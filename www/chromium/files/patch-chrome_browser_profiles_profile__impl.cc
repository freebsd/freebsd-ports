--- chrome/browser/profiles/profile_impl.cc.orig	2022-07-22 17:30:31 UTC
+++ chrome/browser/profiles/profile_impl.cc
@@ -259,6 +259,10 @@
 #include "chrome/browser/spellchecker/spellcheck_service.h"
 #endif
 
+#if BUILDFLAG(IS_OPENBSD)
+#include "sandbox/policy/openbsd/sandbox_openbsd.h"
+#endif
+
 using bookmarks::BookmarkModel;
 using content::BrowserThread;
 using content::DownloadManagerDelegate;
@@ -847,7 +851,17 @@ void ProfileImpl::DoFinalInit(CreateMode create_mode) 
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
