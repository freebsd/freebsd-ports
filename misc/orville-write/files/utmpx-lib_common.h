--- lib_common.h.orig	2010-02-02 22:40:13.646402561 -0800
+++ lib_common.h	2010-02-02 22:40:30.475105092 -0800
@@ -6,7 +6,7 @@
 #include "getutent.h"
 
 int init_wstream(int mode);
-struct utmp *find_utmp(char *tty);
+struct utmpx *find_utmp(char *tty);
 void find_wrttmp(char *tty, time_t time,struct wrttmp *wbuf, long *pos);
 void dflt_wrttmp(struct wrttmp *wbuf, char *tty, time_t time);
 char *leafname(char *fullpath);
