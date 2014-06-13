--- ./zebra/kernel_socket.c.orig	2003-11-27 10:35:50.000000000 -0600
+++ ./zebra/kernel_socket.c	2014-06-13 12:53:05.553677585 -0500
@@ -58,8 +58,12 @@
   {RTM_REDIRECT, "RTM_REDIRECT"},
   {RTM_MISS,     "RTM_MISS"},
   {RTM_LOCK,     "RTM_LOCK"},
+#ifdef RTM_OLDADD
   {RTM_OLDADD,   "RTM_OLDADD"},
+#endif
+#ifdef RTM_OLDDEL
   {RTM_OLDDEL,   "RTM_OLDDEL"},
+#endif
   {RTM_RESOLVE,  "RTM_RESOLVE"},
   {RTM_NEWADDR,  "RTM_NEWADDR"},
   {RTM_DELADDR,  "RTM_DELADDR"},
@@ -91,9 +95,13 @@
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
@@ -593,9 +601,11 @@
   if (gate && message == RTM_ADD)
     msg.rtm.rtm_flags |= RTF_GATEWAY;
 
+#ifdef RTF_CLONING
   if (! gate && message == RTM_ADD && ifp &&
       (ifp->flags & IFF_POINTOPOINT) == 0)
     msg.rtm.rtm_flags |= RTF_CLONING;
+#endif */ RTF_CLONING */
 
   /* If no protocol specific gateway is specified, use link
      address for gateway. */
