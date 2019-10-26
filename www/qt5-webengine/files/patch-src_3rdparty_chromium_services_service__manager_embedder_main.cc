--- src/3rdparty/chromium/services/service_manager/embedder/main.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/services/service_manager/embedder/main.cc
@@ -322,7 +322,7 @@ int Main(const MainParams& params) {
     base::EnableTerminationOnOutOfMemory();
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // The various desktop environments set this environment variable that
     // allows the dbus client library to connect directly to the bus. When this
     // variable is not set (test environments like xvfb-run), the dbus client
