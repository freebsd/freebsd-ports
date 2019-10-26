--- src/3rdparty/chromium/services/service_manager/sandbox/sandbox_type.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/services/service_manager/sandbox/sandbox_type.cc
@@ -25,7 +25,7 @@ bool IsUnsandboxedSandboxType(SandboxType sandbox_type
           service_manager::features::kXRSandbox);
 #endif
     case SANDBOX_TYPE_AUDIO:
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
       return !base::FeatureList::IsEnabled(
           service_manager::features::kAudioServiceSandbox);
 #else
