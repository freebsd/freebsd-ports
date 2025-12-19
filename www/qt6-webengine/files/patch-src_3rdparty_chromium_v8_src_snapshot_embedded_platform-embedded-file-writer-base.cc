--- src/3rdparty/chromium/v8/src/snapshot/embedded/platform-embedded-file-writer-base.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/v8/src/snapshot/embedded/platform-embedded-file-writer-base.cc
@@ -148,6 +148,8 @@ EmbeddedTargetOs ToEmbeddedTargetOs(const char* s) {
     return EmbeddedTargetOs::kStarboard;
   } else if (string == "zos") {
     return EmbeddedTargetOs::kZOS;
+  } else if (string == "openbsd") {
+    return EmbeddedTargetOs::kOpenBSD;
   } else {
     return EmbeddedTargetOs::kGeneric;
   }
