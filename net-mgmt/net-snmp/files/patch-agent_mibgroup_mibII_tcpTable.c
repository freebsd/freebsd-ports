--- agent/mibgroup/mibII/tcpTable.c.orig	2018-07-16 14:33:40 UTC
+++ agent/mibgroup/mibII/tcpTable.c
@@ -120,7 +120,11 @@ struct netsnmp_tcpConnEntry_s {
 
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
@@ -330,8 +334,10 @@ tcpTable_handler(netsnmp_mib_handler          *handler
 #ifndef NETSNMP_FEATURE_REMOVE_TCP_COUNT_CONNECTIONS
 int
 TCP_Count_Connections( void ) {
+#if (defined(CAN_USE_SYSCTL) && defined(TCPCTL_PCBLIST))
     tcpTable_load(NULL, NULL);
     return tcp_estab;
+#endif
 }
 #endif /* NETSNMP_FEATURE_REMOVE_TCP_COUNT_CONNECTIONS */
 
@@ -988,12 +994,20 @@ tcpTable_load(netsnmp_cache *cache, void *vmagic)
         nnew = SNMP_MALLOC_TYPEDEF(netsnmp_inpcb);
         if (!nnew)
             break;
+#if __FreeBSD_version >= 1200026
+        nnew->state = StateMap[((NS_ELEM *) xig)->t_state];
+#else
         nnew->state = StateMap[((NS_ELEM *) xig)->xt_tp.t_state];
+#endif
         if (nnew->state == 5 /* established */ ||
             nnew->state == 8 /*  closeWait  */ )
             tcp_estab++;
         memcpy(&(nnew->pcb), &(((NS_ELEM *) xig)->xt_inp),
+#if __FreeBSD_version >= 1200026
+                           sizeof(struct xinpcb));
+#else
                            sizeof(struct inpcb));
+#endif
 
 #ifdef INP_ISIPV6
 	if (INP_ISIPV6(&nnew->pcb))
