--- chrome/updater/util.cc.orig	2023-01-17 19:19:00 UTC
+++ chrome/updater/util.cc
@@ -36,7 +36,7 @@
 #include "third_party/abseil-cpp/absl/types/optional.h"
 #include "url/gurl.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/updater/linux/linux_util.h"
 #elif BUILDFLAG(IS_MAC)
 #import "chrome/updater/mac/mac_util.h"
@@ -119,7 +119,7 @@ absl::optional<base::FilePath> GetBaseDataDirectory(Up
   app_data_dir = GetApplicationDataDirectory(scope);
 #elif BUILDFLAG(IS_MAC)
   app_data_dir = GetApplicationSupportDirectory(scope);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   app_data_dir = GetApplicationDataDirectory(scope);
 #endif
   if (!app_data_dir) {
