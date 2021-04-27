--- content/browser/devtools/protocol/system_info_handler.cc.orig	2021-04-14 18:41:02 UTC
+++ content/browser/devtools/protocol/system_info_handler.cc
@@ -50,8 +50,8 @@ std::unique_ptr<SystemInfo::Size> GfxSizeToSystemInfoS
 // 1153667.
 // Windows builds need more time -- see Issue 873112 and 1004472.
 // ASAN builds need more time -- see Issue 1167875.
-#if ((defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)) && \
-     !defined(NDEBUG)) ||                                              \
+#if ((defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)) && \
+     !defined(NDEBUG)) ||                                                                 \
     defined(OS_WIN) || defined(ADDRESS_SANITIZER)
 const int kGPUInfoWatchdogTimeoutMs = 30000;
 #else
