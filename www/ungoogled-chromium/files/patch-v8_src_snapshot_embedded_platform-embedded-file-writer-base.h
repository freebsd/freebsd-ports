--- v8/src/snapshot/embedded/platform-embedded-file-writer-base.h.orig	2025-12-06 13:30:52 UTC
+++ v8/src/snapshot/embedded/platform-embedded-file-writer-base.h
@@ -37,6 +37,7 @@ enum class EmbeddedTargetOs {
   kWin,
   kStarboard,
   kZOS,
+  kOpenBSD,
   kGeneric,  // Everything not covered above falls in here.
 };
 
