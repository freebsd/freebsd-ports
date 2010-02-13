--- agent/mibgroup/mibII/tcpTable.c.orig	Fri Jul 18 21:10:09 2003
+++ agent/mibgroup/mibII/tcpTable.c	Fri Jul 18 21:10:12 2003
@@ -435,11 +435,42 @@
 int TCP_Count_Connections (void)
 {
 	int Established;
+#if !(defined(freebsd2) || defined(netbsd1) || defined(openbsd2))
+	int mib[4], len;
+	char *p;
+	struct tcpcb *tpcb;
+	struct xtcpcb *tp;
+	struct xinpgen *next;
+
+	mib[0]=CTL_NET;
+	mib[1]=PF_INET;
+	mib[2]=IPPROTO_TCP;
+	mib[3]=TCPCTL_PCBLIST;
+
+	if (sysctl(mib, 4, NULL, &len, NULL, 0) != 0) {
+		snmp_log_perror("TCP_Count_Connections - sysctl");
+		return 0;
+	}
+	if ((p=(char *)malloc(len)) == NULL) {
+		snmp_log_perror("TCP_Count_Connections - malloc");
+		return 0;
+	}
+	if (sysctl(mib, 4, p, &len, NULL, 0) != 0) {
+		snmp_log_perror("TCP_Count_Connections - sysctl");
+		free(p);
+		return 0;
+	}
+	Established=0;
+	next=(struct xinpgen *)p;
+	for (next=(struct xinpgen *)((char *)next + next->xig_len); next->xig_len > sizeof(struct xinpgen); next=(struct xinpgen *)((char *)next + next->xig_len)) {
+		tp=(struct xtcpcb *)next;
+		if (tp->xt_tp.t_state == TCPS_ESTABLISHED || tp->xt_tp.t_state == TCPS_CLOSE_WAIT)
+			Established++;
+	}
+	free(p);
+#else
 	struct inpcb cb;
 	register struct inpcb *next;
-#if !(defined(freebsd2) || defined(netbsd2) || defined(openbsd2))
-	register struct inpcb *prev;
-#endif
 	struct inpcb inpcb;
 	struct tcpcb tcpcb;
 
@@ -450,17 +481,10 @@
 
 	auto_nlist(TCP_SYMBOL, (char *)&cb, sizeof(struct inpcb));
 	inpcb = cb;
-#if !(defined(freebsd2) || defined(netbsd1) || defined(openbsd2))
-	prev = (struct inpcb *) auto_nlist_value(TCP_SYMBOL);
-#endif /*  !(defined(freebsd2) || defined(netbsd1) || defined(openbsd2)) */
 	/*
 	 *	Scan the control blocks
 	 */
-#if defined(freebsd2) || defined(netbsd1) || defined(openbsd2)
 	while ((inpcb.INP_NEXT_SYMBOL != NULL) && (inpcb.INP_NEXT_SYMBOL != (struct inpcb *) auto_nlist_value(TCP_SYMBOL)))
-#else /*  defined(freebsd2) || defined(netbsd1) || defined(openbsd2) */
-	while (inpcb.INP_NEXT_SYMBOL != (struct inpcb *) auto_nlist_value(TCP_SYMBOL))
-#endif /*  defined(freebsd2) || defined(netbsd1) */
 	{
 		next = inpcb.INP_NEXT_SYMBOL;
 
@@ -468,16 +492,7 @@
 		    snmp_log_perror("TCP_Count_Connections - inpcb");
 		    break;
 		}
-#if !(defined(freebsd2) || defined(netbsd1) || defined(openbsd2))
-		if (inpcb.INP_PREV_SYMBOL != prev) {	    /* ??? */
-			sleep(1);
-			goto Again;
-		}
-#endif /*  !(defined(freebsd2) || defined(netbsd1) || defined(openbsd2)) */
 		if (inet_lnaof(inpcb.inp_laddr) == INADDR_ANY) {
-#if !(defined(freebsd2) || defined(netbsd1) || defined(openbsd2))
-			prev = next;
-#endif /*  !(defined(freebsd2) || defined(netbsd1) || defined(openbsd2)) */
 			continue;
 		}
 		if(klookup((unsigned long)inpcb.inp_ppcb, (char *)&tcpcb, sizeof (tcpcb)) == 0) {
@@ -488,10 +503,8 @@
 		if ((tcpcb.t_state == TCPS_ESTABLISHED) ||
 		    (tcpcb.t_state == TCPS_CLOSE_WAIT))
 		    Established++;
-#if !(defined(freebsd2) || defined(netbsd1) || defined(openbsd2))
-		prev = next;
-#endif /*  !(defined(freebsd2) || defined(netbsd1) || defined(openbsd2)) */
 	}
+#endif
 	return(Established);
 }
 #endif	/* !linux && !hpux11 */

