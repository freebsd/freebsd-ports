--- content/common/mojo_core_library_support.cc.orig	2020-11-16 14:35:51 UTC
+++ content/common/mojo_core_library_support.cc
@@ -15,7 +15,7 @@ bool IsMojoCoreSharedLibraryEnabled() {
 }
 
 base::Optional<base::FilePath> GetMojoCoreSharedLibraryPath() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   const base::CommandLine& command_line =
       *base::CommandLine::ForCurrentProcess();
   if (!command_line.HasSwitch(switches::kMojoCoreLibraryPath))
