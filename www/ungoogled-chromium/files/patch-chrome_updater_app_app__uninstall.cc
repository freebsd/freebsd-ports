--- chrome/updater/app/app_uninstall.cc.orig	2025-09-10 13:22:16 UTC
+++ chrome/updater/app/app_uninstall.cc
@@ -181,7 +181,7 @@ void UninstallInThreadPool(UpdaterScope scope,
             }
             if (int result = UninstallOtherVersions(scope);
                 result != kErrorOk) {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
               // TODO(crbug.com/366249606): Ignores the errors when uninstalls
               // the other versions, because currently older Linux updater on
               // CIPD exits with error `kErrorFailedToDeleteFolder`.
