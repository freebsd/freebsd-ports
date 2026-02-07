--- chrome/common/extensions/extension_constants.h.orig	2025-09-10 13:22:16 UTC
+++ chrome/common/extensions/extension_constants.h
@@ -313,7 +313,7 @@ inline constexpr char kReadingModeGDocsHelperExtension
 inline constexpr base::FilePath::CharType
     kReadingModeGDocsHelperManifestFilename[] =
         FILE_PATH_LITERAL("reading_mode_gdocs_helper_manifest.json");
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 // The extension id of the google tts engine extension to use on-device natural
 // Google voices.
 inline constexpr char kTTSEngineExtensionId[] =
