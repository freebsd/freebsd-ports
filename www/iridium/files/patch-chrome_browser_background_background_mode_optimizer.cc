--- chrome/browser/background/background_mode_optimizer.cc.orig	2017-09-07 23:33:41.430876000 +0200
+++ chrome/browser/background/background_mode_optimizer.cc	2017-09-07 23:34:04.189439000 +0200
@@ -30,10 +30,10 @@
           switches::kKeepAliveForTest))
     return nullptr;
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   if (base::FeatureList::IsEnabled(features::kBackgroundModeAllowRestart))
     return base::WrapUnique(new BackgroundModeOptimizer());
-#endif  // defined(OS_WIN) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
   return nullptr;
 }
