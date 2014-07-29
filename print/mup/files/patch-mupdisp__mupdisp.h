--- mupdisp/mupdisp.h.orig	Sun Jan 15 10:39:51 2006
+++ mupdisp/mupdisp.h	Mon Feb 20 17:31:40 2006
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
@@ -146,10 +145,4 @@
 extern void init P((void));
 extern void do_cmd P((int c));
 
-extern char *getenv();
-extern long ftell();
-#ifdef __STDC__
 #include <unistd.h>
-#else
-extern long lseek();
-#endif
