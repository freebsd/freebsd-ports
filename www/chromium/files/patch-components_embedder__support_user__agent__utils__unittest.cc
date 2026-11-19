--- components/embedder_support/user_agent_utils_unittest.cc.orig	2026-11-19 12:25:27 UTC
+++ components/embedder_support/user_agent_utils_unittest.cc
@@ -157,7 +157,7 @@ class UserAgentUtilsTest : public testing::Test {
         "X11; CrOS x86_64 14541.0.0";
 #elif BUILDFLAG(IS_FUCHSIA)
         "Fuchsia";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
         "X11; Linux x86_64";
 #elif BUILDFLAG(IS_MAC)
         "Macintosh; Intel Mac OS X 10_15_7";
@@ -336,7 +336,7 @@ TEST_F(UserAgentUtilsTest, UserAgentMetadata) {
 
 #if BUILDFLAG(IS_WIN)
   VerifyWinPlatformVersion(metadata.platform_version);
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   EXPECT_EQ(metadata.platform_version, "");
 #else
   int32_t major, minor, bugfix = 0;
@@ -363,7 +363,7 @@ TEST_F(UserAgentUtilsTest, UserAgentMetadata) {
 #endif
 #elif BUILDFLAG(IS_ANDROID)
   EXPECT_EQ(metadata.platform, "Android");
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   EXPECT_EQ(metadata.platform, "Linux");
 #elif BUILDFLAG(IS_FREEBSD)
   EXPECT_EQ(metadata.platform, "FreeBSD");
