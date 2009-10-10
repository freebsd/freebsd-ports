--- Source/plugin-threads.cpp.orig	2008-06-12 23:38:37.000000000 -0400
+++ Source/plugin-threads.cpp	2009-10-01 05:04:31.000000000 -0400
@@ -14,8 +14,11 @@
 
 static void sig_child(int signo)
 {
-    // Not used, so commented out
-    // wait(NULL);
+	pid_t pid;
+	int status;
+
+	pid = wait(&status);
+	return;
 }
