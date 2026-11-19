--- chrome/browser/ui/webui/management/management_ui_constants.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/ui/webui/management/management_ui_constants.cc
@@ -96,7 +96,7 @@ const char kProfileReportingExtension[] = "profileRepo
 const char kProfileReportingPolicy[] = "profileReportingPolicy";
 const char kProfileReportingLearnMore[] = "profileReportingLearnMore";
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kManagementScreenCaptureEvent[] = "managementScreenCaptureEvent";
 const char kManagementScreenCaptureData[] = "managementScreenCaptureData";
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
