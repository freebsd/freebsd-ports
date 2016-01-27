--- content/app/content_main_runner.cc.orig	2016-01-21 16:00:09.209120298 +0100
+++ content/app/content_main_runner.cc	2016-01-21 16:02:40.649109123 +0100
@@ -98,10 +98,10 @@
 #include "base/posix/global_descriptors.h"
 #include "content/public/common/content_descriptors.h"
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
 #include "content/public/common/zygote_fork_delegate_linux.h"
 #endif
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 #include "content/zygote/zygote_main.h"
 #endif
 
@@ -259,7 +259,7 @@
   int (*function)(const MainFunctionParams&);
 };
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 // On platforms that use the zygote, we have a special subset of
 // subprocesses that are launched via the zygote.  This function
 // fills in some process-launching bits around ZygoteMain().
@@ -308,7 +308,7 @@
   NOTREACHED() << "Unknown zygote process type: " << process_type;
   return 1;
 }
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 
 #if !defined(OS_IOS)
 static void RegisterMainThreadFactories() {
@@ -379,7 +379,7 @@
     }
   }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   // Zygote startup is special -- see RunZygote comments above
   // for why we don't use ZygoteMain directly.
   if (process_type == switches::kZygoteProcess)
