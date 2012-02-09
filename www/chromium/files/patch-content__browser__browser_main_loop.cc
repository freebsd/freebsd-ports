--- content/browser/browser_main_loop.cc.orig	2012-01-30 22:18:23.000000000 +0200
+++ content/browser/browser_main_loop.cc	2012-01-30 22:19:06.000000000 +0200
@@ -39,7 +39,7 @@
 #include "net/base/winsock_init.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <glib-object.h>
 #endif
 
@@ -89,7 +89,7 @@
 }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 static void GLibLogHandler(const gchar* log_domain,
                            GLogLevelFlags log_level,
                            const gchar* message,
@@ -518,7 +518,7 @@
   // are no #else branches on any #ifs.
   // TODO(stevenjb): Move platform specific code into platform specific Parts
   // (Need to add InitializeToolkit stage to BrowserParts).
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Glib type system initialization. Needed at least for gconf,
   // used in net/proxy/proxy_config_service_linux.cc. Most likely
   // this is superfluous as gtk_init() ought to do this. It's
