--- content/browser/plugin_service_impl.cc.orig	2013-08-30 06:45:42.000000000 +0300
+++ content/browser/plugin_service_impl.cc	2013-09-03 22:45:55.464628229 +0300
@@ -790,7 +790,8 @@
 }
 
 bool PluginServiceImpl::NPAPIPluginsSupported() {
-#if defined(OS_WIN) || defined(OS_MACOSX) || (defined(OS_LINUX) && !defined(USE_AURA))
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD) || \
+    (defined(OS_LINUX) && !defined(USE_AURA))
   return true;
 #else
   return false;
