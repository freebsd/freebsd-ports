--- content/app/content_main_runner.cc.orig	2012-11-27 10:01:23.000000000 +0200
+++ content/app/content_main_runner.cc	2012-12-09 16:57:51.000000000 +0200
@@ -99,7 +99,7 @@
 extern int RendererMain(const content::MainFunctionParams&);
 extern int UtilityMain(const MainFunctionParams&);
 extern int WorkerMain(const MainFunctionParams&);
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 extern int ZygoteMain(const MainFunctionParams&,
                       ZygoteForkDelegate* forkdelegate);
 #endif
@@ -344,7 +344,7 @@
   int (*function)(const MainFunctionParams&);
 };
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 // On platforms that use the zygote, we have a special subset of
 // subprocesses that are launched via the zygote.  This function
 // fills in some process-launching bits around ZygoteMain().
@@ -449,7 +449,7 @@
     }
   }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   // Zygote startup is special -- see RunZygote comments above
   // for why we don't use ZygoteMain directly.
   if (process_type == switches::kZygoteProcess)
