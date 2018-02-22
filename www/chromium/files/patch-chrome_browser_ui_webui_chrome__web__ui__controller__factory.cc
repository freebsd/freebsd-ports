--- chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc.orig	2017-12-15 02:04:11.000000000 +0100
+++ chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc	2017-12-24 02:53:23.421702000 +0100
@@ -179,7 +179,7 @@
 #include "chrome/browser/ui/webui/welcome_win10_ui.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 #include "chrome/browser/ui/webui/sandbox_internals_ui.h"
 #endif
 
@@ -284,13 +284,13 @@
 #if !defined(OS_ANDROID)
           || url.host_piece() == chrome::kChromeUITermsHost
 #endif
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX)
           || url.host_piece() == chrome::kChromeUILinuxProxyConfigHost
 #endif
 #if defined(OS_CHROMEOS)
           || url.host_piece() == chrome::kChromeUIOSCreditsHost
 #endif
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
           || url.host_piece() == chrome::kChromeUIDiscardsHost
 #endif
           );  // NOLINT
@@ -532,7 +532,7 @@
   if (url.host_piece() == chrome::kChromeUINaClHost)
     return &NewWebUI<NaClUI>;
 #endif
-#if (defined(OS_LINUX) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA)
+#if (defined(OS_LINUX) && defined(TOOLKIT_VIEWS)) || defined(USE_AURA) || defined(OS_BSD)
   if (url.host_piece() == chrome::kChromeUITabModalConfirmDialogHost)
     return &NewWebUI<ConstrainedWebDialogUI>;
 #endif
@@ -593,7 +593,7 @@
     return &NewWebUI<CastUI>;
   }
 #endif
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   if (url.host_piece() == chrome::kChromeUISandboxHost) {
     return &NewWebUI<SandboxInternalsUI>;
   }
