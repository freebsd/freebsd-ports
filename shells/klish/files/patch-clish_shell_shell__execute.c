--- clish/shell/shell_execute.c.orig	2015-10-06 14:51:41 UTC
+++ clish/shell/shell_execute.c
@@ -19,12 +19,14 @@
 #include <signal.h>
 #include <fcntl.h>
 
+#if !defined(__XSI_VISIBLE)
 /* Empty signal handler to ignore signal but don't use SIG_IGN. */
 static void sigignore(int signo)
 {
 	signo = signo; /* Happy compiler */
 	return;
 }
+#endif
 
 /*-------------------------------------------------------- */
 static int clish_shell_lock(const char *lock_path)
