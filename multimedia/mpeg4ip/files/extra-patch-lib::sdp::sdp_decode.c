--- lib/sdp/sdp_decode.c.orig	Tue Feb 24 15:54:20 2004
+++ lib/sdp/sdp_decode.c	Mon Nov 22 20:17:07 2004
@@ -378,7 +378,7 @@
   q = NULL;
   while (p != NULL) {
     if (new->adj_time == p->adj_time) {
-      sdp_debug(LOG_NOTICE, "Duplicate time %ld in adj description", p->adj_time);
+      sdp_debug(LOG_NOTICE, "Duplicate time %ld in adj description", (long)p->adj_time);
       free(new);
       return (start);
     }
@@ -1558,6 +1558,7 @@
   int valid;
   time_adj_desc_t *start_aptr, *aptr;
   time_t adj_time;
+  long adj_time_l;
   int32_t offset;
   int possign;
   int err;
@@ -1580,7 +1581,8 @@
       continue;
     }
     // process <adjustment time> - adjust it from NTP to unix time
-    sscanf(sep, "%ld", &adj_time);
+    sscanf(sep, "%ld", &adj_time_l);
+    adj_time = adj_time_l;
 
     // Check for negative sign for offset.
     ADV_SPACE(lptr);
