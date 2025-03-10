--- services/screen_ai/public/cpp/utilities.cc.orig	2024-08-26 12:06:38 UTC
+++ services/screen_ai/public/cpp/utilities.cc
@@ -18,7 +18,7 @@ namespace screen_ai {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 constexpr char kBinaryPathSwitch[] = "screen-ai-binary";
 #endif
 
@@ -39,7 +39,7 @@ constexpr char kScreenAIDlcRootPath[] =
 #endif
 
 #if BUILDFLAG(ENABLE_SCREEN_AI_BROWSERTESTS)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr base::FilePath::CharType kScreenAIResourcePathForTests[] =
     FILE_PATH_LITERAL("third_party/screen-ai/linux/resources");
 #elif BUILDFLAG(IS_MAC)
@@ -128,7 +128,7 @@ base::FilePath GetComponentBinaryPathForTests() {
 
 const char* GetBinaryPathSwitch() {
   // This is only used on Linux and ChromeOS.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return kBinaryPathSwitch;
 #else
   return nullptr;
