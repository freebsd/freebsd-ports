--- chrome/browser/ui/webui/management/management_ui_handler.cc.orig	2023-07-21 09:49:17 UTC
+++ chrome/browser/ui/webui/management/management_ui_handler.cc
@@ -171,7 +171,7 @@ enum class ReportingType {
   kUserActivity
 };
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kManagementScreenCaptureEvent[] = "managementScreenCaptureEvent";
 const char kManagementScreenCaptureData[] = "managementScreenCaptureData";
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
@@ -966,7 +966,7 @@ base::Value::Dict ManagementUIHandler::GetThreatProtec
                                   &info);
   }
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (capture_policy::IsGetAllScreensMediaAllowedForAnySite(profile)) {
     AddThreatProtectionPermission(kManagementScreenCaptureEvent,
                                   kManagementScreenCaptureData, &info);
