--- src/3rdparty/chromium/content/common/mojo_core_library_support.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/content/common/mojo_core_library_support.cc
@@ -15,7 +15,7 @@ base::Optional<base::FilePath> GetMojoCoreSharedLibrar
 }
 
 base::Optional<base::FilePath> GetMojoCoreSharedLibraryPath() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   const base::CommandLine& command_line =
       *base::CommandLine::ForCurrentProcess();
   if (!command_line.HasSwitch(switches::kMojoCoreLibraryPath))
