--- chrome/browser/ui/webui/management/management_ui_constants.h.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/ui/webui/management/management_ui_constants.h
@@ -9,7 +9,7 @@
 #include "build/build_config.h"
 #include "extensions/buildflags/buildflags.h"
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Constants defining the IDs for the localized strings sent to the page as
 // load time data.
 extern const char kManagementScreenCaptureEvent[];
