--- chrome/app/chrome_main.cc.orig	2017-06-05 19:03:01 UTC
+++ chrome/app/chrome_main.cc
@@ -97,14 +97,14 @@ int ChromeMain(int argc, const char** argv) {
   ALLOW_UNUSED_LOCAL(command_line);
 #endif
 
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   if (command_line->HasSwitch(switches::kHeadless)) {
 #if defined(OS_MACOSX)
     SetUpBundleOverrides();
 #endif
     return headless::HeadlessShellMain(argc, argv);
   }
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 
 #if defined(OS_CHROMEOS) && BUILDFLAG(ENABLE_PACKAGE_MASH_SERVICES)
   version_info::Channel channel = chrome::GetChannel();
