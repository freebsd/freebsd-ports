--- content/app/content_main_runner.cc.orig	2012-10-31 21:01:34.000000000 +0200
+++ content/app/content_main_runner.cc	2012-11-07 17:25:10.000000000 +0200
@@ -91,7 +91,7 @@
 extern int RendererMain(const content::MainFunctionParams&);
 extern int WorkerMain(const content::MainFunctionParams&);
 extern int UtilityMain(const content::MainFunctionParams&);
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 namespace content {
 extern int ZygoteMain(const MainFunctionParams&,
                       ZygoteForkDelegate* forkdelegate);
@@ -333,7 +333,7 @@
   int (*function)(const MainFunctionParams&);
 };
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 // On platforms that use the zygote, we have a special subset of
 // subprocesses that are launched via the zygote.  This function
 // fills in some process-launching bits around ZygoteMain().
@@ -438,7 +438,7 @@
     }
   }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   // Zygote startup is special -- see RunZygote comments above
   // for why we don't use ZygoteMain directly.
   if (process_type == switches::kZygoteProcess)
@@ -548,7 +548,7 @@
                kPrimaryIPCChannel + base::GlobalDescriptors::kBaseDescriptor);
 #endif  // !OS_ANDROID && !OS_IOS
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
     g_fds->Set(kCrashDumpSignal,
                kCrashDumpSignal + base::GlobalDescriptors::kBaseDescriptor);
 #endif
