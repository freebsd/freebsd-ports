--- ospfd/ospf_lsa.c.orig	Wed Dec 22 19:16:02 2004
+++ ospfd/ospf_lsa.c	Mon Mar  7 12:24:04 2005
@@ -3665,6 +3665,7 @@
   struct listnode *node;
   struct ospf *ospf = THREAD_ARG (t);
   int i;
+  time_t ct;
   struct list *lsa_to_refresh = list_new ();
 
   if (IS_DEBUG_OSPF (lsa, LSA_REFRESH))
@@ -3672,15 +3673,25 @@
 
   
   i = ospf->lsa_refresh_queue.index;
+
+  if ((ct = time(NULL)) < ospf->lsa_refresher_started) {
+    zlog_debug ("LSA[Refresh]: ospf_lsa_refresh_walker(): HACK: fixing lsa_refresher_started: %d -> %d", ospf->lsa_refresher_started, ct);
+    ospf->lsa_refresher_started = ct;
+  }
   
   ospf->lsa_refresh_queue.index =
     (ospf->lsa_refresh_queue.index +
-     (time (NULL) - ospf->lsa_refresher_started) / OSPF_LSA_REFRESHER_GRANULARITY)
+     (ct - ospf->lsa_refresher_started) / OSPF_LSA_REFRESHER_GRANULARITY)
     % OSPF_LSA_REFRESHER_SLOTS;
 
   if (IS_DEBUG_OSPF (lsa, LSA_REFRESH))
     zlog_debug ("LSA[Refresh]: ospf_lsa_refresh_walker(): next index %d",
 	       ospf->lsa_refresh_queue.index);
+
+  if (ospf->lsa_refresh_queue.index >= OSPF_LSA_REFRESHER_SLOTS) {
+    zlog_debug ("LSA[Refresh]: ospf_lsa_refresh_walker(): HACK: fixing index: %hu -> 0", ospf->lsa_refresh_queue.index);
+    ospf->lsa_refresh_queue.index = 0;
+  }
 
   for (;i != ospf->lsa_refresh_queue.index;
        i = (i + 1) % OSPF_LSA_REFRESHER_SLOTS)
