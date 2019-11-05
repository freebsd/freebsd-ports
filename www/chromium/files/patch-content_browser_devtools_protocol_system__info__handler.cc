--- content/browser/devtools/protocol/system_info_handler.cc.orig	2019-09-09 21:55:16 UTC
+++ content/browser/devtools/protocol/system_info_handler.cc
@@ -48,7 +48,7 @@ std::unique_ptr<SystemInfo::Size> GfxSizeToSystemInfoS
 // Give the GPU process a few seconds to provide GPU info.
 // Linux Debug builds need more time -- see Issue 796437.
 // Windows builds need more time -- see Issue 873112.
-#if (defined(OS_LINUX) && !defined(NDEBUG)) || defined(OS_WIN)
+#if ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(NDEBUG)) || defined(OS_WIN)
 const int kGPUInfoWatchdogTimeoutMs = 20000;
 #else
 const int kGPUInfoWatchdogTimeoutMs = 5000;
