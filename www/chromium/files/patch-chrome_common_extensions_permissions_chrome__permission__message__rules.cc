--- chrome/common/extensions/permissions/chrome_permission_message_rules.cc.orig	2022-08-31 12:19:35 UTC
+++ chrome/common/extensions/permissions/chrome_permission_message_rules.cc
@@ -284,7 +284,7 @@ int GetEnterpriseReportingPrivatePermissionMessageId()
   }
 #if BUILDFLAG(IS_WIN)
   return IDS_EXTENSION_PROMPT_WARNING_ENTERPRISE_REPORTING_PRIVATE_ENABLED_WIN;
-#elif BUILDFLAG(IS_LINUX) or BUILDFLAG(IS_MAC)
+#elif BUILDFLAG(IS_LINUX) or BUILDFLAG(IS_MAC) or BUILDFLAG(IS_BSD)
   return IDS_EXTENSION_PROMPT_WARNING_ENTERPRISE_REPORTING_PRIVATE_ENABLED_LINUX_AND_MACOS;
 #else
   return IDS_EXTENSION_PROMPT_WARNING_ENTERPRISE_REPORTING_PRIVATE;
