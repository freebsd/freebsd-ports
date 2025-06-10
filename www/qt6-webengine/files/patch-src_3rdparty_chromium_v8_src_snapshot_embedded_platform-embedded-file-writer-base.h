--- src/3rdparty/chromium/v8/src/snapshot/embedded/platform-embedded-file-writer-base.h.orig	2024-09-30 07:45:04 UTC
+++ src/3rdparty/chromium/v8/src/snapshot/embedded/platform-embedded-file-writer-base.h
@@ -36,6 +36,7 @@ enum class EmbeddedTargetOs {
   kWin,
   kStarboard,
   kZOS,
+  kOpenBSD,
   kGeneric,  // Everything not covered above falls in here.
 };
 
