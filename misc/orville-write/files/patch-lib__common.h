--- lib_common.h.orig	2000-02-01 05:49:10 UTC
+++ lib_common.h
@@ -6,7 +6,7 @@
 #include "getutent.h"
 
 int init_wstream(int mode);
-struct utmp *find_utmp(char *tty);
+struct utmpx *find_utmp(char *tty);
 void find_wrttmp(char *tty, time_t time,struct wrttmp *wbuf, long *pos);
 void dflt_wrttmp(struct wrttmp *wbuf, char *tty, time_t time);
 char *leafname(char *fullpath);
@@ -19,7 +19,7 @@ extern int f_disconnect, f_exceptions, f_helpers, f_lo
 extern char *progname;
 extern char mydevname[];
 extern int wstream;
-struct wrthdr wt_head;
+extern struct wrthdr wt_head;
 
 #ifdef TTYPERMS
 int saveperms(void);
