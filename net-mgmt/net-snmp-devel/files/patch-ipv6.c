--- agent/mibgroup/mibII/ipv6.c.orig	Fri Feb 28 18:13:36 2003
+++ agent/mibgroup/mibII/ipv6.c	Wed Nov 19 00:16:27 2003
@@ -1238,6 +1238,7 @@
     if (!auto_nlist("udb6", (char *) &udb6, sizeof(udb6)))
         return NULL;
     p = (caddr_t) udb6.in6p_next;
+    DEBUGMSGTL(("mibII/ipv6", "start: p=%x\n", p));
 #else
     {
         const char     *udblist = "net.inet.udp.pcblist";
@@ -1254,11 +1255,11 @@
         oxig = (struct xinpgen *) sysctl_buf;
         xig = (struct xinpgen *) ((char *) oxig + oxig->xig_len);
     }
+    DEBUGMSGTL(("mibII/ipv6", "start: xig=%p\n", xig));
 #endif
     found = hitnext = 0;
     memcpy((char *) newname, (char *) vp->name,
            (int) vp->namelen * sizeof(oid));
-    DEBUGMSGTL(("mibII/ipv6", "start: p=%x\n", p));
     while (
 #if !(defined(__FreeBSD__) && __FreeBSD__ >= 3)
               p && (u_long) p != auto_nlist_value("udb6")
@@ -1266,12 +1267,16 @@
               xig->xig_len > sizeof(struct xinpgen)
 #endif
         ) {
-        DEBUGMSGTL(("mibII/ipv6", "looping: p=%x\n", p));
 
 #if !(defined(__FreeBSD__) && __FreeBSD__ >= 3)
+        DEBUGMSGTL(("mibII/ipv6", "looping: p=%x\n", p));
         klookup((u_long) p, (char *) &in6pcb, sizeof(in6pcb));
 #else
         in6pcb = ((struct xinpcb *) xig)->xi_inp;
+	if (!(in6pcb.inp_vflag & 0x02)) { /* Skip non-IPv6 pcb */
+	  xig = (struct xinpgen *) ((char *) xig + xig->xig_len);
+	  continue;
+	}
 #endif
         j = (int) vp->namelen;
         for (i = 0; i < sizeof(struct in6_addr); i++)
@@ -1283,8 +1288,8 @@
         else
             newname[j++] = 0;
         /*XXX*/
-            DEBUGMSGTL(("mibII/ipv6", "var_udp6 new: %d %d ",
-                        (int) vp->namelen, j));
+	DEBUGMSGTL(("mibII/ipv6", "var_udp6 new: %d %d ",
+		    (int) vp->namelen, j));
         DEBUGMSGOID(("mibII/ipv6", newname, j));
         DEBUGMSG(("mibII/ipv6", " %d\n", exact));
 
@@ -1447,9 +1452,6 @@
                         p));
             break;
         }
-#else
-        in6pcb = ((struct xinpcb *) xig)->xi_inp;
-#endif
         if (klookup
             ((u_long) in6pcb.in6p_ppcb, (char *) &tcp6cb, sizeof(tcp6cb))
             < 0) {
@@ -1457,6 +1459,14 @@
                         in6pcb.in6p_ppcb));
             break;
         }
+#else
+        in6pcb = ((struct xinpcb *) xig)->xi_inp;
+	struct xtcpcb *xp = (struct xtcpcb *)xig;
+	tcp6cb = xp->xt_tp;
+	if (!(in6pcb.inp_vflag & 0x02)) { /* Skip non-IPv6 pcb */
+	  goto skip;
+	}
+#endif
         j = (int) vp->namelen;
         for (i = 0; i < sizeof(struct in6_addr); i++)
             newname[j++] = in6pcb.in6p_laddr.s6_addr[i];
@@ -1590,6 +1600,7 @@
 #if defined(__FreeBSD__) && __FreeBSD__ >= 3
     char           *sysctl_buf;
     struct xinpgen *xig, *oxig;
+    struct xtcpcb *xp;
 #endif                          /* defined(__FreeBSD__) && __FreeBSD__ >= 3 */
 
     if (!initialized) {
@@ -1646,11 +1657,7 @@
         DEBUGMSGTL(("mibII/ipv6", "looping: p=%x\n", p));
 
 #if !(defined(__FreeBSD__) && __FreeBSD__ >= 3)
-        if (klookup((u_long) p, (char *) &in6pcb, sizeof(in6pcb)) < 0)
-#else
-        in6pcb = ((struct xinpcb *) xig)->xi_inp;
-#endif
-        {
+        if (klookup((u_long) p, (char *) &in6pcb, sizeof(in6pcb)) < 0) {
             DEBUGMSGTL(("mibII/ipv6", "klookup fail for in6pcb at %x\n",
                         p));
             break;
@@ -1662,6 +1669,14 @@
                         in6pcb.in6p_ppcb));
             break;
         }
+#else
+        in6pcb = ((struct xinpcb *) xig)->xi_inp;
+	xp = (struct xtcpcb *)xig;
+	tcp6cb = xp->xt_tp;
+	if (!(in6pcb.inp_vflag & 0x02)) { /* Skip non-IPv6 pcb */
+	  goto skip;
+	}
+#endif
         j = (int) vp->namelen;
         for (i = 0; i < sizeof(struct in6_addr); i++)
             newname[j++] = in6pcb.in6p_laddr.s6_addr[i];
