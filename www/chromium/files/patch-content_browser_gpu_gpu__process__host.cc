--- content/browser/gpu/gpu_process_host.cc.orig	2022-01-20 10:35:56 UTC
+++ content/browser/gpu/gpu_process_host.cc
@@ -98,7 +98,7 @@
 #include "ui/ozone/public/ozone_switches.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/gfx/switches.h"
 #endif
 
@@ -233,8 +233,8 @@ static const char* const kSwitchNames[] = {
     sandbox::policy::switches::kNoSandbox,
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
-    !BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_BSD) || (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
+    !BUILDFLAG(IS_CHROMEOS_LACROS))
     switches::kDisableDevShmUsage,
 #endif
 #if defined(OS_WIN)
@@ -295,7 +295,7 @@ static const char* const kSwitchNames[] = {
     switches::kOzoneDumpFile,
     switches::kDisableBufferBWCompression,
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     switches::kX11Display,
     switches::kNoXshm,
 #endif
@@ -1135,7 +1135,7 @@ bool GpuProcessHost::LaunchGpuProcess() {
   std::unique_ptr<base::CommandLine> cmd_line =
       std::make_unique<base::CommandLine>(base::CommandLine::NO_PROGRAM);
 #else
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   int child_flags = gpu_launcher.empty() ? ChildProcessHost::CHILD_ALLOW_SELF
                                          : ChildProcessHost::CHILD_NORMAL;
 #elif defined(OS_MAC)
