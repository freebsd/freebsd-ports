--- zebra/kernel_socket.c.orig	2009-01-03 20:20:10.000000000 +0300
+++ zebra/kernel_socket.c	2009-01-03 20:22:37.000000000 +0300
@@ -173,9 +173,13 @@
 #ifdef RTF_MASK
   {RTF_MASK,      "MASK"},
 #endif /* RTF_MASK */
+#ifdef RTF_CLONING
   {RTF_CLONING,   "CLONING"},
+#endif /* RTF_CLONING */
   {RTF_XRESOLVE,  "XRESOLVE"},
+#ifdef RTF_LLINFO
   {RTF_LLINFO,    "LLINFO"},
+#endif /* RTF_LLINFO */
   {RTF_STATIC,    "STATIC"},
   {RTF_BLACKHOLE, "BLACKHOLE"},
 #ifdef RTF_PRIVATE
@@ -999,9 +1003,11 @@
   if (gate && message == RTM_ADD)
     msg.rtm.rtm_flags |= RTF_GATEWAY;
 
+#ifdef RTF_CLONING
   if (! gate && message == RTM_ADD && ifp &&
       (ifp->flags & IFF_POINTOPOINT) == 0)
     msg.rtm.rtm_flags |= RTF_CLONING;
+#endif */ RTF_CLONING */
 
   /* If no protocol specific gateway is specified, use link
      address for gateway. */
