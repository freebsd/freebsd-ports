--- agent/mibgroup/mibII/ipv6.c.orig	2007-05-25 07:01:04.000000000 +0900
+++ agent/mibgroup/mibII/ipv6.c	2008-03-26 07:29:07.122940424 +0900
@@ -8,10 +8,25 @@
 #define _KERNEL 1
 #define _I_DEFINED_KERNEL
 #endif
+
+/* make this source a wee bit more readable */
+#if defined(__NetBSD__) && __NetBSD_Version__ >= 106250000	/*1.6Y*/
+#define OS_NET_BSD_16_OR_LATER 1
+#endif
+#if !(defined(__FreeBSD__) && __FreeBSD__ >= 3) && !defined(darwin)
+#define OS_NOT_FREEBSD_NOR_DARWIN 1
+#endif
+#if (defined(__FreeBSD__) && __FreeBSD__ >= 3) || defined(darwin)
+#define OS_FREEBSD_OR_DARWIN 1
+#if !defined(INP_IPV6PROTO)
+#define	INP_IPV6PROTO	0x04
+#endif
+#endif
+
 #include <sys/types.h>
 #include <sys/param.h>
 #include <sys/socket.h>
-#if (defined(__FreeBSD__) && __FreeBSD__ >= 3) || defined(darwin)
+#if OS_FREEBSD_OR_DARWIN
 # if HAVE_SYS_SOCKETVAR_H
 #  include <sys/socketvar.h>
 # endif
@@ -80,7 +95,7 @@
 # include <netinet6/ip6_var.h>
 #endif
 #include <net/route.h>
-#if (defined(__FreeBSD__) && __FreeBSD__ >= 3) || defined(darwin)
+#if OS_FREEBSD_OR_DARWIN
 # if HAVE_NETINET_IN_PCB_H
 #  include <netinet/in_pcb.h>
 # endif
@@ -578,7 +593,7 @@
             memcpy(result, &tmp, sizeof(tmp));
             return 0;
         }
-#if (defined(__FreeBSD__) && __FreeBSD__ >= 3) || defined(darwin)
+#if OS_FREEBSD_OR_DARWIN
         q = (caddr_t) TAILQ_NEXT(&tmp, if_link);
 #else
 # if defined(__NetBSD__) || defined(__OpenBSD__)
@@ -809,7 +824,7 @@
 
             if (if_getifnet(interface, &ifnet) < 0)
                 break;
-#if (defined(__FreeBSD__) && __FreeBSD__ >= 3) || defined(darwin)
+#if OS_FREEBSD_OR_DARWIN
             ifa = (caddr_t) TAILQ_FIRST(&ifnet.if_addrhead);
 #else
 # if defined(__NetBSD__) || defined(__OpenBSD__)
@@ -836,7 +851,7 @@
                     *var_len = sdl.sdl_alen;
                     return (u_char *) (sdl.sdl_data + sdl.sdl_nlen);
                 }
-#if (defined(__FreeBSD__) && __FreeBSD__ >= 3) || defined(darwin)
+#if OS_FREEBSD_OR_DARWIN
                 ifa = (caddr_t) TAILQ_NEXT(&ifaddr, ifa_link);
 #else
 # if defined(__NetBSD__) || defined(__OpenBSD__)
