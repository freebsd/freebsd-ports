--- ./fea/data_plane/managers/fea_data_plane_manager_linux.hh.orig	2011-03-16 21:27:48.000000000 +0000
+++ ./fea/data_plane/managers/fea_data_plane_manager_linux.hh	2014-02-26 21:17:13.000000000 +0000
@@ -118,10 +118,10 @@
      * @return the @ref IfConfigGetIoctl plugin.
      */
     IfConfigGetIoctl* ifconfig_get_ioctl() { return (_ifconfig_get_ioctl); }
-#endif
 
 private:
     IfConfigGetIoctl*	_ifconfig_get_ioctl;
+#endif
 };
 
 #endif // __FEA_DATA_PLANE_MANAGERS_FEA_DATA_PLANE_MANAGER_LINUX_HH__
