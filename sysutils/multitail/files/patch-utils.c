--- utils.c.orig	Thu Jan 20 14:02:33 2005
+++ utils.c	Mon Jan 24 19:28:28 2005
@@ -1,4 +1,9 @@
 #define _LARGEFILE64_SOURCE	/* required for GLIBC to enable stat64 and friends */
+#if defined(__FreeBSD__)
+#define off64_t off_t
+#define stat64 stat
+#define open64 open
+#endif
 #include <curses.h>
 #include <errno.h>
 #include <signal.h>
