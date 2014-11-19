--- lib/utils.c.orig	2014-06-10 04:41:45.000000000 -0400
+++ lib/utils.c	2014-07-28 14:32:24.000000000 -0400
@@ -41,6 +41,10 @@
 #include <glib/gstdio.h>
 #include <searpc-utils.h>
 
+#ifdef __FreeBSD__
+#include <netinet/in.h>
+#endif
+
 extern int inet_pton(int af, const char *src, void *dst);
 
 
@@ -1463,14 +1467,19 @@
 }
 #endif  /* ifdef WIN32 */
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
 /* read the link of /proc/123/exe and compare with `process_name' */
 static int
 find_process_in_dirent(struct dirent *dir, const char *process_name)
 {
     char path[512];
     /* fisrst construct a path like /proc/123/exe */
+#if defined(__linux__)
     if (sprintf (path, "/proc/%s/exe", dir->d_name) < 0) {
+#endif
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+    if (sprintf (path, "/proc/%s/file", dir->d_name) < 0) {
+#endif
         return -1;
     }
 
@@ -1528,6 +1537,22 @@
 }
 #endif
 
+/*
+ * Finally, we should not enforce to use /proc
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+gboolean process_is_running (const char *process_name)
+{
+    //TODO
+    return FALSE;
+}
+
+int count_process(const char *process_name)
+{
+    return 0;
+}
+#endif
+*/
+
 char*
 ccnet_object_type_from_id (const char *object_id)
 {
