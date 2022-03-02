--- extensions/shell/browser/shell_browser_main_parts.cc.orig	2022-02-28 16:54:41 UTC
+++ extensions/shell/browser/shell_browser_main_parts.cc
@@ -142,7 +142,7 @@ void ShellBrowserMainParts::PostCreateMainMessageLoop(
       switches::kAppShellAllowRoaming)) {
     network_controller_->SetCellularAllowRoaming(true);
   }
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   // app_shell doesn't need GTK, so the fake input method context can work.
   // See crbug.com/381852 and revision fb69f142.
   // TODO(michaelpg): Verify this works for target environments.
