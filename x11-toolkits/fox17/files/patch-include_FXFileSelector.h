Disengage FXPathBox. This is an experimental replacement for FXDirBox, but
audio/gogglesmm is not ready for it and as an experimental feature, should
not be enabled by default.

--- include/FXFileSelector.h.orig	2025-11-12 04:54:22 UTC
+++ include/FXFileSelector.h
@@ -53,8 +53,6 @@ enum {
   SELECTFILE_DIRECTORY        /// Existing directory, including '.' or '..'
   };
 
-#define PATHBOX 1
-
 /// File selection widget
 class FXAPI FXFileSelector : public FXPacker {
   FXDECLARE(FXFileSelector)
