--- src/attack.c.orig	2025-05-27 12:10:19 UTC
+++ src/attack.c
@@ -31,7 +31,6 @@
 #include "utils.h"
 
 #include <arpa/inet.h> /* for inet_ntoa() */
-#include <bsd/unistd.h>
 #include <errno.h> /* for errno() */
 #include <fcntl.h>
 #include <glib.h>
@@ -1555,21 +1554,21 @@ stop:
   gettimeofday (&now, NULL);
   if (test_alive_hosts_only)
     {
-      g_message ("Vulnerability scan %s finished in %ld seconds: "
+      g_message ("Vulnerability scan %s finished in %lld seconds: "
                  "%d alive hosts of %d",
-                 globals->scan_id, now.tv_sec - then.tv_sec,
+                 globals->scan_id, (long long)now.tv_sec - then.tv_sec,
                  gvm_hosts_count (alive_hosts_list), gvm_hosts_count (hosts));
     }
   else
-    g_message ("Vulnerability scan %s finished in %ld seconds: %d hosts",
-               globals->scan_id, now.tv_sec - then.tv_sec,
+    g_message ("Vulnerability scan %s finished in %lld seconds: %d hosts",
+               globals->scan_id, (long long)now.tv_sec - then.tv_sec,
                gvm_hosts_count (hosts));
 
   if (prefs_get ("report_scripts"))
     {
       char *buff =
-        g_strdup_printf ("},\"scan_time\":  {\"start\": %ld, \"stop\": %ld}}",
-                         then.tv_sec, now.tv_sec);
+        g_strdup_printf ("},\"scan_time\":  {\"start\": %lld, \"stop\": %lld}}",
+                         (long long)then.tv_sec, (long long)now.tv_sec);
       char *path = g_strdup_printf (
         "%s/%s-stats.json", prefs_get ("report_scripts"), globals->scan_id);
 