@@ -1229,32 +1244,33 @@
          size_t * length,
          int exact, size_t * var_len, WriteMethod ** write_method)
 {
-    oid             newname[MAX_OID_LEN];
-    oid             savname[MAX_OID_LEN];
+    oid             newname[MAX_OID_LEN], savname[MAX_OID_LEN];
     int             result;
     int             i, j;
     caddr_t         p;
-    static struct in6pcb in6pcb, savpcb;
+    static struct in6pcb tstpcb, savpcb;
     int             found, savnameLen;
-#if defined(__NetBSD__) && __NetBSD_Version__ >= 106250000	/*1.6Y*/
+#if OS_NOT_FREEBSD_NOR_DARWIN
+    static struct in6pcb udb6;
+#endif
+#if OS_NET_BSD_16_OR_LATER
     struct inpcbtable udbtable;
     caddr_t	    first;
-#elif (defined(__FreeBSD__) && __FreeBSD__ >= 3) || defined(darwin)
+#endif
+#if OS_FREEBSD_OR_DARWIN
     char           *sysctl_buf;
     struct xinpgen *xig, *oxig;
-#else
-    static struct in6pcb udb6;
 #endif
 
     DEBUGMSGTL(("mibII/ipv6", "var_udp6: "));
     DEBUGMSGOID(("mibII/ipv6", name, *length));
     DEBUGMSG(("mibII/ipv6", " %d\n", exact));
 
-#if defined(__NetBSD__) && __NetBSD_Version__ >= 106250000	/*1.6Y*/
+#if OS_NET_BSD_16_OR_LATER
     if (!auto_nlist("udbtable", (char *) &udbtable, sizeof(udbtable)))
         return NULL;
     first = p = (caddr_t)udbtable.inpt_queue.cqh_first;
-#elif !(defined(__FreeBSD__) && __FreeBSD__ >= 3) && !defined(darwin)
+#elif OS_NOT_FREEBSD_NOR_DARWIN
     if (!auto_nlist("udb6", (char *) &udb6, sizeof(udb6)))
         return NULL;
     p = (caddr_t) udb6.in6p_next;
@@ -1283,9 +1299,10 @@
            (int) vp->namelen * sizeof(oid));
     DEBUGMSGTL(("mibII/ipv6", "start: p=%x\n", p));
     while (
-#if defined(__NetBSD__) && __NetBSD_Version__ >= 106250000	/*1.6Y*/
+#if OS_NET_BSD_16_OR_LATER
               p &&  p != first
-#elif !(defined(__FreeBSD__) && __FreeBSD__ >= 3) && !defined(darwin)
+#elif OS_NOT_FREEBSD_NOR_DARWIN
+
               p && (u_long) p != auto_nlist_value("udb6")
 #else
               xig->xig_len > sizeof(struct xinpgen)
@@ -1293,31 +1310,32 @@
         ) {
         DEBUGMSGTL(("mibII/ipv6", "looping: p=%x\n", p));
 
-#if !(defined(__FreeBSD__) && __FreeBSD__ >= 3) && !defined(darwin)
-        if (!NETSNMP_KLOOKUP(p, (char *) &in6pcb, sizeof(in6pcb))) {
+#if OS_NOT_FREEBSD_NOR_DARWIN
+        if (!NETSNMP_KLOOKUP(p, (char *) &tstpcb, sizeof(tstpcb))) {
             DEBUGMSGTL(("mibII/ipv6", "klookup fail for udb6 at %x\n",
                         p));
             found = 0;
             break;
         }
 #else
-        in6pcb = ((struct xinpcb *) xig)->xi_inp;
+        tstpcb = ((struct xinpcb *) xig)->xi_inp;
 #endif
-#if defined(__NetBSD__) && __NetBSD_Version__ >= 106250000	/*1.6Y*/
-        if (in6pcb.in6p_af != AF_INET6)
+#if OS_NET_BSD_16_OR_LATER
+        if (tstpcb.in6p_af != AF_INET6) {
+            p = (caddr_t)tstpcb.in6p_queue.cqe_next;
             goto skip;
-#elif (defined(__FreeBSD__) && __FreeBSD__ >= 3) || defined(darwin)
-        if (0 == (in6pcb.inp_vflag & INP_IPV6))
+#elif OS_FREEBSD_OR_DARWIN
+        if (0 == (tstpcb.inp_vflag & INP_IPV6PROTO))
             goto skip;
 #endif
 
         j = (int) vp->namelen;
         for (i = 0; i < sizeof(struct in6_addr); i++)
-            newname[j++] = in6pcb.in6p_laddr.s6_addr[i];
-        newname[j++] = ntohs(in6pcb.in6p_lport);
-        if (IN6_IS_ADDR_LINKLOCAL(&in6pcb.in6p_laddr))
+            newname[j++] = tstpcb.in6p_laddr.s6_addr[i];
+        newname[j++] = ntohs(tstpcb.inp_lport);
+        if (IN6_IS_ADDR_LINKLOCAL(&tstpcb.in6p_laddr))
             newname[j++] =
-                ntohs(*(uint16_t *) & in6pcb.in6p_laddr.s6_addr[2]);
+                ntohs(*(uint16_t *) & tstpcb.in6p_laddr.s6_addr[2]);
         else
             newname[j++] = 0;
         /*XXX*/
@@ -1328,7 +1346,7 @@
 
         result = snmp_oid_compare(name, *length, newname, j);
         if (exact && (result == 0)) {
-                memcpy(&savpcb, &in6pcb, sizeof(savpcb));
+                memcpy(&savpcb, &tstpcb, sizeof(savpcb));
                 savnameLen = j;
                 memcpy(savname, newname, j * sizeof(oid));
                 found++;
@@ -1339,7 +1357,7 @@
              */
             if ((savnameLen == 0) ||
               (snmp_oid_compare(savname, savnameLen, newname, j) > 0)) {
-                memcpy(&savpcb, &in6pcb, sizeof(savpcb));
+                memcpy(&savpcb, &tstpcb, sizeof(savpcb));
                 savnameLen = j;
                 memcpy(savname, newname, j * sizeof(oid));
                     found++;
@@ -1347,15 +1365,15 @@
         }
 
       skip:
-#if defined(__NetBSD__) && __NetBSD_Version__ >= 106250000	/*1.6Y*/
-        p = (caddr_t)in6pcb.in6p_queue.cqe_next;
-#elif !(defined(__FreeBSD__) && __FreeBSD__ >= 3) && !defined(darwin)
-        p = (caddr_t) in6pcb.in6p_next;
+#if OS_NET_BSD_16_OR_LATER
+        p = (caddr_t)tstpcb.in6p_queue.cqe_next;
+#elif OS_NOT_FREEBSD_NOR_DARWIN
+        p = (caddr_t) tstpcb.in6p_next;
 #else
         xig = (struct xinpgen *) ((char *) xig + xig->xig_len);
 #endif
     }
-#if (defined(__FreeBSD__) && __FreeBSD__ >= 3) || defined(darwin)
+#if OS_FREEBSD_OR_DARWIN
     free(sysctl_buf);
 #endif
     DEBUGMSGTL(("mibII/ipv6", "found=%d\n", found));
@@ -1363,7 +1381,7 @@
         return NULL;
     *length = savnameLen;
     memcpy((char *) name, (char *) savname, *length * sizeof(oid));
-    memcpy(&in6pcb, &savpcb, sizeof(savpcb));
+    memcpy(&tstpcb, &savpcb, sizeof(savpcb));
     *write_method = 0;
     *var_len = sizeof(long);    /* default to 'long' results */
 
@@ -1376,14 +1394,14 @@
     switch (vp->magic) {
     case IPV6UDPLOCALADDRESS:
         *var_len = sizeof(struct in6_addr);
-        return in6pcb.in6p_laddr.s6_addr;
+        return savpcb.in6p_laddr.s6_addr;
     case IPV6UDPLOCALPORT:
-        long_return = ntohs(in6pcb.in6p_lport);
+        long_return = ntohs(savpcb.inp_lport);
         return (u_char *) & long_return;
     case IPV6UDPIFINDEX:
-        if (IN6_IS_ADDR_LINKLOCAL(&in6pcb.in6p_laddr))
+        if (IN6_IS_ADDR_LINKLOCAL(&savpcb.in6p_laddr))
             long_return =
-                ntohs(*(uint16_t *) & in6pcb.in6p_laddr.s6_addr[2]);
+                ntohs(*(uint16_t *) & savpcb.in6p_laddr.s6_addr[2]);
         else
             long_return = 0;
         /*XXX*/ return (u_char *) & long_return;
@@ -1401,24 +1419,24 @@
          size_t * length,
          int exact, size_t * var_len, WriteMethod ** write_method)
 {
-    oid             newname[MAX_OID_LEN];
-    oid             savname[MAX_OID_LEN];
+    oid             newname[MAX_OID_LEN], savname[MAX_OID_LEN];
     int             result;
     int             i, j;
     caddr_t         p;
-    static struct in6pcb in6pcb, savpcb;
+    static struct in6pcb tstpcb, savpcb;
     struct tcp6cb   tcp6cb;
     int             found, savnameLen;
     static int      tcp6statemap[TCP6_NSTATES];
     static int      initialized = 0;
-#if defined(__NetBSD__) && __NetBSD_Version__ >= 106250000	/*1.6Y*/
+#if OS_NOT_FREEBSD_NOR_DARWIN
+    static struct in6pcb tcb6;
+#endif
+#if OS_NET_BSD_16_OR_LATER
     struct inpcbtable tcbtable;
     caddr_t	    first;
-#elif (defined(__FreeBSD__) && __FreeBSD__ >= 3) || defined(darwin)
+#elif OS_FREEBSD_OR_DARWIN
     char           *sysctl_buf;
     struct xinpgen *xig, *oxig;
-#else
-    static struct in6pcb tcb6;
 #endif
 
     if (!initialized) {
@@ -1440,11 +1458,11 @@
     DEBUGMSGOID(("mibII/ipv6", name, *length));
     DEBUGMSG(("mibII/ipv6", " %d\n", exact));
 
-#if defined(__NetBSD__) && __NetBSD_Version__ >= 106250000	/*1.6Y*/
+#if OS_NET_BSD_16_OR_LATER
     if (!auto_nlist("tcbtable", (char *) &tcbtable, sizeof(tcbtable)))
         return NULL;
     first = p = (caddr_t)tcbtable.inpt_queue.cqh_first;
-#elif !(defined(__FreeBSD__) && __FreeBSD__ >= 3) && !defined(darwin)
+#elif OS_NOT_FREEBSD_NOR_DARWIN
     if (!auto_nlist("tcb6", (char *) &tcb6, sizeof(tcb6)))
         return NULL;
     p = (caddr_t) tcb6.in6p_next;
@@ -1473,9 +1491,10 @@
            (int) vp->namelen * sizeof(oid));
     DEBUGMSGTL(("mibII/ipv6", "start: p=%x\n", p));
     while (
-#if defined(__NetBSD__) && __NetBSD_Version__ >= 106250000	/*1.6Y*/
+#if OS_NET_BSD_16_OR_LATER
               p &&  p != first
-#elif !(defined(__FreeBSD__) && __FreeBSD__ >= 3) && !defined(darwin)
+#elif OS_NOT_FREEBSD_NOR_DARWIN
+
               p && (u_long) p != auto_nlist_value("tcb6")
 #else
               xig->xig_len > sizeof(struct xinpgen)
@@ -1483,39 +1502,39 @@
         ) {
         DEBUGMSGTL(("mibII/ipv6", "looping: p=%x\n", p));
 
-#if !(defined(__FreeBSD__) && __FreeBSD__ >= 3) && !defined(darwin)
-        if (!NETSNMP_KLOOKUP(p, (char *) &in6pcb, sizeof(in6pcb))) {
+#if OS_NOT_FREEBSD_NOR_DARWIN
+        if (!NETSNMP_KLOOKUP(p, (char *) &tstpcb, sizeof(tstpcb))) {
             DEBUGMSGTL(("mibII/ipv6", "klookup fail for tcb6 at %x\n",
                         p));
             found = 0;
             break;
         }
 #else
-        in6pcb = ((struct xinpcb *) xig)->xi_inp;
+        tstpcb = ((struct xinpcb *) xig)->xi_inp;
 #endif
-#if defined(__NetBSD__) && __NetBSD_Version__ >= 106250000	/*1.6Y*/
-        if (in6pcb.in6p_af != AF_INET6)
+#if OS_NET_BSD_16_OR_LATER
+        if (tstpcb.in6p_af != AF_INET6)
             goto skip;
-#elif (defined(__FreeBSD__) && __FreeBSD__ >= 3) || defined(darwin)
-        if (0 == (in6pcb.inp_vflag & INP_IPV6))
+#elif OS_FREEBSD_OR_DARWIN
+        if (0 == (tstpcb.inp_vflag & INP_IPV6))
             goto skip;
 #endif
-        if (!NETSNMP_KLOOKUP(in6pcb.in6p_ppcb, (char *) &tcp6cb, sizeof(tcp6cb))) {
+        if (!NETSNMP_KLOOKUP(tstpcb.inp_ppcb, (char *) &tcp6cb, sizeof(tcp6cb))) {
             DEBUGMSGTL(("mibII/ipv6", "klookup fail for tcb6.tcp6cb at %x\n",
-                        in6pcb.in6p_ppcb));
+                        tstpcb.inp_ppcb));
             found = 0;
             break;
         }
         j = (int) vp->namelen;
         for (i = 0; i < sizeof(struct in6_addr); i++)
-            newname[j++] = in6pcb.in6p_laddr.s6_addr[i];
-        newname[j++] = ntohs(in6pcb.in6p_lport);
+            newname[j++] = tstpcb.in6p_laddr.s6_addr[i];
+        newname[j++] = ntohs(tstpcb.inp_lport);
         for (i = 0; i < sizeof(struct in6_addr); i++)
-            newname[j++] = in6pcb.in6p_faddr.s6_addr[i];
-        newname[j++] = ntohs(in6pcb.in6p_fport);
-        if (IN6_IS_ADDR_LINKLOCAL(&in6pcb.in6p_laddr))
+            newname[j++] = tstpcb.in6p_faddr.s6_addr[i];
+        newname[j++] = ntohs(tstpcb.inp_fport);
+        if (IN6_IS_ADDR_LINKLOCAL(&tstpcb.in6p_laddr))
             newname[j++] =
-                ntohs(*(uint16_t *) & in6pcb.in6p_laddr.s6_addr[2]);
+                ntohs(*(uint16_t *) & tstpcb.in6p_laddr.s6_addr[2]);
         else
             newname[j++] = 0;
         /*XXX*/ newname[j++] = tcp6statemap[tcp6cb.t_state];
@@ -1526,13 +1545,13 @@
         DEBUGMSG(("mibII/ipv6", " %d\n", exact));
 
 #if 1                           /* this is very odd but sometimes happen, and cause infinite loop */
-        if (ntohs(in6pcb.in6p_lport) == 0)
+        if (ntohs(tstpcb.inp_lport) == 0)
             goto skip;
 #endif
 
         result = snmp_oid_compare(name, *length, newname, j);
         if (exact && (result == 0)) {
-                memcpy(&savpcb, &in6pcb, sizeof(savpcb));
+                memcpy(&savpcb, &tstpcb, sizeof(savpcb));
                 savnameLen = j;
                 memcpy(savname, newname, j * sizeof(oid));
                 found++;
@@ -1543,7 +1562,7 @@
              */
             if ((savnameLen == 0) ||
               (snmp_oid_compare(savname, savnameLen, newname, j) > 0)) {
-                memcpy(&savpcb, &in6pcb, sizeof(savpcb));
+                memcpy(&savpcb, &tstpcb, sizeof(savpcb));
                 savnameLen = j;
                 memcpy(savname, newname, j * sizeof(oid));
                     found++;
@@ -1551,15 +1570,15 @@
         }
 
       skip:
-#if defined(__NetBSD__) && __NetBSD_Version__ >= 106250000	/*1.6Y*/
-        p = (caddr_t)in6pcb.in6p_queue.cqe_next;
-#elif !(defined(__FreeBSD__) && __FreeBSD__ >= 3) && !defined(darwin)
-        p = (caddr_t) in6pcb.in6p_next;
+#if OS_NET_BSD_16_OR_LATER
+        p = (caddr_t)tstpcb.in6p_queue.cqe_next;
+#elif OS_NOT_FREEBSD_NOR_DARWIN
+        p = (caddr_t) tstpcb.in6p_next;
 #else
         xig = (struct xinpgen *) ((char *) xig + xig->xig_len);
 #endif
     }
-#if (defined(__FreeBSD__) && __FreeBSD__ >= 3) || defined(darwin)
+#if OS_FREEBSD_OR_DARWIN
     free(sysctl_buf);
 #endif
     DEBUGMSGTL(("mibII/ipv6", "found=%d\n", found));
@@ -1580,20 +1599,20 @@
     switch (vp->magic) {
     case IPV6TCPLOCALADDR:
         *var_len = sizeof(struct in6_addr);
-        return (u_char *) & in6pcb.in6p_laddr.s6_addr[0];
+        return (u_char *) & savpcb.in6p_laddr.s6_addr[0];
     case IPV6TCPLOCALPORT:
-        long_return = ntohs(in6pcb.in6p_lport);
+        long_return = ntohs(savpcb.inp_lport);
         return (u_char *) & long_return;
     case IPV6TCPREMOTEADDR:
         *var_len = sizeof(struct in6_addr);
-        return (u_char *) & in6pcb.in6p_faddr.s6_addr[0];
+        return (u_char *) & savpcb.in6p_faddr.s6_addr[0];
     case IPV6TCPREMOTEPORT:
-        long_return = ntohs(in6pcb.in6p_fport);
+        long_return = ntohs(savpcb.inp_fport);
         return (u_char *) & long_return;
     case IPV6TCPIFINDEX:
-        if (IN6_IS_ADDR_LINKLOCAL(&in6pcb.in6p_laddr))
+        if (IN6_IS_ADDR_LINKLOCAL(&savpcb.in6p_laddr))
             long_return =
-                ntohs(*(uint16_t *) & in6pcb.in6p_laddr.s6_addr[2]);
+                ntohs(*(uint16_t *) & savpcb.in6p_laddr.s6_addr[2]);
         else
             long_return = 0;
         /*XXX*/ return (u_char *) & long_return;
@@ -1640,22 +1659,23 @@
          size_t * length,
          int exact, size_t * var_len, WriteMethod ** write_method)
 {
-    oid             newname[MAX_OID_LEN];
-    oid             savname[MAX_OID_LEN];
+    oid             newname[MAX_OID_LEN], savname[MAX_OID_LEN];
     int             result;
     int             i, j;
     caddr_t         p;
-    static struct in6pcb in6pcb, savpcb;
+    static struct in6pcb tstpcb, savpcb;
     struct tcpcb    tcpcb;
     int             found, savnameLen;
-#if defined(__NetBSD__) && __NetBSD_Version__ >= 106250000	/*1.6Y*/
+#if OS_NOT_FREEBSD_NOR_DARWIN
+    static struct in6pcb tcb6;
+#endif
+#if OS_NET_BSD_16_OR_LATER
     struct inpcbtable tcbtable;
     caddr_t	    first;
-#elif (defined(__FreeBSD__) && __FreeBSD__ >= 3) || defined(darwin)
+#endif
+#if OS_FREEBSD_OR_DARWIN
     char           *sysctl_buf;
     struct xinpgen *xig, *oxig;
-#else
-    static struct in6pcb tcb6;
 #endif
 
     DEBUGMSGTL(("mibII/ipv6", "var_tcp6: "));
@@ -1695,9 +1715,9 @@
            (int) vp->namelen * sizeof(oid));
     DEBUGMSGTL(("mibII/ipv6", "start: p=%x\n", p));
     while (
-#if defined(__NetBSD__) && __NetBSD_Version__ >= 106250000	/*1.6Y*/
+#if OS_NET_BSD_16_OR_LATER
               p && p != first
-#elif !(defined(__FreeBSD__) && __FreeBSD__ >= 3) && !defined(darwin)
+#elif OS_NOT_FREEBSD_NOR_DARWIN
               p && (u_long) p != auto_nlist_value("tcb6")
 #else
               xig->xig_len > sizeof(struct xinpgen)
@@ -1705,39 +1725,39 @@
         ) {
         DEBUGMSGTL(("mibII/ipv6", "looping: p=%x\n", p));
 
-#if !(defined(__FreeBSD__) && __FreeBSD__ >= 3) && !defined(darwin)
-        if (!NETSNMP_KLOOKUP(p, (char *) &in6pcb, sizeof(in6pcb))) {
+#if OS_NOT_FREEBSD_NOR_DARWIN
+        if (!NETSNMP_KLOOKUP(p, (char *) &tstpcb, sizeof(tstpcb))) {
             DEBUGMSGTL(("mibII/ipv6", "klookup fail for tcb6 at %x\n",
                         p));
             found = 0;
             break;
         }
 #else
-        in6pcb = ((struct xinpcb *) xig)->xi_inp;
+        tstpcb = ((struct xinpcb *) xig)->xi_inp;
 #endif
-#if defined(__NetBSD__) && __NetBSD_Version__ >= 106250000	/*1.6Y*/
-        if (in6pcb.in6p_af != AF_INET6)
+#if OS_NET_BSD_16_OR_LATER
+        if (tstpcb.in6p_af != AF_INET6)
             goto skip;
-#elif (defined(__FreeBSD__) && __FreeBSD__ >= 3) || defined(darwin)
-        if (0 == (in6pcb.inp_vflag & INP_IPV6))
+#elif OS_FREEBSD_OR_DARWIN
+        if (0 == (tstpcb.inp_vflag & INP_IPV6))
             goto skip;
 #endif
-        if (!NETSNMP_KLOOKUP(in6pcb.in6p_ppcb, (char *) &tcpcb, sizeof(tcpcb))) {
+        if (!NETSNMP_KLOOKUP(tstpcb.inp_ppcb, (char *) &tcpcb, sizeof(tcpcb))) {
             DEBUGMSGTL(("mibII/ipv6", "klookup fail for tcb6.tcpcb at %x\n",
-                        in6pcb.in6p_ppcb));
+                        tstpcb.inp_ppcb));
             found = 0;
             break;
         }
         j = (int) vp->namelen;
         for (i = 0; i < sizeof(struct in6_addr); i++)
-            newname[j++] = in6pcb.in6p_laddr.s6_addr[i];
-        newname[j++] = ntohs(in6pcb.in6p_lport);
+            newname[j++] = tstpcb.in6p_laddr.s6_addr[i];
+        newname[j++] = ntohs(tstpcb.inp_lport);
         for (i = 0; i < sizeof(struct in6_addr); i++)
-            newname[j++] = in6pcb.in6p_faddr.s6_addr[i];
-        newname[j++] = ntohs(in6pcb.in6p_fport);
-        if (IN6_IS_ADDR_LINKLOCAL(&in6pcb.in6p_laddr))
+            newname[j++] = tstpcb.in6p_faddr.s6_addr[i];
+        newname[j++] = ntohs(tstpcb.inp_fport);
+        if (IN6_IS_ADDR_LINKLOCAL(&tstpcb.in6p_laddr))
             newname[j++] =
-                ntohs(*(uint16_t *) & in6pcb.in6p_laddr.s6_addr[2]);
+                ntohs(*(uint16_t *) & tstpcb.in6p_laddr.s6_addr[2]);
         else
             newname[j++] = 0;
         /*XXX*/ newname[j++] = mapTcpState((int)tcpcb.t_state);
@@ -1748,12 +1768,12 @@
         DEBUGMSG(("mibII/ipv6", " %d\n", exact));
 
 #if 1                           /* this is very odd but sometimes happen, and cause infinite loop */
-        if (ntohs(in6pcb.in6p_lport) == 0)
+        if (ntohs(tstpcb.inp_lport) == 0)
             goto skip;
 #endif
         result = snmp_oid_compare(name, *length, newname, j);
         if (exact && (result == 0)) {
-                memcpy(&savpcb, &in6pcb, sizeof(savpcb));
+                memcpy(&savpcb, &tstpcb, sizeof(savpcb));
                 savnameLen = j;
                 memcpy(savname, newname, j * sizeof(oid));
                 found++;
@@ -1764,7 +1784,7 @@
              */
             if ((savnameLen == 0) ||
               (snmp_oid_compare(savname, savnameLen, newname, j) > 0)) {
-                memcpy(&savpcb, &in6pcb, sizeof(savpcb));
+                memcpy(&savpcb, &tstpcb, sizeof(savpcb));
                 savnameLen = j;
                 memcpy(savname, newname, j * sizeof(oid));
                     found++;
@@ -1772,15 +1792,15 @@
         }
 
       skip:
-#if defined(__NetBSD__) && __NetBSD_Version__ >= 106250000	/*1.6Y*/
-        p = (caddr_t)in6pcb.in6p_queue.cqe_next;
-#elif !(defined(__FreeBSD__) && __FreeBSD__ >= 3) && !defined(darwin)
-        p = (caddr_t) in6pcb.in6p_next;
+#if OS_NET_BSD_16_OR_LATER
+        p = (caddr_t)tstpcb.in6p_queue.cqe_next;
+#elif OS_NOT_FREEBSD_NOR_DARWIN
+        p = (caddr_t) tstpcb.in6p_next;
 #else
         xig = (struct xinpgen *) ((char *) xig + xig->xig_len);
 #endif
     }
-#if (defined(__FreeBSD__) && __FreeBSD__ >= 3) || defined(darwin)
+#if OS_FREEBSD_OR_DARWIN
     free(sysctl_buf);
 #endif
     DEBUGMSGTL(("mibII/ipv6", "found=%d\n", found));
@@ -1788,7 +1808,7 @@
         return NULL;
     *length = savnameLen;
     memcpy((char *) name, (char *) savname, *length * sizeof(oid));
-    memcpy(&in6pcb, &savpcb, sizeof(savpcb));
+    memcpy(&tstpcb, &savpcb, sizeof(savpcb));
     *write_method = 0;
     *var_len = sizeof(long);    /* default to 'long' results */
 
@@ -1801,20 +1821,20 @@
     switch (vp->magic) {
     case IPV6TCPLOCALADDR:
         *var_len = sizeof(struct in6_addr);
-        return (u_char *) & in6pcb.in6p_laddr.s6_addr[0];
+        return (u_char *) & savpcb.in6p_laddr.s6_addr[0];
     case IPV6TCPLOCALPORT:
-        long_return = ntohs(in6pcb.in6p_lport);
+        long_return = ntohs(savpcb.inp_lport);
         return (u_char *) & long_return;
     case IPV6TCPREMOTEADDR:
         *var_len = sizeof(struct in6_addr);
-        return (u_char *) & in6pcb.in6p_faddr.s6_addr[0];
+        return (u_char *) & savpcb.in6p_faddr.s6_addr[0];
     case IPV6TCPREMOTEPORT:
-        long_return = ntohs(in6pcb.in6p_fport);
+        long_return = ntohs(savpcb.inp_fport);
         return (u_char *) & long_return;
     case IPV6TCPIFINDEX:
-        if (IN6_IS_ADDR_LINKLOCAL(&in6pcb.in6p_laddr))
+        if (IN6_IS_ADDR_LINKLOCAL(&savpcb.in6p_laddr))
             long_return =
-                ntohs(*(uint16_t *) & in6pcb.in6p_laddr.s6_addr[2]);
+                ntohs(*(uint16_t *) & savpcb.in6p_laddr.s6_addr[2]);
         else
             long_return = 0;
         /*XXX*/ return (u_char *) & long_return;
