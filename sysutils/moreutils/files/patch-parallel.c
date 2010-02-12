--- parallel.c.orig	2010-02-09 12:39:08.000000000 -0800
+++ parallel.c	2010-02-09 22:27:25.000000000 -0800
@@ -76,6 +76,7 @@
 	return;
 }
 
+#ifdef HAVE_WAITID
 int wait_for_child(int options) {
 	id_t id_ignored = 0;
 	siginfo_t infop;
@@ -88,6 +89,18 @@
 		return infop.si_status;
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
 
 int main(int argc, char **argv) {
 	int maxjobs = -1;
