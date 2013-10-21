diff --git a/sysdep/bsd/krt-sock.c b/sysdep/bsd/krt-sock.c
index 08dfccc..3d30036 100644
--- sysdep/bsd/krt-sock.c
+++ sysdep/bsd/krt-sock.c
@@ -676,22 +676,18 @@ krt_read_addr(struct ks_msg *msg)
 
 #ifdef IPV6
   /* Clean up embedded interface ID returned in link-local address */
+
   if (ipa_has_link_scope(ifa.ip))
     _I0(ifa.ip) = 0xfe800000;
-#endif
 
-#ifdef IPV6
-  /* Why not the same check also for IPv4? */
-  if ((iface->flags & IF_MULTIACCESS) || (masklen != BITS_PER_IP_ADDRESS))
-#else
-  if (iface->flags & IF_MULTIACCESS)
+  if (ipa_has_link_scope(ifa.brd))
+    _I0(ifa.brd) = 0xfe800000;
 #endif
+
+  if (masklen < BITS_PER_IP_ADDRESS)
   {
     ifa.prefix = ipa_and(ifa.ip, ipa_mkmask(masklen));
 
-    if (masklen == BITS_PER_IP_ADDRESS)
-      ifa.flags |= IA_HOST;
-
     if (masklen == (BITS_PER_IP_ADDRESS - 1))
       ifa.opposite = ipa_opposite_m1(ifa.ip);
 
@@ -699,11 +695,19 @@ krt_read_addr(struct ks_msg *msg)
     if (masklen == (BITS_PER_IP_ADDRESS - 2))
       ifa.opposite = ipa_opposite_m2(ifa.ip);
 #endif
+
+    if (!(iface->flags & IF_MULTIACCESS))
+      ifa.opposite = ifa.brd;
   }
-  else         /* PtP iface */
+  else if (!(iface->flags & IF_MULTIACCESS) && ipa_nonzero(ifa.brd))
   {
-    ifa.flags |= IA_PEER;
     ifa.prefix = ifa.opposite = ifa.brd;
+    ifa.flags |= IA_PEER;
+  }
+  else
+  {
+    ifa.prefix = ifa.ip;
+    ifa.flags |= IA_HOST;
   }
 
   if (new)
