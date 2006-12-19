--- config.h.orig	Wed Nov 24 16:36:07 1993
+++ config.h	Mon Dec 18 11:46:21 2006
@@ -73,7 +73,7 @@
 #ifdef SYSV
 #define RESET_PROGRAM "tput clear"
 #else
-#ifdef __BSD_4_4__
+#if defined(__BSD_4_4__) || defined(__FreeBSD__)
 #define RESET_PROGRAM "/usr/bin/reset"
 #else
 #define RESET_PROGRAM "/usr/ucb/reset"
@@ -155,7 +155,11 @@
 #ifdef NeXT
 #define sigtype void
 #else
+#ifdef __FreeBSD__
+#define sigtype void
+#else
 #define sigtype int
+#endif
 #endif
 #endif
 
