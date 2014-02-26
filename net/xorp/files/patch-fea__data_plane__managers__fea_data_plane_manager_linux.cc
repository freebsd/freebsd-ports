--- ./fea/data_plane/managers/fea_data_plane_manager_linux.cc.orig	2011-03-16 21:27:48.000000000 +0000
+++ ./fea/data_plane/managers/fea_data_plane_manager_linux.cc	2014-02-26 21:17:13.000000000 +0000
@@ -71,8 +71,10 @@
 
 
 FeaDataPlaneManagerLinux::FeaDataPlaneManagerLinux(FeaNode& fea_node)
-    : FeaDataPlaneManager(fea_node, "Linux"),
-      _ifconfig_get_ioctl(NULL)
+    : FeaDataPlaneManager(fea_node, "Linux")
+#if defined(HAVE_PROC_LINUX) && defined(HAVE_IOCTL_SIOCGIFCONF) and !defined(HAVE_NETLINK_SOCKETS)
+      , _ifconfig_get_ioctl(NULL)
+#endif
 {
 }
 
