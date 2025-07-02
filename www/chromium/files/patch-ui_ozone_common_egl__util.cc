--- ui/ozone/common/egl_util.cc.orig	2025-07-02 06:08:04 UTC
+++ ui/ozone/common/egl_util.cc
@@ -35,9 +35,9 @@ const base::FilePath::CharType kDefaultGlesSoname[] =
     FILE_PATH_LITERAL("libGLESv2.so");
 #else  // BUILDFLAG(IS_FUCHSIA)
 const base::FilePath::CharType kDefaultEglSoname[] =
-    FILE_PATH_LITERAL("libEGL.so.1");
+    FILE_PATH_LITERAL("libEGL.so");
 const base::FilePath::CharType kDefaultGlesSoname[] =
-    FILE_PATH_LITERAL("libGLESv2.so.2");
+    FILE_PATH_LITERAL("libGLESv2.so");
 #endif
 #if !BUILDFLAG(USE_STATIC_ANGLE)
 const base::FilePath::CharType kAngleEglSoname[] =
