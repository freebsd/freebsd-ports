--- agent/mibgroup/mibII/tcpTable.c.orig	Tue Mar 16 08:27:45 2004
+++ agent/mibgroup/mibII/tcpTable.c	Wed Apr 14 09:40:00 2004
@@ -95,6 +95,8 @@
 #define	TCPTABLE_REMOTEADDRESS	pcb.inp_faddr.s_addr 
 #define	TCPTABLE_REMOTEPORT	pcb.inp_fport
 #define	TCPTABLE_IS_LINKED_LIST
+#undef	INP_NEXT_SYMBOL
+#define	INP_NEXT_SYMBOL		inp_next
 
 #endif                          /* linux */
 #endif                          /* WIN32 */
@@ -275,6 +277,9 @@
 
 int
 TCP_Count_Connections( void ) {
+#if (defined(CAN_USE_SYSCTL) && defined(TCPCTL_PCBLIST))
+    tcpTable_load(NULL, NULL);
+#endif
     return tcp_estab;
 }
 
@@ -691,6 +696,7 @@
     struct xinpgen *xig = NULL;
     netsnmp_inpcb  *nnew;
     int      StateMap[] = { 1, 2, 3, 4, 5, 8, 6, 10, 9, 7, 11 };
+    struct tcpcb *tp = NULL;
 
     tcpTable_free(NULL, NULL);
 
@@ -717,12 +723,13 @@
         nnew = SNMP_MALLOC_TYPEDEF(netsnmp_inpcb);
         if (!nnew)
             break;
-        nnew->state = StateMap[((struct xinpcb *) xig)->xt_tp.t_state];
+	tp = &((struct xtcpcb *)xig)->xt_tp;
+        nnew->state = StateMap[tp->t_state];
         if (nnew->state == 5 /* established */ ||
             nnew->state == 8 /*  closeWait  */ )
             tcp_estab++;
-        memcpy(&(nnew->pcb), &(((struct xinpcb *) xig)->xt_inp),
-                           sizeof(struct inpcb));
+        memcpy(&(nnew->pcb), &(((struct xtcpcb *) xig)->xt_tp),
+                           sizeof(struct tcpcb));
 
 	nnew->inp_next = tcp_head;
 	tcp_head   = nnew;
