--- chrome/browser/ui/webui/management/management_ui_handler.cc.orig	2023-06-05 19:39:05 UTC
+++ chrome/browser/ui/webui/management/management_ui_handler.cc
@@ -171,7 +171,7 @@ enum class ReportingType {
   kUserActivity
 };
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kManagementScreenCaptureEvent[] = "managementScreenCaptureEvent";
 const char kManagementScreenCaptureData[] = "managementScreenCaptureData";
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
@@ -967,7 +967,7 @@ base::Value::Dict ManagementUIHandler::GetThreatProtec
                                   &info);
   }
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (capture_policy::IsGetDisplayMediaSetSelectAllScreensAllowedForAnySite(
           profile)) {
     AddThreatProtectionPermission(kManagementScreenCaptureEvent,
