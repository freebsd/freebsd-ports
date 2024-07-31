--- base/threading/hang_watcher.cc.orig	2024-07-30 11:12:21 UTC
+++ base/threading/hang_watcher.cc
@@ -354,7 +354,7 @@ void HangWatcher::InitializeOnMainThread(ProcessType p
 
   bool enable_hang_watcher = base::FeatureList::IsEnabled(kEnableHangWatcher);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_BSD)
   if (is_zygote_child) {
     enable_hang_watcher =
         enable_hang_watcher &&
