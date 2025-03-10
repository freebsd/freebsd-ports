--- v8/src/snapshot/embedded/platform-embedded-file-writer-base.h.orig	2024-11-04 08:56:03 UTC
+++ v8/src/snapshot/embedded/platform-embedded-file-writer-base.h
@@ -36,6 +36,7 @@ enum class EmbeddedTargetOs {
   kWin,
   kStarboard,
   kZOS,
+  kOpenBSD,
   kGeneric,  // Everything not covered above falls in here.
 };
 
