--- proto/ospf/lsupd.c	2015-04-22 14:41:44.000000000 +0000
+++ proto/ospf/lsupd.c	2016-03-22 13:09:59.000000000 +0000
@@ -593,7 +593,7 @@
       if ((lsa.rt == p->router_id) ||
 	  (ospf_is_v2(p) && (lsa_type == LSA_T_NET) && ospf_addr_is_local(p, ifa->oa, ipa_from_u32(lsa.id))))
       {
-	OSPF_TRACE(D_EVENTS, "Received unexpected self-originated LSA");
+	log(L_INFO "Received unexpected self-originated LSA");
 	ospf_advance_lsa(p, en, &lsa, lsa_type, lsa_domain, body);
 	continue;
       }
