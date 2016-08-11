--- config.h.orig	1993-11-24 15:36:07 UTC
+++ config.h
@@ -73,7 +73,7 @@ WITHOUT ANY EXPRESS OR IMPLIED WARRANTIE
 #ifdef SYSV
 #define RESET_PROGRAM "tput clear"
 #else
-#ifdef __BSD_4_4__
+#if defined(__BSD_4_4__) || defined(__FreeBSD__)
 #define RESET_PROGRAM "/usr/bin/reset"
 #else
 #define RESET_PROGRAM "/usr/ucb/reset"
@@ -155,9 +155,13 @@ WITHOUT ANY EXPRESS OR IMPLIED WARRANTIE
 #ifdef NeXT
 #define sigtype void
 #else
+#ifdef __FreeBSD__
+#define sigtype void
+#else
 #define sigtype int
 #endif
 #endif
+#endif
 
 #ifdef MSDOS
 #define PATH_SEPARATOR ';'
