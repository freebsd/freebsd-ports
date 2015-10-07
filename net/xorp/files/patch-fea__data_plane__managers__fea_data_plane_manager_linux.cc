--- fea/data_plane/managers/fea_data_plane_manager_linux.cc.orig	2012-01-11 17:56:10 UTC
+++ fea/data_plane/managers/fea_data_plane_manager_linux.cc
@@ -71,8 +71,10 @@ extern "C" void destroy(FeaDataPlaneMana
 
 
 FeaDataPlaneManagerLinux::FeaDataPlaneManagerLinux(FeaNode& fea_node)
-    : FeaDataPlaneManager(fea_node, "Linux"),
-      _ifconfig_get_ioctl(NULL)
+    : FeaDataPlaneManager(fea_node, "Linux")
+#if defined(HAVE_PROC_LINUX) && defined(HAVE_IOCTL_SIOCGIFCONF) and !defined(HAVE_NETLINK_SOCKETS)
+      , _ifconfig_get_ioctl(NULL)
+#endif
 {
 }
 
