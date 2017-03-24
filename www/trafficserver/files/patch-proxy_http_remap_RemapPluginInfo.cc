--- proxy/http/remap/RemapPluginInfo.cc.orig	2016-07-11 23:03:32 UTC
+++ proxy/http/remap/RemapPluginInfo.cc
@@ -39,7 +39,7 @@ remap_plugin_info::remap_plugin_info(cha
 {
   // coverity did not see ats_free
   // coverity[ctor_dtor_leak]
-  if (_path && likely((path = ats_strdup(_path)) > 0))
+  if (_path && likely((path = ats_strdup(_path)) != NULL))
     path_size = strlen(path);
 }
 
