--- mt.c.orig	Mon Apr 21 12:39:51 2003
+++ mt.c	Tue Apr 22 00:21:15 2003
@@ -6,9 +6,6 @@
 #include <fcntl.h>
 #include <limits.h>
 #include <ncurses.h>
-#ifdef __FreeBSD__
-#include <libutil.h>
-#endif
 #ifdef linux
 #include <pty.h>
 #endif
@@ -25,6 +22,9 @@
 #include <sys/time.h>
 #include <sys/types.h>
 #include <unistd.h>
+#ifdef __FreeBSD__
+#include <libutil.h>
+#endif
 
 /* #define KEYB_DEBUG */
 
