--- ui/gfx/render_text_api_fuzzer.cc.orig	2026-07-01 06:24:19 UTC
+++ ui/gfx/render_text_api_fuzzer.cc
@@ -24,7 +24,7 @@
 #include "base/test/test_support_android.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "third_party/test_fonts/fontconfig/fontconfig_util_linux.h"
 #endif
 
@@ -59,7 +59,7 @@ struct Environment {
 
     CHECK(base::i18n::InitializeICU());
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     test_fonts::SetUpFontconfig();
 #endif
     gfx::InitializeFonts();
