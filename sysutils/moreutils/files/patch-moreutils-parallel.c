--- moreutils-parallel.c.orig	2015-01-19 18:03:51 UTC
+++ moreutils-parallel.c
@@ -112,6 +113,7 @@ void exec_child(char **command, char **a
 	return;
 }
 
+#ifdef HAVE_WAITID
 int wait_for_child(int options) {
 	id_t id_ignored = 0;
 	siginfo_t infop;
@@ -126,6 +128,18 @@ int wait_for_child(int options) {
 	}
 	return 1;
 }
+#else
+int wait_for_child(int options) {
+   int status;
+
+   if(waitpid(-1, &status, options) == -1)
+       return -1; /* nothing to wait for */
+   if(WIFEXITED(status))
+           return WEXITSTATUS(status);
+   return 1;
+}
+#endif
+
 
 static int pipe_child(int fd, int orig_fd)
 {
