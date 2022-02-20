--- chrome/browser/profiles/profile_impl.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/profiles/profile_impl.cc
@@ -181,6 +181,7 @@
 #include "services/preferences/public/mojom/preferences.mojom.h"
 #include "services/preferences/public/mojom/tracked_preference_validation_delegate.mojom.h"
 #include "services/service_manager/public/cpp/service.h"
+#include "sandbox/policy/switches.h"
 #include "ui/base/l10n/l10n_util.h"
 
 #if BUILDFLAG(IS_CHROMEOS_ASH)
@@ -846,7 +847,13 @@ void ProfileImpl::DoFinalInit(CreateMode create_mode) 
 }
 
 base::FilePath ProfileImpl::last_selected_directory() {
-  return GetPrefs()->GetFilePath(prefs::kSelectFileLastDirectory);
+  // If unveil(2) is used, force the file dialog directory to something we
+  // know is available.
+  base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
+  if (!command_line->HasSwitch(sandbox::policy::switches::kDisableUnveil))
+    return GetPrefs()->GetFilePath(prefs::kDownloadDefaultDirectory);
+  else
+    return GetPrefs()->GetFilePath(prefs::kSelectFileLastDirectory);
 }
 
 void ProfileImpl::set_last_selected_directory(const base::FilePath& path) {
