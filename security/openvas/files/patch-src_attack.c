--- src/attack.c.orig	2023-01-03 21:45:22 UTC
+++ src/attack.c
@@ -1493,13 +1493,13 @@ stop:
 
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
