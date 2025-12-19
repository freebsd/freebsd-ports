--- src/3rdparty/chromium/chrome/common/extensions/extension_constants.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/chrome/common/extensions/extension_constants.h
@@ -332,7 +332,7 @@ inline constexpr base::FilePath::CharType
     kReadingModeGDocsHelperManifestFilename[] =
         FILE_PATH_LITERAL("reading_mode_gdocs_helper_manifest.json");
 #endif  // !BUILDFLAG(IS_CHROMEOS_LACROS)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 // The extension id of the google tts engine extension to use on-device natural
 // Google voices.
 inline constexpr char kTTSEngineExtensionId[] =
