--- ui/gfx/render_text_fuzzer.cc.orig	2026-02-15 10:01:45 UTC
+++ ui/gfx/render_text_fuzzer.cc
@@ -18,7 +18,7 @@
 #include "ui/gfx/canvas.h"
 #include "ui/gfx/font_util.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "third_party/test_fonts/fontconfig/fontconfig_util_linux.h"
 #endif
 
@@ -41,7 +41,7 @@ struct Environment {
 
     CHECK(base::i18n::InitializeICU());
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     test_fonts::SetUpFontconfig();
 #endif
     gfx::InitializeFonts();
