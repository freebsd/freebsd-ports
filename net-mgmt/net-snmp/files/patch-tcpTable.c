--- agent/mibgroup/mibII/tcpTable.c.orig	Sat Apr 20 16:30:05 2002
+++ agent/mibgroup/mibII/tcpTable.c	Sat Aug 16 17:38:05 2003
@@ -462,6 +462,40 @@
 TCP_Count_Connections(void)
 {
     int             Established;
+#if (defined(freebsd2) || defined(netbsd2) || defined(openbsd2))
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
     struct inpcb    cb;
     register struct inpcb *next;
 #if !(defined(freebsd2) || defined(netbsd2) || defined(openbsd2))
@@ -525,6 +559,7 @@
         prev = next;
 #endif                          /*  !(defined(freebsd2) || defined(netbsd1) || defined(openbsd2)) */
     }
+#endif
     return (Established);
 }
 #endif                          /* !linux && !hpux11 */
