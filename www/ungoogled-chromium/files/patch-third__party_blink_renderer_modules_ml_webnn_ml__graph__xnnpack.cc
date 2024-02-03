--- third_party/blink/renderer/modules/ml/webnn/ml_graph_xnnpack.cc.orig	2024-02-03 15:42:55 UTC
+++ third_party/blink/renderer/modules/ml/webnn/ml_graph_xnnpack.cc
@@ -197,7 +197,7 @@ class SharedXnnpackContext : public ThreadSafeRefCount
 
   ~SharedXnnpackContext() {
     base::AutoLock auto_lock(SharedXnnpackContextLock());
-#if !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+#if !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
     // For Linux and ChromeOS, cpuinfo needs to parse /proc/cpuinfo to
     // initialize in pre sandbox stage. Calling xnn_deinitialize() here will
     // deinitialize cpuinfo within sandbox and cannot access /proc/cpuinfo
