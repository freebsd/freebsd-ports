--- lib/sdp/sdp_decode.c.orig	Thu Sep 30 01:32:23 2004
+++ lib/sdp/sdp_decode.c	Thu Sep 30 01:32:45 2004
@@ -378,7 +378,7 @@
   q = NULL;
   while (p != NULL) {
     if (new->adj_time == p->adj_time) {
-      sdp_debug(LOG_NOTICE, "Duplicate time %ld in adj description", p->adj_time);
+      sdp_debug(LOG_NOTICE, "Duplicate time %d in adj description", p->adj_time);
       free(new);
       return (start);
     }
@@ -1580,7 +1580,7 @@
       continue;
     }
     // process <adjustment time> - adjust it from NTP to unix time
-    sscanf(sep, "%ld", &adj_time);
+    sscanf(sep, "%d", &adj_time);
 
     // Check for negative sign for offset.
     ADV_SPACE(lptr);
