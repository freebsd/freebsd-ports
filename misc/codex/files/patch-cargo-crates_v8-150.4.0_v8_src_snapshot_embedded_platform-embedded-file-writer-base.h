--- cargo-crates/v8-150.4.0/v8/src/snapshot/embedded/platform-embedded-file-writer-base.h.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/v8-150.4.0/v8/src/snapshot/embedded/platform-embedded-file-writer-base.h
@@ -37,6 +37,7 @@ enum class EmbeddedTargetOs {
   kWin,
   kStarboard,
   kZOS,
+  kOpenBSD,
   kGeneric,  // Everything not covered above falls in here.
 };
 
