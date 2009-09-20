--- parallel.c.orig	2009-07-25 00:59:37.000000000 -0700
+++ parallel.c	2009-09-19 15:41:07.000000000 -0700
@@ -64,6 +64,7 @@
 	return;
 }
 
+#ifdef HAVE_WAITID
 int wait_for_child(int options) {
 	id_t id_ignored = 0;
 	siginfo_t infop;
@@ -76,6 +77,17 @@
 		return infop.si_status;
 	return 1;
 }
+#else
+int wait_for_child(int options) {
+	int status;
+
+	if(waitpid(-1, &status, options) == -1)
+		return -1; /* nothing to wait for */
+	if(WIFEXITED(status))
+			return WEXITSTATUS(status);
+	return 1;
+}
+#endif
 
 int main(int argc, char **argv) {
 	int maxjobs = -1;
