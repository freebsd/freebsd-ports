--- chrome/browser/web_applications/commands/launch_web_app_command.cc.orig	2026-02-15 10:01:45 UTC
+++ chrome/browser/web_applications/commands/launch_web_app_command.cc
@@ -113,7 +113,7 @@ void LaunchWebAppCommand::StartWithLock(std::unique_pt
     // OsIntegrationTestOverride can use the xdg install command to detect
     // install.
     SynchronizeOsOptions options;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     options.add_shortcut_to_desktop = true;
 #endif
     lock_->os_integration_manager().Synchronize(
