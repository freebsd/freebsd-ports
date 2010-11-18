--- ./parallel.c.orig	2010-07-06 12:06:47.000000000 -0700
+++ ./parallel.c	2010-11-17 15:49:57.000000000 -0800
@@ -87,6 +87,7 @@
 	return;
 }
 
+#ifdef HAVE_WAITID
 int wait_for_child(int options) {
 	id_t id_ignored = 0;
 	siginfo_t infop;
@@ -101,6 +102,18 @@
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
 
 int main(int argc, char **argv) {
 	int maxjobs = -1;
