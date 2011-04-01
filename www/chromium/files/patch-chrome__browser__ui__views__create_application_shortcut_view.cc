--- ./chrome/browser/ui/views/create_application_shortcut_view.cc.orig	2010-12-16 02:11:56.000000000 +0100
+++ ./chrome/browser/ui/views/create_application_shortcut_view.cc	2010-12-20 20:15:08.000000000 +0100
@@ -260,7 +260,7 @@
         l10n_util::GetString(IDS_PIN_TO_TASKBAR_CHKBOX) :
         l10n_util::GetString(IDS_CREATE_SHORTCUTS_QUICK_LAUNCH_BAR_CHKBOX),
       profile_->GetPrefs()->GetBoolean(prefs::kWebAppCreateInQuickLaunchBar));
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
   menu_check_box_ = AddCheckbox(
       l10n_util::GetString(IDS_CREATE_SHORTCUTS_MENU_CHKBOX),
       profile_->GetPrefs()->GetBoolean(prefs::kWebAppCreateInAppsMenu));
