--- chrome/browser/profiles/profile_impl.cc.orig	2024-03-22 14:16:19 UTC
+++ chrome/browser/profiles/profile_impl.cc
@@ -265,6 +265,10 @@
 #include "chrome/browser/spellchecker/spellcheck_service.h"
 #endif
 
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#endif
+
 using bookmarks::BookmarkModel;
 using content::BrowserThread;
 using content::DownloadManagerDelegate;
@@ -596,7 +600,7 @@ void ProfileImpl::LoadPrefsForNormalStartup(bool async
 #else
   {
 #endif  // BUILDFLAG(IS_CHROMEOS_LACROS)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     ProfileManager* profile_manager = g_browser_process->profile_manager();
     ProfileAttributesEntry* entry =
         profile_manager->GetProfileAttributesStorage()
@@ -873,7 +877,17 @@ void ProfileImpl::DoFinalInit(CreateMode create_mode) 
 }
 
 base::FilePath ProfileImpl::last_selected_directory() {
+#if BUILDFLAG(IS_OPENBSD)
+  // If unveil(2) is used, force the file dialog directory to something we
+  // know is available.
+  auto* sandbox = sandbox::policy::SandboxLinux::GetInstance();
+  if (sandbox->unveil_initialized())
+    return GetPrefs()->GetFilePath(prefs::kDownloadDefaultDirectory);
+  else
+    return GetPrefs()->GetFilePath(prefs::kSelectFileLastDirectory);
+#else
   return GetPrefs()->GetFilePath(prefs::kSelectFileLastDirectory);
+#endif
 }
 
 void ProfileImpl::set_last_selected_directory(const base::FilePath& path) {
