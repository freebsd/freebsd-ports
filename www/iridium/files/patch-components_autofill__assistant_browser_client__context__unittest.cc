--- components/autofill_assistant/browser/client_context_unittest.cc.orig	2023-01-17 19:19:00 UTC
+++ components/autofill_assistant/browser/client_context_unittest.cc
@@ -75,7 +75,7 @@ TEST_F(ClientContextTest, Initialize) {
               ClientContextProto::PLATFORM_TYPE_ANDROID);
 #endif
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   EXPECT_THAT(actual_client_context.platform_type(),
               ClientContextProto::PLATFORM_TYPE_DESKTOP);
 #endif
@@ -256,7 +256,7 @@ TEST(GetPlatformType, ReturnsCorrectPlatform) {
               ClientContextProto::PLATFORM_TYPE_ANDROID);
 #endif
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   EXPECT_THAT(ClientContext::GetPlatformType(),
               ClientContextProto::PLATFORM_TYPE_DESKTOP);
 #endif
