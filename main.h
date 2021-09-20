#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <errno.h>
#include <sys/ioctl.h>

#define CTRL_KEY(k) ((k) & 0x1f)

/* data */
struct editorConfig {
    int scrRows;
    int scrCols;
    struct termios orig_termios;
};

struct editorConfig editConf;

void disableRawMode();
void enableRawMode();
void die(const char *s);
char editorReadKey();
void editorProcessKeyPress();
void editorRefreshScreen();
void editorDrawRows();
int getWindowSize(int *, int *);
void initEditor();
