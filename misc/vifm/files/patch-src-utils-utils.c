--- src/utils/utils.c.orig	2013-04-02 18:56:49.000000000 +0300
+++ src/utils/utils.c	2013-04-02 18:21:24.000000000 +0300
@@ -34,7 +34,7 @@
 #include <sys/wait.h> /* waitpid() */
 #endif
 
-#if !defined(_WIN32) && !defined(__APPLE__)
+#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <mntent.h> /* getmntent() */
 #endif
 
@@ -267,7 +267,7 @@
 int
 is_on_slow_fs(const char *full_path)
 {
-#if defined(_WIN32) || defined(__APPLE__)
+#if defined(_WIN32) || defined(__APPLE__) || defined(__FreeBSD__)
 	return 0;
 #else
 	FILE *f;
