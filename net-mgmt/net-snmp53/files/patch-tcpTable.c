--- agent/mibgroup/mibII/tcpTable.c.orig	Fri Nov 14 14:49:21 2003
+++ agent/mibgroup/mibII/tcpTable.c	Fri Nov 14 15:14:16 2003
@@ -84,6 +84,8 @@
 #define	TCPTABLE_REMOTEADDRESS	pcb.inp_faddr.s_addr 
 #define	TCPTABLE_REMOTEPORT	pcb.inp_fport
 #define	TCPTABLE_IS_LINKED_LIST
+#undef	INP_NEXT_SYMBOL
+#define	INP_NEXT_SYMBOL		inp_next
 
 #endif                          /* linux */
 #endif                          /* WIN32 */
@@ -695,11 +697,13 @@
         nnew = SNMP_MALLOC_TYPEDEF(netsnmp_inpcb);
         if (!nnew)
             break;
+#if 0
         nnew->state = StateMap[((struct xinpcb *) xig)->xt_tp.t_state];
         if (nnew->state == 5 /* established */ ||
             nnew->state == 8 /*  closeWait  */ )
             tcp_estab++;
-        memcpy(&(nnew->pcb), &(((struct xinpcb *) xig)->xt_inp),
+#endif
+        memcpy(&(nnew->pcb), &(((struct xinpcb *) xig)->xi_inp),
                            sizeof(struct inpcb));
 
 	nnew->inp_next = tcp_head;
