--- chrome/browser/enterprise/connectors/reporting/browser_crash_event_router.cc.orig	2022-09-24 10:57:32 UTC
+++ chrome/browser/enterprise/connectors/reporting/browser_crash_event_router.cc
@@ -18,14 +18,14 @@
 #include "chrome/common/chrome_paths.h"
 #include "components/version_info/version_info.h"
 
-#if !BUILDFLAG(IS_FUCHSIA)
+#if !BUILDFLAG(IS_FUCHSIA) && !BUILDFLAG(IS_BSD)
 #include "components/crash/core/app/crashpad.h"
 #include "third_party/crashpad/crashpad/client/crash_report_database.h"
 #endif  // !BUILDFLAG(IS_FUCHSIA)
 
 namespace enterprise_connectors {
 
-#if !BUILDFLAG(IS_FUCHSIA)
+#if !BUILDFLAG(IS_FUCHSIA) && !BUILDFLAG(IS_BSD)
 namespace {
 // key names used when building the dictionary to pass to the real-time
 // reporting API
