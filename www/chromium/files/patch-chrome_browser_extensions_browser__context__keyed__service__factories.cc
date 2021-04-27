--- chrome/browser/extensions/browser_context_keyed_service_factories.cc.orig	2021-04-14 18:40:53 UTC
+++ chrome/browser/extensions/browser_context_keyed_service_factories.cc
@@ -54,7 +54,7 @@
 #include "extensions/browser/api/networking_private/networking_private_delegate_factory.h"
 #include "ppapi/buildflags/buildflags.h"
 
-#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 #include "chrome/browser/extensions/api/input_ime/input_ime_api.h"
 #endif
 
