--- agent/mibgroup/mibII/udpTable.c.orig	2018-07-16 14:33:40 UTC
+++ agent/mibgroup/mibII/udpTable.c
@@ -97,7 +97,11 @@ struct netsnmp_udpEntry_s {
 #if defined(freebsd4) || defined(darwin) || defined(osf5)
 typedef struct netsnmp_inpcb_s netsnmp_inpcb;
 struct netsnmp_inpcb_s {
+#if __FreeBSD_version >= 1200026
+    struct xinpcb   pcb;
+#else
     struct inpcb    pcb;
+#endif
     int             state;
     netsnmp_inpcb  *inp_next;
 };
@@ -708,7 +712,11 @@ udpTable_load(netsnmp_cache *cache, void *vmagic)
         nnew = SNMP_MALLOC_TYPEDEF(UDPTABLE_ENTRY_TYPE);
         if (!nnew)
             break;
+#if __FreeBSD_version >= 1200026
+        memcpy(&nnew->pcb, xig, sizeof(struct xinpcb));
+#else
         memcpy(&nnew->pcb, &((struct xinpcb *) xig)->xi_inp, sizeof(struct inpcb));
+#endif
 	nnew->inp_next = udp_head;
 	udp_head   = nnew;
 #if defined(dragonfly)
