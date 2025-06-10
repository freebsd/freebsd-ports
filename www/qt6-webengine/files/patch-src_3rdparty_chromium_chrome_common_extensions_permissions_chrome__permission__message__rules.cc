--- src/3rdparty/chromium/chrome/common/extensions/permissions/chrome_permission_message_rules.cc.orig	2025-02-21 12:29:33 UTC
+++ src/3rdparty/chromium/chrome/common/extensions/permissions/chrome_permission_message_rules.cc
@@ -287,7 +287,7 @@ int GetEnterpriseReportingPrivatePermissionMessageId()
 #endif
 #if BUILDFLAG(IS_WIN)
   return IDS_EXTENSION_PROMPT_WARNING_ENTERPRISE_REPORTING_PRIVATE_ENABLED_WIN;
-#elif BUILDFLAG(IS_LINUX) or BUILDFLAG(IS_MAC)
+#elif BUILDFLAG(IS_LINUX) or BUILDFLAG(IS_MAC) or BUILDFLAG(IS_BSD)
   return IDS_EXTENSION_PROMPT_WARNING_ENTERPRISE_REPORTING_PRIVATE_ENABLED_LINUX_AND_MACOS;
 #else
   return IDS_EXTENSION_PROMPT_WARNING_ENTERPRISE_REPORTING_PRIVATE;
