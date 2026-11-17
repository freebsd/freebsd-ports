--- src/components/private_ai/proto_utils/client_metadata_utils.cc.orig	2026-10-18 18:43:23 UTC
+++ src/components/private_ai/proto_utils/client_metadata_utils.cc
@@ -41,7 +41,7 @@ proto::ChromeClientMetadata::Platform Ge
   return proto::ChromeClientMetadata::PLATFORM_ANDROID;
 #elif BUILDFLAG(IS_IOS)
   return proto::ChromeClientMetadata::PLATFORM_IOS;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return proto::ChromeClientMetadata::PLATFORM_LINUX;
 #else
   return proto::ChromeClientMetadata::PLATFORM_UNKNOWN;
