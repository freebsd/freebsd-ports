--- ./lib/replace/system/wait.h.orig	2010-02-10 02:17:10.000000000 +0000
+++ ./lib/replace/system/wait.h	2010-02-10 02:19:48.000000000 +0000
@@ -32,6 +32,18 @@
 
 #include <signal.h>
 
+#ifndef SIGRTMIN
+#	ifdef NSIG
+#		define SIGRTMIN (NSIG+1)
+#	else
+#		define SIGRTMIN 33
+#	endif
+#endif
+
+#ifndef SIGRTMAX
+#define SIGRTMAX (SIGRTMIN+64)
+#endif
+
 #ifndef SIGCLD
 #define SIGCLD SIGCHLD
 #endif
