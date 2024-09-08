--- v8/src/snapshot/embedded/platform-embedded-file-writer-base.h.orig	2024-08-27 06:28:16 UTC
+++ v8/src/snapshot/embedded/platform-embedded-file-writer-base.h
@@ -32,6 +32,7 @@ enum class EmbeddedTargetOs {
   kWin,
   kStarboard,
   kZOS,
+  kOpenBSD,
   kGeneric,  // Everything not covered above falls in here.
 };
 
