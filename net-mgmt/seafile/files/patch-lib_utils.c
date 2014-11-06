--- lib/utils.c.orig	2014-06-05 02:25:50.000000000 -0400
+++ lib/utils.c	2014-07-30 22:56:37.000000000 -0400
@@ -1756,14 +1756,19 @@
 
 #endif  /* ifdef WIN32 */
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
 /* read the link of /proc/123/exe and compare with `process_name' */
 static int
 find_process_in_dirent(struct dirent *dir, const char *process_name)
 {
     char path[512];
     /* fisrst construct a path like /proc/123/exe */
+#ifdef __linux__
     if (sprintf (path, "/proc/%s/exe", dir->d_name) < 0) {
+#endif
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+    if (sprintf (path, "/proc/%s/file", dir->d_name) < 0) {
+#endif
         return -1;
     }
 
