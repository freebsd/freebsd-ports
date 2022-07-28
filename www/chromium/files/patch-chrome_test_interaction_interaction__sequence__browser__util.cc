--- chrome/test/interaction/interaction_sequence_browser_util.cc.orig	2022-07-22 17:30:31 UTC
+++ chrome/test/interaction/interaction_sequence_browser_util.cc
@@ -52,7 +52,7 @@ class RenderFrameHost;
 
 namespace {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 #define SUPPORTS_PIXEL_TESTS 1
 #else
 #define SUPPORTS_PIXEL_TESTS 0
