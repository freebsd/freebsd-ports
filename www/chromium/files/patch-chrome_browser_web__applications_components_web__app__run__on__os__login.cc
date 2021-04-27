--- chrome/browser/web_applications/components/web_app_run_on_os_login.cc.orig	2021-04-14 18:40:56 UTC
+++ chrome/browser/web_applications/components/web_app_run_on_os_login.cc
@@ -34,7 +34,7 @@ namespace internals {
 
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if !(defined(OS_WIN) || defined(OS_MAC) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)))
+#if !(defined(OS_WIN) || defined(OS_MAC) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD))
 // This boilerplate function is used for platforms that don't support Run On OS
 // Login. Currently the feature is supported on Windows, Linux and MacOS.
 bool RegisterRunOnOsLogin(const ShortcutInfo& shortcut_info) {
