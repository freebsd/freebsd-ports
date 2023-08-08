--- src/3rdparty/chromium/content/browser/ppapi_plugin_process_host.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/content/browser/ppapi_plugin_process_host.cc
@@ -364,7 +364,7 @@ bool PpapiPluginProcessHost::Init(const PepperPluginIn
   base::CommandLine::StringType plugin_launcher =
       browser_command_line.GetSwitchValueNative(switches::kPpapiPluginLauncher);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   int flags = plugin_launcher.empty() ? ChildProcessHost::CHILD_ALLOW_SELF :
                                         ChildProcessHost::CHILD_NORMAL;
 #elif defined(OS_MAC)
