--- src/3rdparty/chromium/content/app/content_main.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/content/app/content_main.cc
@@ -232,7 +232,7 @@ int RunContentProcess(const ContentMainParams& params,
     base::EnableTerminationOnOutOfMemory();
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     // The various desktop environments set this environment variable that
     // allows the dbus client library to connect directly to the bus. When this
     // variable is not set (test environments like xvfb-run), the dbus client
