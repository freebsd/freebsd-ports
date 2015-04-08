--- lib/netdev-bsd.c.orig	2015-04-08 13:49:06.863643000 +0800
+++ lib/netdev-bsd.c	2015-04-08 13:50:53.973989000 +0800
@@ -1771,7 +1771,7 @@
 ifr_get_flags(const struct ifreq *ifr)
 {
 #ifdef HAVE_STRUCT_IFREQ_IFR_FLAGSHIGH
-    return (ifr->ifr_flagshigh << 16) | ifr->ifr_flags;
+    return (ifr->ifr_flagshigh << 16) | (ifr->ifr_flags & 0xffff);
 #else
     return ifr->ifr_flags;
 #endif
@@ -1780,9 +1780,11 @@
 static void
 ifr_set_flags(struct ifreq *ifr, int flags)
 {
-    ifr->ifr_flags = flags;
 #ifdef HAVE_STRUCT_IFREQ_IFR_FLAGSHIGH
+    ifr->ifr_flags = flags & 0xffff;
     ifr->ifr_flagshigh = flags >> 16;
+#else
+    ifr->ifr_flags = flags;
 #endif
 }
 
