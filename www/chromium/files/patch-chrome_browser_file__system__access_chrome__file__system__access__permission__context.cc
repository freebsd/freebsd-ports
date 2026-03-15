--- chrome/browser/file_system_access/chrome_file_system_access_permission_context.cc.orig	2026-03-13 06:02:14 UTC
+++ chrome/browser/file_system_access/chrome_file_system_access_permission_context.cc
@@ -399,7 +399,7 @@ GenerateBlockPaths(bool should_normalize_file_path) {
            FILE_PATH_LITERAL("Library/Mobile Documents/com~apple~CloudDocs"),
            BlockType::kDontBlockChildren},
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
           // On Linux also block access to devices via /dev.
           {kNoBasePathKey, FILE_PATH_LITERAL("/dev"),
            BlockType::kBlockAllChildren},
