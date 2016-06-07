--- content/browser/ppapi_plugin_process_host.cc.orig	2016-05-11 19:02:20 UTC
+++ content/browser/ppapi_plugin_process_host.cc
@@ -49,7 +49,7 @@
 
 namespace content {
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 ZygoteHandle g_ppapi_zygote;
 #endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
 
@@ -113,7 +113,7 @@ class PpapiPluginSandboxedProcessLaunche
   }
 
 #elif defined(OS_POSIX)
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   ZygoteHandle* GetZygote() override {
     const base::CommandLine& browser_command_line =
         *base::CommandLine::ForCurrentProcess();
@@ -213,7 +213,7 @@ PpapiPluginProcessHost* PpapiPluginProce
   return NULL;
 }
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 // static
 void PpapiPluginProcessHost::EarlyZygoteLaunch() {
   DCHECK(!g_ppapi_zygote);
