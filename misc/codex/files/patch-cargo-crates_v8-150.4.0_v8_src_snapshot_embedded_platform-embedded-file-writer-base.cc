--- cargo-crates/v8-150.4.0/v8/src/snapshot/embedded/platform-embedded-file-writer-base.cc.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/v8-150.4.0/v8/src/snapshot/embedded/platform-embedded-file-writer-base.cc
@@ -150,6 +150,8 @@ EmbeddedTargetOs ToEmbeddedTargetOs(const char* s) {
     return EmbeddedTargetOs::kStarboard;
   } else if (string == "zos") {
     return EmbeddedTargetOs::kZOS;
+  } else if (string == "openbsd") {
+    return EmbeddedTargetOs::kOpenBSD;
   } else {
     return EmbeddedTargetOs::kGeneric;
   }
