--- v8/src/snapshot/embedded/platform-embedded-file-writer-base.h.orig	2023-03-13 07:33:08 UTC
+++ v8/src/snapshot/embedded/platform-embedded-file-writer-base.h
@@ -31,6 +31,7 @@ enum class EmbeddedTargetOs {
   kMac,
   kWin,
   kStarboard,
+  kOpenBSD,
   kGeneric,  // Everything not covered above falls in here.
 };
 
