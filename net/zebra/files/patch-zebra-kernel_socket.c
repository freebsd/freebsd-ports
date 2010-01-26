--- zebra/kernel_socket.c.orig	2003-11-28 01:35:50.000000000 +0900
+++ zebra/kernel_socket.c	2010-01-26 15:13:19.000000000 +0900
@@ -91,9 +91,13 @@
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
   {RTF_PROTO1,    "PROTO1"},
@@ -593,9 +597,11 @@
   if (gate && message == RTM_ADD)
     msg.rtm.rtm_flags |= RTF_GATEWAY;
 
+#ifdef RTF_CLONING
   if (! gate && message == RTM_ADD && ifp &&
       (ifp->flags & IFF_POINTOPOINT) == 0)
     msg.rtm.rtm_flags |= RTF_CLONING;
+#endif */ RTF_CLONING */
 
   /* If no protocol specific gateway is specified, use link
      address for gateway. */
