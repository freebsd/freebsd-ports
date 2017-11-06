We currently do not use the zygote code that Linux does.
--- src/3rdparty/chromium/content/app/content_main_runner.cc.orig	2017-04-19 16:52:23 UTC
+++ src/3rdparty/chromium/content/app/content_main_runner.cc
@@ -265,7 +265,7 @@ struct MainFunction {
   int (*function)(const MainFunctionParams&);
 };
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 // On platforms that use the zygote, we have a special subset of
 // subprocesses that are launched via the zygote.  This function
 // fills in some process-launching bits around ZygoteMain().
@@ -314,7 +314,7 @@ int RunZygote(const MainFunctionParams& 
   NOTREACHED() << "Unknown zygote process type: " << process_type;
   return 1;
 }
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 
 #if !defined(OS_IOS)
 static void RegisterMainThreadFactories() {
@@ -385,7 +385,7 @@ int RunNamedProcessTypeMain(
     }
   }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   // Zygote startup is special -- see RunZygote comments above
   // for why we don't use ZygoteMain directly.
   if (process_type == switches::kZygoteProcess)
