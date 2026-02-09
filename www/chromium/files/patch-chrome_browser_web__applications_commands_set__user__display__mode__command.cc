--- chrome/browser/web_applications/commands/set_user_display_mode_command.cc.orig	2026-02-11 09:05:39 UTC
+++ chrome/browser/web_applications/commands/set_user_display_mode_command.cc
@@ -65,7 +65,7 @@ void SetUserDisplayModeCommand::StartWithLock(
     // OsIntegrationTestOverride can use the xdg install command to detect
     // install.
     SynchronizeOsOptions options;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     options.add_shortcut_to_desktop = true;
 #endif
     app_lock_->os_integration_manager().Synchronize(
