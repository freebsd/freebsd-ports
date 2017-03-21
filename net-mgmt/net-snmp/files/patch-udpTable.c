--- agent/mibgroup/mibII/udpTable.c.orig	2017-03-15 18:08:43.000000000 +0000
+++ agent/mibgroup/mibII/udpTable.c	2017-03-15 18:08:43.000000000 +0000
@@ -71,7 +71,11 @@
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
@@ -670,7 +674,11 @@
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
