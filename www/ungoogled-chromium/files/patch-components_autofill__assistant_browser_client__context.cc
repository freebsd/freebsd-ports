--- components/autofill_assistant/browser/client_context.cc.orig	2023-01-13 08:56:02 UTC
+++ components/autofill_assistant/browser/client_context.cc
@@ -109,7 +109,7 @@ ClientContextProto::PlatformType ClientContext::GetPla
 #if BUILDFLAG(IS_ANDROID)
   return ClientContextProto::PLATFORM_TYPE_ANDROID;
 #elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   return ClientContextProto::PLATFORM_TYPE_DESKTOP;
 #else
   return ClientContextProto::PLATFORM_TYPE_UNDEFINED;
