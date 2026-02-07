# https://github.com/snl-dakota/dakota/pull/195

--- src/PluginInterface.hpp.orig	2025-06-14 09:02:26 UTC
+++ src/PluginInterface.hpp
@@ -13,7 +13,7 @@
 #include "ApplicationInterface.hpp"
 #include "plugins/DakotaInterfaceAPI.hpp"
 
-#include <boost/shared_ptr.hpp> // blech
+#include <memory>
 
 
 namespace Dakota {
@@ -54,7 +54,7 @@ class PluginInterface: public ApplicationInterface (pr
   String pluginPath;
 
   /// the interface class loaded via plugin
-  boost::shared_ptr<DakotaPlugins::DakotaInterfaceAPI> pluginInterface;
+  std::shared_ptr<DakotaPlugins::DakotaInterfaceAPI> pluginInterface;
 
 
   /// list of drivers to perform core simulation mappings (can
