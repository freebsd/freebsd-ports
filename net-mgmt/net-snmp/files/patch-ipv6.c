--- agent/mibgroup/mibII/ipv6.c.orig	Thu Jul  8 05:31:54 2004
+++ agent/mibgroup/mibII/ipv6.c	Mon Oct 25 08:32:31 2004
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
@@ -575,7 +590,7 @@
             memcpy(result, &tmp, sizeof(tmp));
             return 0;
         }
-#if (defined(__FreeBSD__) && __FreeBSD__ >= 3) || defined(darwin)
+#if OS_FREEBSD_OR_DARWIN
         q = (caddr_t) TAILQ_NEXT(&tmp, if_link);
 #else
 # if defined(__NetBSD__) || defined(__OpenBSD__)
@@ -806,7 +821,7 @@
 
             if (if_getifnet(interface, &ifnet) < 0)
                 break;
-#if (defined(__FreeBSD__) && __FreeBSD__ >= 3) || defined(darwin)
+#if OS_FREEBSD_OR_DARWIN
             ifa = (caddr_t) TAILQ_FIRST(&ifnet.if_addrhead);
 #else
 # if defined(__NetBSD__) || defined(__OpenBSD__)
@@ -827,7 +842,7 @@
                     *var_len = sdl.sdl_alen;
                     return (u_char *) (sdl.sdl_data + sdl.sdl_nlen);
                 }
-#if (defined(__FreeBSD__) && __FreeBSD__ >= 3) || defined(darwin)
+#if OS_FREEBSD_OR_DARWIN
                 ifa = (caddr_t) TAILQ_NEXT(&ifaddr, ifa_link);
 #else
 # if defined(__NetBSD__) || defined(__OpenBSD__)
