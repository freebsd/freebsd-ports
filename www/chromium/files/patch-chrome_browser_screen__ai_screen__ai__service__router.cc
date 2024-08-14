--- chrome/browser/screen_ai/screen_ai_service_router.cc.orig	2024-07-30 11:12:21 UTC
+++ chrome/browser/screen_ai/screen_ai_service_router.cc
@@ -284,7 +284,7 @@ void ScreenAIServiceRouter::LaunchIfNotRunning() {
   base::FilePath binary_path = state_instance->get_component_binary_path();
 #if BUILDFLAG(IS_WIN)
   std::vector<base::FilePath> preload_libraries = {binary_path};
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   std::vector<std::string> extra_switches = {
       base::StringPrintf("--%s=%s", screen_ai::GetBinaryPathSwitch(),
                          binary_path.MaybeAsASCII().c_str())};
@@ -298,7 +298,7 @@ void ScreenAIServiceRouter::LaunchIfNotRunning() {
           .WithPreloadedLibraries(
               preload_libraries,
               content::ServiceProcessHostPreloadLibraries::GetPassKey())
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           .WithExtraCommandLineSwitches(extra_switches)
 #endif  // BUILDFLAG(IS_WIN)
           .Pass());
