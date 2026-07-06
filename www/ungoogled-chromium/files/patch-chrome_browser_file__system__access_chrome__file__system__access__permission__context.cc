--- chrome/browser/file_system_access/chrome_file_system_access_permission_context.cc.orig	2026-06-05 13:45:06 UTC
+++ chrome/browser/file_system_access/chrome_file_system_access_permission_context.cc
@@ -412,7 +412,7 @@ GenerateBlockPaths(bool should_normalize_file_path) {
           FILE_PATH_LITERAL("Library/Mobile Documents/com~apple~CloudDocs"),
           BlockType::kDontBlockChildren),
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
       // On Linux also block access to devices via /dev.
       BlockPath::CreateAbsolute(FILE_PATH_LITERAL("/dev"),
                                 BlockType::kBlockAllChildren),
