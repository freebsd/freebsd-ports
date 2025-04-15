--- src/attack.c	2025-03-03 04:49:55.000000000 -0800
+++ src/attack.c	2025-04-14 20:09:40.968033000 -0700
@@ -31,7 +31,6 @@
 #include "utils.h"
 
 #include <arpa/inet.h> /* for inet_ntoa() */
-#include <bsd/unistd.h>
 #include <errno.h> /* for errno() */
 #include <fcntl.h>
 #include <glib.h>
@@ -1555,14 +1554,14 @@
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
