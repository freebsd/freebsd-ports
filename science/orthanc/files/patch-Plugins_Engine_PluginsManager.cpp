--- Plugins/Engine/PluginsManager.cpp.orig	2015-02-12 13:47:38 UTC
+++ Plugins/Engine/PluginsManager.cpp
@@ -42,7 +42,7 @@
 
 #ifdef WIN32
 #define PLUGIN_EXTENSION ".dll"
-#elif defined(__linux) || defined(__FreeBSD_kernel__)
+#elif defined(__linux) || defined(__FreeBSD_kernel__) || defined(__FreeBSD__)
 #define PLUGIN_EXTENSION ".so"
 #elif defined(__APPLE__) && defined(__MACH__)
 #define PLUGIN_EXTENSION ".dylib"
