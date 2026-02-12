--- sql/database.cc.orig	2026-02-11 09:05:39 UTC
+++ sql/database.cc
@@ -112,7 +112,7 @@ bool FilePathIsFixedSSD(const base::FilePath& path) {
 
   return !drive_info->has_seek_penalty.value_or(false)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
          && !drive_info->is_removable.value_or(false)
 #endif
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
