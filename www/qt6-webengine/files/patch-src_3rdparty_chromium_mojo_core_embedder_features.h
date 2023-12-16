--- src/3rdparty/chromium/mojo/core/embedder/features.h.orig	2022-11-30 08:12:58 UTC
+++ src/3rdparty/chromium/mojo/core/embedder/features.h
@@ -14,7 +14,7 @@ namespace mojo {
 namespace core {
 
 #if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_MAC)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(MOJO_CORE_EMBEDDER_FEATURES)
 BASE_DECLARE_FEATURE(kMojoLinuxChannelSharedMem);
 
