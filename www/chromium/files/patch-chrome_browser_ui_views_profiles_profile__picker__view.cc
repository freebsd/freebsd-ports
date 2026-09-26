--- chrome/browser/ui/views/profiles/profile_picker_view.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/ui/views/profiles/profile_picker_view.cc
@@ -90,7 +90,7 @@
 #include "chrome/browser/renderer_host/chrome_render_widget_host_view_mac_history_swiping_control.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/shell_integration_linux.h"
 #endif
 
