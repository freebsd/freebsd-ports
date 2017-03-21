--- agent/mibgroup/mibII/tcpTable.c.orig	2017-03-15 17:46:37.000000000 +0000
+++ agent/mibgroup/mibII/tcpTable.c	2017-03-15 17:46:37.000000000 +0000
@@ -96,7 +96,11 @@
 
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
@@ -301,8 +305,10 @@
 #ifndef NETSNMP_FEATURE_REMOVE_TCP_COUNT_CONNECTIONS
 int
 TCP_Count_Connections( void ) {
+#if (defined(CAN_USE_SYSCTL) && defined(TCPCTL_PCBLIST))
     tcpTable_load(NULL, NULL);
     return tcp_estab;
+#endif
 }
 #endif /* NETSNMP_FEATURE_REMOVE_TCP_COUNT_CONNECTIONS */
 
@@ -923,12 +929,20 @@
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
 
 	if (nnew->pcb.inp_vflag & INP_IPV6)
 	    free(nnew);
