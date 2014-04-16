--- ./ospfd/ospf_lsa.c.orig	2005-05-26 11:40:19.000000000 -0500
+++ ./ospfd/ospf_lsa.c	2014-04-09 15:16:46.751621976 -0500
@@ -3247,6 +3247,7 @@
   listnode node;
   struct ospf *ospf = THREAD_ARG (t);
   int i;
+  time_t ct;
   list lsa_to_refresh = list_new ();
 
   if (IS_DEBUG_OSPF (lsa, LSA_REFRESH))
@@ -3254,16 +3255,26 @@
 
   
   i = ospf->lsa_refresh_queue.index;
+
+  if ((ct = time(NULL)) < ospf->lsa_refresher_started) {
+    zlog_info ("LSA[Refresh]: ospf_lsa_refresh_walker(): HACK: fixing lsa_refresher_started: %d -> %d", ospf->lsa_refresher_started, ct);
+    ospf->lsa_refresher_started = ct;
+  }
   
   ospf->lsa_refresh_queue.index =
     (ospf->lsa_refresh_queue.index +
-     (time (NULL) - ospf->lsa_refresher_started) / OSPF_LSA_REFRESHER_GRANULARITY)
+     (ct - ospf->lsa_refresher_started) / OSPF_LSA_REFRESHER_GRANULARITY)
     % OSPF_LSA_REFRESHER_SLOTS;
 
   if (IS_DEBUG_OSPF (lsa, LSA_REFRESH))
     zlog_info ("LSA[Refresh]: ospf_lsa_refresh_walker(): next index %d",
 	       ospf->lsa_refresh_queue.index);
 
+  if (ospf->lsa_refresh_queue.index >= OSPF_LSA_REFRESHER_SLOTS) {
+    zlog_info ("LSA[Refresh]: ospf_lsa_refresh_walker(): HACK: fixing index: %hu -> 0", ospf->lsa_refresh_queue.index);
+    ospf->lsa_refresh_queue.index = 0;
+  }
+
   for (;i != ospf->lsa_refresh_queue.index;
        i = (i + 1) % OSPF_LSA_REFRESHER_SLOTS)
     {
