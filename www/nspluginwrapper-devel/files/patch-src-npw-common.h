--- src/npw-common.h.orig	2009-01-02 15:22:29.000000000 +0100
+++ src/npw-common.h	2009-11-10 09:58:34.000000000 +0100
@@ -115,7 +115,7 @@ npw_plugin_instance_is_valid(void *ptr)
 static inline NPW_PluginInstance *
 _npw_get_plugin_instance (NPP instance)
 {
-  return (NPW_PluginInstance *)instance->_NPW_INSTANCE_PRIVATE_DATA;
+  return instance ? (NPW_PluginInstance *)instance->_NPW_INSTANCE_PRIVATE_DATA : NULL;
 }
 
 static inline NPW_PluginInstance *
