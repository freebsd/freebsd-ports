--- src/attack.c.orig	2023-10-11 11:14:13 UTC
+++ src/attack.c
@@ -31,7 +31,7 @@
 #include "utils.h"
 
 #include <arpa/inet.h> /* for inet_ntoa() */
-#include <bsd/unistd.h>
+
 #include <errno.h> /* for errno() */
 #include <fcntl.h>
 #include <glib.h>
@@ -1095,7 +1095,7 @@ apply_hosts_reverse_lookup_preferences (gvm_hosts_t *h
       gvm_hosts_t *excluded;
 
       excluded = gvm_hosts_reverse_lookup_unify_excluded (hosts);
-      g_debug ("reverse_lookup_unify: Skipped %lu host(s).", excluded->count);
+      g_debug ("reverse_lookup_unify: Skipped %zu host(s).", excluded->count);
 
       // Get the amount of hosts which are excluded now for this option,
       // but they are already in the exclude list.
@@ -1111,7 +1111,7 @@ apply_hosts_reverse_lookup_preferences (gvm_hosts_t *h
       gvm_hosts_t *excluded;
 
       excluded = gvm_hosts_reverse_lookup_only_excluded (hosts);
-      g_debug ("reverse_lookup_unify: Skipped %lu host(s).", excluded->count);
+      g_debug ("reverse_lookup_unify: Skipped %zu host(s).", excluded->count);
       // Get the amount of hosts which are excluded now for this option,
       // but they are already in the exclude list.
       // This is to avoid issues with the scan progress calculation, since
@@ -1614,13 +1614,13 @@ stop:
 
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
