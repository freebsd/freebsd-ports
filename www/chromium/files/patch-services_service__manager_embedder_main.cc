--- services/service_manager/embedder/main.cc.orig	2019-01-09 13:16:40.515216000 +0100
+++ services/service_manager/embedder/main.cc	2019-01-09 13:17:09.817906000 +0100
@@ -331,7 +331,7 @@
 #endif
     base::EnableTerminationOnOutOfMemory();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // The various desktop environments set this environment variable that
     // allows the dbus client library to connect directly to the bus. When this
     // variable is not set (test environments like xvfb-run), the dbus client
