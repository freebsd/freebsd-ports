--- sandbox/policy/features.cc.orig	2026-01-16 13:40:34 UTC
+++ sandbox/policy/features.cc
@@ -154,7 +154,7 @@ bool IsNetworkSandboxSupported() {
 #endif  // BUILDFLAG(IS_WIN)
 
 bool IsNetworkSandboxEnabled() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   return true;
 #else
 #if BUILDFLAG(IS_WIN)
