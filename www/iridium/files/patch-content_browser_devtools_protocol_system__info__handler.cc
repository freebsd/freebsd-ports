--- content/browser/devtools/protocol/system_info_handler.cc.orig	2019-12-16 21:51:26 UTC
+++ content/browser/devtools/protocol/system_info_handler.cc
@@ -48,7 +48,7 @@ std::unique_ptr<SystemInfo::Size> GfxSizeToSystemInfoS
 // Give the GPU process a few seconds to provide GPU info.
 // Linux Debug builds need more time -- see Issue 796437.
 // Windows builds need more time -- see Issue 873112 and 1004472.
-#if (defined(OS_LINUX) && !defined(NDEBUG))
+#if ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(NDEBUG))
 const int kGPUInfoWatchdogTimeoutMs = 20000;
 #elif defined(OS_WIN)
 const int kGPUInfoWatchdogTimeoutMs = 30000;
