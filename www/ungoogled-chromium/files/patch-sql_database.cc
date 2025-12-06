--- sql/database.cc.orig	2025-12-06 13:30:52 UTC
+++ sql/database.cc
@@ -106,7 +106,7 @@ bool FilePathIsFixedSSD(const base::FilePath& path) {
 
   return !drive_info->has_seek_penalty.value_or(false)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
          && !drive_info->is_removable.value_or(false)
 #endif
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
