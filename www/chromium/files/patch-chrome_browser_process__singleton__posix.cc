--- chrome/browser/process_singleton_posix.cc.orig	2021-04-14 18:40:54 UTC
+++ chrome/browser/process_singleton_posix.cc
@@ -95,12 +95,12 @@
 #include "net/base/network_interfaces.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "chrome/browser/ui/process_singleton_dialog_linux.h"
 #endif
 
 #if defined(TOOLKIT_VIEWS) && \
-    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD))
 #include "ui/views/linux_ui/linux_ui.h"
 #endif
 
@@ -297,7 +297,7 @@ bool DisplayProfileInUseError(const base::FilePath& lo
   if (g_disable_prompt)
     return g_user_opted_unlock_in_use_profile;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   base::string16 relaunch_button_text = l10n_util::GetStringUTF16(
       IDS_PROFILE_IN_USE_LINUX_RELAUNCH);
   return ShowProcessSingletonDialog(error, relaunch_button_text);
@@ -874,7 +874,7 @@ ProcessSingleton::NotifyResult ProcessSingleton::Notif
     return PROCESS_NONE;
   } else if (strncmp(buf, kACKToken, base::size(kACKToken) - 1) == 0) {
 #if defined(TOOLKIT_VIEWS) && \
-    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD))
     // Likely NULL in unit tests.
     views::LinuxUI* linux_ui = views::LinuxUI::instance();
     if (linux_ui)
