--- services/catalog/public/cpp/manifest_parsing_util.cc.orig	2017-09-05 21:05:23.000000000 +0200
+++ services/catalog/public/cpp/manifest_parsing_util.cc	2017-09-06 21:09:16.599702000 +0200
@@ -17,7 +17,8 @@
          name == Store::kRequiredFilesKey_PlatformValue_Linux ||
          name == Store::kRequiredFilesKey_PlatformValue_MacOSX ||
          name == Store::kRequiredFilesKey_PlatformValue_Android ||
-         name == Store::kRequiredFilesKey_PlatformValue_Fuchsia;
+         name == Store::kRequiredFilesKey_PlatformValue_Fuchsia ||
+         name == Store::kRequiredFilesKey_PlatformValue_FreeBSD;
 }
 
 bool IsCurrentPlatform(const std::string& name) {
@@ -31,6 +32,8 @@
   return name == Store::kRequiredFilesKey_PlatformValue_Android;
 #elif defined(OS_FUCHSIA)
   return name == Store::kRequiredFilesKey_PlatformValue_Fuchsia;
+#elif defined(OS_BSD)
+  return name == Store::kRequiredFilesKey_PlatformValue_FreeBSD;
 #else
 #error This architecture is not supported.
 #endif
