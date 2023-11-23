--- v8/src/snapshot/embedded/platform-embedded-file-writer-base.cc.orig	2023-11-22 14:00:11 UTC
+++ v8/src/snapshot/embedded/platform-embedded-file-writer-base.cc
@@ -143,6 +143,8 @@ EmbeddedTargetOs ToEmbeddedTargetOs(const char* s) {
     return EmbeddedTargetOs::kWin;
   } else if (string == "starboard") {
     return EmbeddedTargetOs::kStarboard;
+  } else if (string == "openbsd") {
+    return EmbeddedTargetOs::kOpenBSD;
   } else {
     return EmbeddedTargetOs::kGeneric;
   }
