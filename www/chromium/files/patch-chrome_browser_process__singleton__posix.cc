--- chrome/browser/process_singleton_posix.cc.orig	2017-06-05 19:03:02 UTC
+++ chrome/browser/process_singleton_posix.cc
@@ -93,11 +93,11 @@
 #include "net/base/network_interfaces.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/ui/process_singleton_dialog_linux.h"
 #endif
 
-#if defined(TOOLKIT_VIEWS) && defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(TOOLKIT_VIEWS) && (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #include "ui/views/linux_ui/linux_ui.h"
 #endif
 
@@ -322,7 +322,7 @@ bool DisplayProfileInUseError(const base::FilePath& lo
   if (g_disable_prompt)
     return false;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   base::string16 relaunch_button_text = l10n_util::GetStringUTF16(
       IDS_PROFILE_IN_USE_LINUX_RELAUNCH);
   return ShowProcessSingletonDialog(error, relaunch_button_text);
@@ -866,7 +866,7 @@ ProcessSingleton::NotifyResult ProcessSingleton::Notif
     // The other process is shutting down, it's safe to start a new process.
     return PROCESS_NONE;
   } else if (strncmp(buf, kACKToken, arraysize(kACKToken) - 1) == 0) {
-#if defined(TOOLKIT_VIEWS) && defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(TOOLKIT_VIEWS) && (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
     // Likely NULL in unit tests.
     views::LinuxUI* linux_ui = views::LinuxUI::instance();
     if (linux_ui)
