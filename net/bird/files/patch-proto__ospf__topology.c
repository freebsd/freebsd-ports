--- proto/ospf/topology.c	2015-04-22 14:41:44.000000000 +0000
+++ proto/ospf/topology.c	2016-03-24 13:36:04.000000000 +0000
@@ -79,8 +79,12 @@
    * then we have en->mode from the postponed LSA origination.
    */
 
-  OSPF_TRACE(D_EVENTS, "Installing LSA: Type: %04x, Id: %R, Rt: %R, Seq: %08x, Age: %u",
-	     en->lsa_type, en->lsa.id, en->lsa.rt, en->lsa.sn, en->lsa.age);
+  if (en->lsa.rt == p->router_id || (p->p.debug & D_EVENTS) ||
+      OSPF_FORCE_DEBUG)
+  {
+    log(L_INFO "Installing LSA: Type: %04x, Id: %R, Rt: %R, Seq: %08x, Age: %u",
+	en->lsa_type, en->lsa.id, en->lsa.rt, en->lsa.sn, en->lsa.age);
+  }
 
   if (change)
     ospf_schedule_rtcalc(p);
@@ -281,6 +285,14 @@
   if (!en->nf || !en->lsa_body) 
     en->nf = lsa->nf;
 
+  if (en->lsa_body && (en->lsa.age == LSA_MAXAGE))
+  {
+    /* en could be an unexpected self-originated lsa in which case nf is NULL */
+    log(L_INFO "%s: Found flushing LSA while originating %I/%d with fib: %p",
+        p->p.name, lsa->nf->fn.prefix, lsa->nf->fn.pxlen, en->nf);
+    en->nf = lsa->nf;
+  }
+
   if (en->nf != lsa->nf)
   {
     log(L_ERR "%s: LSA ID collision for %I/%d",
