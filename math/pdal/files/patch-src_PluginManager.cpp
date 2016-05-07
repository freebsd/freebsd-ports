--- src/PluginManager.cpp.orig	2015-11-25 18:45:33 UTC
+++ src/PluginManager.cpp
@@ -58,7 +58,7 @@ namespace
 {
 #if defined(__APPLE__) && defined(__MACH__)
     const std::string dynamicLibraryExtension(".dylib");
-#elif defined __linux__
+#elif defined __linux__ || defined __FreeBSD__ || defined __DragonFly__
     const std::string dynamicLibraryExtension(".so");
 #elif defined _WIN32
     const std::string dynamicLibraryExtension(".dll");
