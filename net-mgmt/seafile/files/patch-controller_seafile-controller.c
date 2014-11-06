--- controller/seafile-controller.c.orig	2014-08-05 01:28:35.000000000 -0400
+++ controller/seafile-controller.c	2014-08-30 09:11:34.868400091 -0400
@@ -18,6 +18,10 @@
 #include "log.h"
 #include "seafile-controller.h"
 
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#include <sys/sysctl.h>
+#endif
+
 #define CHECK_PROCESS_INTERVAL 10        /* every 10 seconds */
 
 SeafileController *ctl;
@@ -273,7 +277,11 @@
 init_seafile_path ()
 {
     GError *error = NULL;
+#if defined(__linux__)
     char *executable = g_file_read_link ("/proc/self/exe", &error);
+#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+    char *executable = g_file_read_link ("/proc/curproc/file", &error);
+#endif
     char *tmp = NULL;
     if (error != NULL) {
         seaf_warning ("failed to readlink: %s\n", error->message);
