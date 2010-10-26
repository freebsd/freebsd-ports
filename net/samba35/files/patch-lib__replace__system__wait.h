--- ./lib/replace/system/wait.h.orig	2010-04-01 15:26:22.000000000 +0200
+++ ./lib/replace/system/wait.h	2010-04-23 01:08:35.000000000 +0200
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
