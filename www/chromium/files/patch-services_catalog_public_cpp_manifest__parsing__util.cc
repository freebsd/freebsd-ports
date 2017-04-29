--- services/catalog/public/cpp/manifest_parsing_util.cc.orig	2017-04-19 19:06:37 UTC
+++ services/catalog/public/cpp/manifest_parsing_util.cc
@@ -15,7 +15,8 @@ bool IsValidPlatformName(const std::stri
   return name == Store::kRequiredFilesKey_PlatformValue_Windows ||
          name == Store::kRequiredFilesKey_PlatformValue_Linux ||
          name == Store::kRequiredFilesKey_PlatformValue_MacOSX ||
-         name == Store::kRequiredFilesKey_PlatformValue_Android;
+         name == Store::kRequiredFilesKey_PlatformValue_Android ||
+         name == Store::kRequiredFilesKey_PlatformValue_FreeBSD;
 }
 
 bool IsCurrentPlatform(const std::string& name) {
@@ -27,6 +28,8 @@ bool IsCurrentPlatform(const std::string
   return name == Store::kRequiredFilesKey_PlatformValue_MacOSX;
 #elif defined(OS_ANDROID)
   return name == Store::kRequiredFilesKey_PlatformValue_Android;
+#elif defined(OS_BSD)
+  return name == Store::kRequiredFilesKey_PlatformValue_FreeBSD;
 #else
 #error This architecture is not supported.
 #endif
