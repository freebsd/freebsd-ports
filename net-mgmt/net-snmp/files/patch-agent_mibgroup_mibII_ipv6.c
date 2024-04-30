--- agent/mibgroup/mibII/ipv6.c.orig	2023-08-15 20:32:01 UTC
+++ agent/mibgroup/mibII/ipv6.c
@@ -5,9 +5,6 @@
 
 #include <net-snmp/net-snmp-config.h>
 #include <net-snmp/net-snmp-features.h>
-/* For FreeBSD */
-#define _WANT_INPCB 1
-#define _WANT_TCPCB 1
 #include <sys/types.h>
 #include <sys/socket.h>
 #ifdef HAVE_SYS_IOCTL_H
@@ -1513,8 +1510,10 @@ var_udp6(register struct variable * vp,
     int             result;
     int             i, j;
     caddr_t         p;
-#if defined(openbsd4) || defined(freebsd3)
+#if defined(openbsd4)
     static struct inpcb in6pcb, savpcb;
+#elif defined(freebsd3)
+    static struct xinpcb in6pcb, savpcb;
 #else
     static struct in6pcb in6pcb, savpcb;
 #endif
@@ -1614,8 +1613,7 @@ var_udp6(register struct variable * vp,
         DEBUGMSGTL(("mibII/ipv6", "looping: p=%p\n", p));
 
 #if defined(freebsd3)
-	/* To do: fill in in6pcb properly. */
-	memset(&in6pcb, 0, sizeof(in6pcb));
+	in6pcb = *(struct xinpcb *) xig;
 #elif defined(darwin)
 	in6pcb = ((struct xinpcb *) xig)->xi_inp;
 #else
@@ -2108,12 +2106,18 @@ var_tcp6(register struct variable * vp,
     int             result;
     int             i, j;
     caddr_t         p;
-#if defined(openbsd4) || defined(freebsd3)
+#if defined(openbsd4)
     static struct inpcb in6pcb, savpcb;
+#elif defined(freebsd3)
+    static struct xinpcb in6pcb;
+    static int      savstate;
 #else
     static struct in6pcb in6pcb, savpcb;
 #endif
+#if !defined(freebsd3)
     struct tcpcb    tcpcb;
+#endif
+    int             state;
     int             found, savnameLen;
 #if defined(__NetBSD__) && __NetBSD_Version__ >= 106250000 || defined(openbsd4)	/*1.6Y*/
     struct inpcbtable tcbtable;
@@ -2208,8 +2212,7 @@ var_tcp6(register struct variable * vp,
         DEBUGMSGTL(("mibII/ipv6", "looping: p=%p\n", p));
 
 #if defined(freebsd3)
-	/* To do: fill in in6pcb properly. */
-	memset(&in6pcb, 0, sizeof(in6pcb));
+	in6pcb = ((struct xtcpcb *) xig)->xt_inp;
 #elif defined(dragonfly)
 	in6pcb = xtp->xt_inp;
 #elif defined(darwin)
@@ -2294,7 +2297,11 @@ var_tcp6(register struct variable * vp,
 #endif
         result = snmp_oid_compare(name, *length, newname, j);
         if (exact && (result == 0)) {
+#if defined(freebsd3)
+                savstate = ((struct xtcpcb *) xig)->t_state;
+#else
                 memcpy(&savpcb, &in6pcb, sizeof(savpcb));
+#endif
                 savnameLen = j;
                 memcpy(savname, newname, j * sizeof(oid));
                 found++;
@@ -2305,7 +2312,11 @@ var_tcp6(register struct variable * vp,
              */
             if ((savnameLen == 0) ||
               (snmp_oid_compare(savname, savnameLen, newname, j) > 0)) {
+#if defined(freebsd3)
+                savstate = ((struct xtcpcb *) xig)->t_state;
+#else
                 memcpy(&savpcb, &in6pcb, sizeof(savpcb));
+#endif
                 savnameLen = j;
                 memcpy(savname, newname, j * sizeof(oid));
                 found++;
@@ -2344,19 +2355,27 @@ var_tcp6(register struct variable * vp,
         return NULL;
     *length = savnameLen;
     memcpy((char *) name, (char *) savname, *length * sizeof(oid));
+#if defined(freebsd3)
+    state = savstate;
+#elif defined(__NetBSD__) && __NetBSD_Version__ >= 999010400
     memcpy(&in6pcb, &savpcb, sizeof(savpcb));
-#if defined(__NetBSD__) && __NetBSD_Version__ >= 999010400
     if (!NETSNMP_KLOOKUP(in6pcb.in6p_pcb.inp_ppcb, (char *) &tcpcb, sizeof(tcpcb))) {
         DEBUGMSGTL(("mibII/ipv6", "klookup fail for tcb6.tcpcb at %p\n",
                     in6pcb.in6p_pcb.inp_ppcb));
+	found = 0;
+	return NULL;
+    }
+    state = (int)tcpcb.t_state;
 #else
+    memcpy(&in6pcb, &savpcb, sizeof(savpcb));
     if (!NETSNMP_KLOOKUP(in6pcb.inp_ppcb, (char *) &tcpcb, sizeof(tcpcb))) {
 	DEBUGMSGTL(("mibII/ipv6", "klookup fail for tcb6.tcpcb at %p\n",
 		    in6pcb.inp_ppcb));
-#endif
 	found = 0;
 	return NULL;
     }
+    state = (int)tcpcb.t_state;
+#endif
     *write_method = 0;
     *var_len = sizeof(long);    /* default to 'long' results */
 
@@ -2368,7 +2387,7 @@ var_tcp6(register struct variable * vp,
     DEBUGMSGTL(("mibII/ipv6", "magic=%d\n", vp->magic));
     switch (vp->magic) {
     case IPV6TCPCONNSTATE:
-        long_return = mapTcpState((int)tcpcb.t_state);
+        long_return = mapTcpState(state);
         return (u_char *) & long_return;
     default:
         break;
