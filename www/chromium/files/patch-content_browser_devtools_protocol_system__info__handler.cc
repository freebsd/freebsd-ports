--- content/browser/devtools/protocol/system_info_handler.cc.orig	2020-11-13 06:36:42 UTC
+++ content/browser/devtools/protocol/system_info_handler.cc
@@ -47,7 +47,7 @@ std::unique_ptr<SystemInfo::Size> GfxSizeToSystemInfoS
 // Give the GPU process a few seconds to provide GPU info.
 // Linux Debug builds need more time -- see Issue 796437 and 1046598.
 // Windows builds need more time -- see Issue 873112 and 1004472.
-#if ((defined(OS_LINUX) || defined(OS_CHROMEOS)) && !defined(NDEBUG)) || \
+#if ((defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && !defined(NDEBUG)) || \
     defined(OS_WIN)
 const int kGPUInfoWatchdogTimeoutMs = 30000;
 #else
