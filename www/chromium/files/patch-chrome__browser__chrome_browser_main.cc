--- chrome/browser/chrome_browser_main.cc.orig	2015-10-13 15:04:31.000000000 -0400
+++ chrome/browser/chrome_browser_main.cc	2015-10-15 13:19:01.371935000 -0400
@@ -158,7 +158,7 @@
 #include "chrome/browser/feedback/feedback_profile_observer.h"
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 #include "chrome/browser/first_run/upgrade_util_linux.h"
 #include "chrome/browser/sxs_linux.h"
 #endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
@@ -1013,7 +1013,7 @@
   }
 #endif  // !defined(OS_ANDROID) && !defined(OS_CHROMEOS)
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_MACOSX)
   // Set the product channel for crash reports.
   base::debug::SetCrashKeyValue(crash_keys::kChannel,
                                 chrome::GetChannelString());
@@ -1349,7 +1349,7 @@
     return chrome::RESULT_CODE_MACHINE_LEVEL_INSTALL_EXISTS;
 #endif  // defined(OS_WIN)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   if (sxs_linux::ShouldMigrateUserDataDir())
     return sxs_linux::MigrateUserDataDir();
 #endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
