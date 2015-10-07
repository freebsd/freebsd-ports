--- fea/data_plane/managers/fea_data_plane_manager_linux.hh.orig	2012-01-11 17:56:10 UTC
+++ fea/data_plane/managers/fea_data_plane_manager_linux.hh
@@ -118,10 +118,10 @@ public:
      * @return the @ref IfConfigGetIoctl plugin.
      */
     IfConfigGetIoctl* ifconfig_get_ioctl() { return (_ifconfig_get_ioctl); }
-#endif
 
 private:
     IfConfigGetIoctl*	_ifconfig_get_ioctl;
+#endif
 };
 
 #endif // __FEA_DATA_PLANE_MANAGERS_FEA_DATA_PLANE_MANAGER_LINUX_HH__
