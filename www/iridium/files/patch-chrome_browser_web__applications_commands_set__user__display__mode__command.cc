--- chrome/browser/web_applications/commands/set_user_display_mode_command.cc.orig	2025-09-11 13:19:19 UTC
+++ chrome/browser/web_applications/commands/set_user_display_mode_command.cc
@@ -56,7 +56,7 @@ void SetUserDisplayModeCommand::StartWithLock(
     // OsIntegrationTestOverride can use the xdg install command to detect
     // install.
     SynchronizeOsOptions options;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     options.add_shortcut_to_desktop = true;
 #endif
     app_lock_->os_integration_manager().Synchronize(
