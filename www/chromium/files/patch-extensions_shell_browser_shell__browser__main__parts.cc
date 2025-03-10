--- extensions/shell/browser/shell_browser_main_parts.cc.orig	2025-01-15 09:18:26 UTC
+++ extensions/shell/browser/shell_browser_main_parts.cc
@@ -137,7 +137,7 @@ void ShellBrowserMainParts::PostCreateMainMessageLoop(
       switches::kAppShellAllowRoaming)) {
     network_controller_->SetCellularAllowRoaming(true);
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // app_shell doesn't need GTK, so the fake input method context can work.
   // See crbug.com/381852 and revision fb69f142.
   // TODO(michaelpg): Verify this works for target environments.
