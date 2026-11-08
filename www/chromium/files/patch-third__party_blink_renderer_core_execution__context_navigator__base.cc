--- third_party/blink/renderer/core/execution_context/navigator_base.cc.orig	2026-10-18 13:29:39 UTC
+++ third_party/blink/renderer/core/execution_context/navigator_base.cc
@@ -27,7 +27,7 @@ namespace blink {
 
 namespace {
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 constexpr char kLinuxX86_64[] = "Linux x86_64";
 #endif
 
@@ -47,7 +47,7 @@ String GetReducedNavigatorPlatform() {
   return "Win32";
 #elif BUILDFLAG(IS_FUCHSIA)
   return "";
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return kLinuxX86_64;
 #elif BUILDFLAG(IS_IOS)
   return "iPhone";
