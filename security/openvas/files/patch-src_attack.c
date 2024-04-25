--- src/attack.c	2024-04-24 02:59:35.930683000 -0500
+++ src/attack.c	2024-04-24 03:02:33.794371000 -0500
@@ -31,7 +31,6 @@
 #include "utils.h"
 
 #include <arpa/inet.h> /* for inet_ntoa() */
-#include <bsd/unistd.h>
 #include <errno.h> /* for errno() */
 #include <fcntl.h>
 #include <glib.h>
@@ -1541,13 +1540,13 @@
 
   gettimeofday (&now, NULL);
   if (test_alive_hosts_only)
-    g_message ("Vulnerability scan %s finished in %ld seconds: "
+    g_message ("Vulnerability scan %s finished in %lld seconds: "
                "%d alive hosts of %d",
-               globals->scan_id, now.tv_sec - then.tv_sec,
+               globals->scan_id, (long long)now.tv_sec - then.tv_sec,
                gvm_hosts_count (alive_hosts_list), gvm_hosts_count (hosts));
   else
-    g_message ("Vulnerability scan %s finished in %ld seconds: %d hosts",
-               globals->scan_id, now.tv_sec - then.tv_sec,
+    g_message ("Vulnerability scan %s finished in %lld seconds: %d hosts",
+               globals->scan_id, (long long)now.tv_sec - then.tv_sec,
                gvm_hosts_count (hosts));
 
   gvm_hosts_free (hosts);
