--- src/3rdparty/chromium/content/browser/ppapi_plugin_process_host.cc.orig	2017-01-26 00:49:13 UTC
+++ src/3rdparty/chromium/content/browser/ppapi_plugin_process_host.cc
@@ -53,9 +53,9 @@
 
 namespace content {
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 ZygoteHandle g_ppapi_zygote;
-#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 // NOTE: changes to this class need to be reviewed by the security team.
 class PpapiPluginSandboxedProcessLauncherDelegate
@@ -109,7 +109,7 @@ class PpapiPluginSandboxedProcessLaunche
     return true;
   }
 
-#elif defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#elif defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   ZygoteHandle* GetZygote() override {
     const base::CommandLine& browser_command_line =
         *base::CommandLine::ForCurrentProcess();
@@ -203,13 +203,13 @@ PpapiPluginProcessHost* PpapiPluginProce
   return NULL;
 }
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 // static
 void PpapiPluginProcessHost::EarlyZygoteLaunch() {
   DCHECK(!g_ppapi_zygote);
   g_ppapi_zygote = CreateZygote();
 }
-#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 // static
 void PpapiPluginProcessHost::DidCreateOutOfProcessInstance(
@@ -361,7 +361,7 @@ bool PpapiPluginProcessHost::Init(const 
   base::CommandLine::StringType plugin_launcher =
       browser_command_line.GetSwitchValueNative(switches::kPpapiPluginLauncher);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   int flags = plugin_launcher.empty() ? ChildProcessHost::CHILD_ALLOW_SELF :
                                         ChildProcessHost::CHILD_NORMAL;
 #else
