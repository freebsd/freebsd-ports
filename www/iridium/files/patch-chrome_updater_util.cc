--- chrome/updater/util.cc.orig	2022-12-06 08:09:13 UTC
+++ chrome/updater/util.cc
@@ -37,7 +37,7 @@
 #include "third_party/abseil-cpp/absl/types/optional.h"
 #include "url/gurl.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/updater/linux/linux_util.h"
 #elif BUILDFLAG(IS_MAC)
 #import "chrome/updater/mac/mac_util.h"
@@ -118,7 +118,7 @@ absl::optional<base::FilePath> GetBaseDataDirectory(Up
   app_data_dir = GetApplicationDataDirectory(scope);
 #elif BUILDFLAG(IS_MAC)
   app_data_dir = GetApplicationSupportDirectory(scope);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   app_data_dir = GetApplicationDataDirectory(scope);
 #endif
   if (!app_data_dir) {
