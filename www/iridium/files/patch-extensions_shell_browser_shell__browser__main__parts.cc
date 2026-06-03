--- extensions/shell/browser/shell_browser_main_parts.cc.orig	2026-04-15 12:07:04 UTC
+++ extensions/shell/browser/shell_browser_main_parts.cc
@@ -126,7 +126,7 @@ void ShellBrowserMainParts::PostCreateMainMessageLoop(
       switches::kAppShellAllowRoaming)) {
     network_controller_->SetCellularAllowRoaming(true);
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // app_shell doesn't need GTK, so the fake input method context can work.
   // See crbug.com/40369323 and revision fb69f142.
   // TODO(michaelpg): Verify this works for target environments.
