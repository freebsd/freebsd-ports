--- chrome/browser/sessions/session_restore.cc.orig	2021-06-10 11:16:08 UTC
+++ chrome/browser/sessions/session_restore.cc
@@ -931,7 +931,7 @@ void SessionRestore::RestoreSessionAfterCrash(Browser*
 // On linux, apps can be restored without the proper app frame,
 // disabling restorations on linux for now. http://crbug.com/1199109
 #if BUILDFLAG(ENABLE_APP_SESSION_SERVICE)
-#if !defined(OS_MAC) && !defined(OS_LINUX)
+#if !defined(OS_MAC) && !defined(OS_LINUX) && !defined(OS_BSD)
   // Apps should always be restored on crash restore.
   behavior |= SessionRestore::RESTORE_APPS;
 #endif
