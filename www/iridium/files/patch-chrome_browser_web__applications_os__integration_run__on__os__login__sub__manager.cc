--- chrome/browser/web_applications/os_integration/run_on_os_login_sub_manager.cc.orig	2026-04-15 12:07:04 UTC
+++ chrome/browser/web_applications/os_integration/run_on_os_login_sub_manager.cc
@@ -54,7 +54,7 @@ proto::os_state::RunOnOsLogin::Mode ConvertWebAppRunOn
 // different from other platforms, see web_app_run_on_os_login_manager.h for
 // more info.
 bool DoesRunOnOsLoginRequireExecution() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