@@ -1220,32 +1235,33 @@
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
@@ -1274,9 +1290,10 @@
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
@@ -1284,31 +1301,32 @@
         ) {
         DEBUGMSGTL(("mibII/ipv6", "looping: p=%x\n", p));
 
-#if !(defined(__FreeBSD__) && __FreeBSD__ >= 3) && !defined(darwin)
-        if (klookup((u_long) p, (char *) &in6pcb, sizeof(in6pcb)) < 0) {
+#if OS_NOT_FREEBSD_NOR_DARWIN
+        if (klookup((u_long) p, (char *) &tstpcb, sizeof(tstpcb)) < 0) {
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
+        newname[j++] = ntohs(tstpcb.in6p_lport);
+        if (IN6_IS_ADDR_LINKLOCAL(&tstpcb.in6p_laddr))
             newname[j++] =
-                ntohs(*(uint16_t *) & in6pcb.in6p_laddr.s6_addr[2]);
+                ntohs(*(uint16_t *) & tstpcb.in6p_laddr.s6_addr[2]);
         else
             newname[j++] = 0;
         /*XXX*/
@@ -1319,7 +1337,7 @@
 
         result = snmp_oid_compare(name, *length, newname, j);
         if (exact && (result == 0)) {
-                memcpy(&savpcb, &in6pcb, sizeof(savpcb));
+                memcpy(&savpcb, &tstpcb, sizeof(savpcb));
                 savnameLen = j;
                 memcpy(savname, newname, j * sizeof(oid));
                 found++;
@@ -1330,7 +1348,7 @@
              */
             if ((savnameLen == 0) ||
               (snmp_oid_compare(savname, savnameLen, newname, j) > 0)) {
-                memcpy(&savpcb, &in6pcb, sizeof(savpcb));
+                memcpy(&savpcb, &tstpcb, sizeof(savpcb));
                 savnameLen = j;
                 memcpy(savname, newname, j * sizeof(oid));
                     found++;
@@ -1338,15 +1356,15 @@
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
@@ -1354,7 +1372,7 @@
         return NULL;
     *length = savnameLen;
     memcpy((char *) name, (char *) savname, *length * sizeof(oid));
-    memcpy(&in6pcb, &savpcb, sizeof(savpcb));
+    memcpy(&tstpcb, &savpcb, sizeof(savpcb));
     *write_method = 0;
     *var_len = sizeof(long);    /* default to 'long' results */
 
@@ -1367,14 +1385,14 @@
     switch (vp->magic) {
     case IPV6UDPLOCALADDRESS:
         *var_len = sizeof(struct in6_addr);
-        return in6pcb.in6p_laddr.s6_addr;
+        return savpcb.in6p_laddr.s6_addr;
     case IPV6UDPLOCALPORT:
-        long_return = ntohs(in6pcb.in6p_lport);
+        long_return = ntohs(savpcb.in6p_lport);
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
@@ -1392,24 +1410,24 @@
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
@@ -1431,11 +1449,11 @@
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
@@ -1464,9 +1482,10 @@
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
@@ -1474,41 +1493,41 @@
         ) {
         DEBUGMSGTL(("mibII/ipv6", "looping: p=%x\n", p));
 
-#if !(defined(__FreeBSD__) && __FreeBSD__ >= 3) && !defined(darwin)
-        if (klookup((u_long) p, (char *) &in6pcb, sizeof(in6pcb)) < 0) {
+#if OS_NOT_FREEBSD_NOR_DARWIN
+        if (klookup((u_long) p, (char *) &tstpcb, sizeof(tstpcb)) < 0) {
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
+        if (0 == (tstpcb.inp_vflag & INP_IPV6PROTO))
             goto skip;
 #endif
         if (klookup
-            ((u_long) in6pcb.in6p_ppcb, (char *) &tcp6cb, sizeof(tcp6cb))
+            ((u_long) tstpcb.in6p_ppcb, (char *) &tcp6cb, sizeof(tcp6cb))
             < 0) {
             DEBUGMSGTL(("mibII/ipv6", "klookup fail for tcb6.tcp6cb at %x\n",
-                        in6pcb.in6p_ppcb));
+                        tstpcb.in6p_ppcb));
             found = 0;
             break;
         }
         j = (int) vp->namelen;
         for (i = 0; i < sizeof(struct in6_addr); i++)
-            newname[j++] = in6pcb.in6p_laddr.s6_addr[i];
-        newname[j++] = ntohs(in6pcb.in6p_lport);
+            newname[j++] = tstpcb.in6p_laddr.s6_addr[i];
+        newname[j++] = ntohs(tstpcb.in6p_lport);
         for (i = 0; i < sizeof(struct in6_addr); i++)
-            newname[j++] = in6pcb.in6p_faddr.s6_addr[i];
-        newname[j++] = ntohs(in6pcb.in6p_fport);
-        if (IN6_IS_ADDR_LINKLOCAL(&in6pcb.in6p_laddr))
+            newname[j++] = tstpcb.in6p_faddr.s6_addr[i];
+        newname[j++] = ntohs(tstpcb.in6p_fport);
+        if (IN6_IS_ADDR_LINKLOCAL(&tstpcb.in6p_laddr))
             newname[j++] =
-                ntohs(*(uint16_t *) & in6pcb.in6p_laddr.s6_addr[2]);
+                ntohs(*(uint16_t *) & tstpcb.in6p_laddr.s6_addr[2]);
         else
             newname[j++] = 0;
         /*XXX*/ newname[j++] = tcp6statemap[tcp6cb.t_state];
@@ -1519,13 +1538,13 @@
         DEBUGMSG(("mibII/ipv6", " %d\n", exact));
 
 #if 1                           /* this is very odd but sometimes happen, and cause infinite loop */
-        if (ntohs(in6pcb.in6p_lport) == 0)
+        if (ntohs(tstpcb.in6p_lport) == 0)
             goto skip;
 #endif
 
         result = snmp_oid_compare(name, *length, newname, j);
         if (exact && (result == 0)) {
-                memcpy(&savpcb, &in6pcb, sizeof(savpcb));
+                memcpy(&savpcb, &tstpcb, sizeof(savpcb));
                 savnameLen = j;
                 memcpy(savname, newname, j * sizeof(oid));
                 found++;
@@ -1536,7 +1555,7 @@
              */
             if ((savnameLen == 0) ||
               (snmp_oid_compare(savname, savnameLen, newname, j) > 0)) {
-                memcpy(&savpcb, &in6pcb, sizeof(savpcb));
+                memcpy(&savpcb, &tstpcb, sizeof(savpcb));
                 savnameLen = j;
                 memcpy(savname, newname, j * sizeof(oid));
                     found++;
@@ -1544,15 +1563,15 @@
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
@@ -1573,20 +1592,20 @@
     switch (vp->magic) {
     case IPV6TCPLOCALADDR:
         *var_len = sizeof(struct in6_addr);
-        return (u_char *) & in6pcb.in6p_laddr.s6_addr[0];
+        return (u_char *) & savpcb.in6p_laddr.s6_addr[0];
     case IPV6TCPLOCALPORT:
-        long_return = ntohs(in6pcb.in6p_lport);
+        long_return = ntohs(savpcb.in6p_lport);
         return (u_char *) & long_return;
     case IPV6TCPREMOTEADDR:
         *var_len = sizeof(struct in6_addr);
-        return (u_char *) & in6pcb.in6p_faddr.s6_addr[0];
+        return (u_char *) & savpcb.in6p_faddr.s6_addr[0];
     case IPV6TCPREMOTEPORT:
-        long_return = ntohs(in6pcb.in6p_fport);
+        long_return = ntohs(savpcb.in6p_fport);
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
@@ -1633,22 +1652,23 @@
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
@@ -1688,9 +1708,9 @@
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
@@ -1698,41 +1718,41 @@
         ) {
         DEBUGMSGTL(("mibII/ipv6", "looping: p=%x\n", p));
 
-#if !(defined(__FreeBSD__) && __FreeBSD__ >= 3) && !defined(darwin)
-        if (klookup((u_long) p, (char *) &in6pcb, sizeof(in6pcb)) < 0) {
+#if OS_NOT_FREEBSD_NOR_DARWIN
+        if (klookup((u_long) p, (char *) &tstpcb, sizeof(in6pcb)) < 0) {
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
+        if (0 == (tstpcb.inp_vflag & INP_IPV6PROTO))
             goto skip;
 #endif
         if (klookup
-            ((u_long) in6pcb.in6p_ppcb, (char *) &tcpcb, sizeof(tcpcb))
+            ((u_long) tstpcb.in6p_ppcb, (char *) &tcpcb, sizeof(tcpcb))
             < 0) {
-            DEBUGMSGTL(("mibII/ipv6", "klookup fail for tcb6.tcpcb at %x\n",
-                        in6pcb.in6p_ppcb));
+            DEBUGMSGTL(("mibII/ipv6", "klookup fail for tcb6.tcp6cb at %x\n",
+                        tstpcb.in6p_ppcb));
             found = 0;
             break;
         }
         j = (int) vp->namelen;
         for (i = 0; i < sizeof(struct in6_addr); i++)
-            newname[j++] = in6pcb.in6p_laddr.s6_addr[i];
-        newname[j++] = ntohs(in6pcb.in6p_lport);
+            newname[j++] = tstpcb.in6p_laddr.s6_addr[i];
+        newname[j++] = ntohs(tstpcb.in6p_lport);
         for (i = 0; i < sizeof(struct in6_addr); i++)
-            newname[j++] = in6pcb.in6p_faddr.s6_addr[i];
-        newname[j++] = ntohs(in6pcb.in6p_fport);
-        if (IN6_IS_ADDR_LINKLOCAL(&in6pcb.in6p_laddr))
+            newname[j++] = tstpcb.in6p_faddr.s6_addr[i];
+        newname[j++] = ntohs(tstpcb.in6p_fport);
+        if (IN6_IS_ADDR_LINKLOCAL(&tstpcb.in6p_laddr))
             newname[j++] =
-                ntohs(*(uint16_t *) & in6pcb.in6p_laddr.s6_addr[2]);
+                ntohs(*(uint16_t *) & tstpcb.in6p_laddr.s6_addr[2]);
         else
             newname[j++] = 0;
         /*XXX*/ newname[j++] = mapTcpState((int)tcpcb.t_state);
@@ -1743,12 +1763,12 @@
         DEBUGMSG(("mibII/ipv6", " %d\n", exact));
 
 #if 1                           /* this is very odd but sometimes happen, and cause infinite loop */
-        if (ntohs(in6pcb.in6p_lport) == 0)
+        if (ntohs(tstpcb.in6p_lport) == 0)
             goto skip;
 #endif
         result = snmp_oid_compare(name, *length, newname, j);
         if (exact && (result == 0)) {
-                memcpy(&savpcb, &in6pcb, sizeof(savpcb));
+                memcpy(&savpcb, &tstpcb, sizeof(savpcb));
                 savnameLen = j;
                 memcpy(savname, newname, j * sizeof(oid));
                 found++;
@@ -1759,7 +1779,7 @@
              */
             if ((savnameLen == 0) ||
               (snmp_oid_compare(savname, savnameLen, newname, j) > 0)) {
-                memcpy(&savpcb, &in6pcb, sizeof(savpcb));
+                memcpy(&savpcb, &tstpcb, sizeof(savpcb));
                 savnameLen = j;
                 memcpy(savname, newname, j * sizeof(oid));
                     found++;
@@ -1767,15 +1787,15 @@
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
@@ -1783,7 +1803,7 @@
         return NULL;
     *length = savnameLen;
     memcpy((char *) name, (char *) savname, *length * sizeof(oid));
-    memcpy(&in6pcb, &savpcb, sizeof(savpcb));
+    memcpy(&tstpcb, &savpcb, sizeof(savpcb));
     *write_method = 0;
     *var_len = sizeof(long);    /* default to 'long' results */
 
@@ -1796,20 +1816,20 @@
     switch (vp->magic) {
     case IPV6TCPLOCALADDR:
         *var_len = sizeof(struct in6_addr);
-        return (u_char *) & in6pcb.in6p_laddr.s6_addr[0];
+        return (u_char *) & savpcb.in6p_laddr.s6_addr[0];
     case IPV6TCPLOCALPORT:
-        long_return = ntohs(in6pcb.in6p_lport);
+        long_return = ntohs(savpcb.in6p_lport);
         return (u_char *) & long_return;
     case IPV6TCPREMOTEADDR:
         *var_len = sizeof(struct in6_addr);
-        return (u_char *) & in6pcb.in6p_faddr.s6_addr[0];
+        return (u_char *) & savpcb.in6p_faddr.s6_addr[0];
     case IPV6TCPREMOTEPORT:
-        long_return = ntohs(in6pcb.in6p_fport);
+        long_return = ntohs(savpcb.in6p_fport);
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
