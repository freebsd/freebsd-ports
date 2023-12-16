--- src/3rdparty/chromium/third_party/blink/renderer/modules/ml/webnn/ml_graph_xnnpack.cc.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/modules/ml/webnn/ml_graph_xnnpack.cc
@@ -177,7 +177,7 @@ class SharedXnnpackContext : public ThreadSafeRefCount
 
   ~SharedXnnpackContext() {
     base::AutoLock auto_lock(SharedXnnpackContextLock());
-#if !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+#if !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
     // For Linux and ChromeOS, cpuinfo needs to parse /proc/cpuinfo to
     // initialize in pre sandbox stage. Calling xnn_deinitialize() here will
     // deinitialize cpuinfo within sandbox and cannot access /proc/cpuinfo
