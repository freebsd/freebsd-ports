--- components/embedder_support/user_agent_utils_unittest.cc.orig	2026-11-11 14:44:17 UTC
+++ components/embedder_support/user_agent_utils_unittest.cc
@@ -155,7 +155,7 @@ class UserAgentUtilsTest : public testing::Test {
         "X11; CrOS x86_64 14541.0.0";
 #elif BUILDFLAG(IS_FUCHSIA)
         "Fuchsia";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
         "X11; Linux x86_64";
 #elif BUILDFLAG(IS_MAC)
         "Macintosh; Intel Mac OS X 10_15_7";
@@ -334,7 +334,7 @@ TEST_F(UserAgentUtilsTest, UserAgentMetadata) {
 
 #if BUILDFLAG(IS_WIN)
   VerifyWinPlatformVersion(metadata.platform_version);
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   EXPECT_EQ(metadata.platform_version, "");
 #else
   int32_t major, minor, bugfix = 0;
@@ -361,7 +361,7 @@ TEST_F(UserAgentUtilsTest, UserAgentMetadata) {
 #endif
 #elif BUILDFLAG(IS_ANDROID)
   EXPECT_EQ(metadata.platform, "Android");
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   EXPECT_EQ(metadata.platform, "Linux");
 #elif BUILDFLAG(IS_FREEBSD)
   EXPECT_EQ(metadata.platform, "FreeBSD");
