--- mupdisp/mupdisp.h.orig	Sun Oct  5 17:53:43 2003
+++ mupdisp/mupdisp.h	Sun Oct  5 17:54:05 2003
@@ -12,8 +12,7 @@
 #include <signal.h>
 #include <string.h>
 #include <stdlib.h>
-#include <malloc.h>
-#if !defined(linux) && !defined(__EMX__)
+#if !defined(linux) && !defined(__EMX__) && !defined(__FreeBSD__)
 /* undef SIGCHLD to avoid conflict with Xos.h */
 #undef SIGCHLD
 #endif
@@ -146,6 +145,3 @@
 extern void init P((void));
 extern void do_cmd P((int c));
 
-extern char *getenv();
-extern long ftell();
-extern long lseek();
