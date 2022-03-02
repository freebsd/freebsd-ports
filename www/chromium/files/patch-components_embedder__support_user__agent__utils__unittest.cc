--- components/embedder_support/user_agent_utils_unittest.cc.orig	2022-02-28 16:54:41 UTC
+++ components/embedder_support/user_agent_utils_unittest.cc
@@ -54,7 +54,7 @@ namespace {
 static constexpr char kChromeProductVersionRegex[] =
     "Chrome/([0-9]+).([0-9]+).([0-9]+).([0-9]+)";
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 std::string GetMachine() {
   struct utsname unixinfo;
   uname(&unixinfo);
@@ -162,7 +162,7 @@ void CheckUserAgentStringOrdering(bool mobile_device) 
     int value;
     ASSERT_TRUE(base::StringToInt(pieces[i], &value));
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // X11; Linux x86_64
   ASSERT_EQ(2u, pieces.size());
   ASSERT_EQ("X11", pieces[0]);
