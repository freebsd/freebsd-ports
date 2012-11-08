--- content/browser/browser_main_loop.cc.orig	2012-10-31 21:01:35.000000000 +0200
+++ content/browser/browser_main_loop.cc	2012-11-07 15:40:53.000000000 +0200
@@ -61,7 +61,7 @@
 #include "net/base/winsock_init.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <glib-object.h>
 #endif
 
@@ -79,7 +79,7 @@
 #include "ui/gfx/gtk_util.h"
 #endif
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 #include <sys/stat.h>
 
 #include "base/process_util.h"
@@ -100,7 +100,7 @@
 
 namespace {
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 void SetupSandbox(const CommandLine& parsed_command_line) {
   // TODO(evanm): move this into SandboxWrapper; I'm just trying to move this
   // code en masse out of chrome_main for now.
@@ -128,7 +128,7 @@
 }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 static void GLibLogHandler(const gchar* log_domain,
                            GLogLevelFlags log_level,
                            const gchar* message,
@@ -286,7 +286,7 @@
   }
 #endif  // !defined(USE_OPENSSL)
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   SetupSandbox(parsed_command_line_);
 #endif
 
@@ -681,7 +681,7 @@
   // are no #else branches on any #ifs.
   // TODO(stevenjb): Move platform specific code into platform specific Parts
   // (Need to add InitializeToolkit stage to BrowserParts).
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Glib type system initialization. Needed at least for gconf,
   // used in net/proxy/proxy_config_service_linux.cc. Most likely
   // this is superfluous as gtk_init() ought to do this. It's
