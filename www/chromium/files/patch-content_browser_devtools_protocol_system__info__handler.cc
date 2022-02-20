--- content/browser/devtools/protocol/system_info_handler.cc.orig	2022-02-07 13:39:41 UTC
+++ content/browser/devtools/protocol/system_info_handler.cc
@@ -50,7 +50,7 @@ std::unique_ptr<SystemInfo::Size> GfxSizeToSystemInfoS
 // Windows builds need more time -- see Issue 873112 and 1004472.
 // Mac builds need more time - see Issue angleproject:6182.
 #if ((defined(OS_LINUX) || defined(OS_CHROMEOS)) && !defined(NDEBUG)) || \
-    defined(OS_WIN) || defined(OS_MAC) || defined(USE_OZONE)
+    defined(OS_WIN) || defined(OS_MAC) || defined(USE_OZONE) || defined(OS_BSD)
 static constexpr int kGPUInfoWatchdogTimeoutMultiplierOS = 3;
 #else
 static constexpr int kGPUInfoWatchdogTimeoutMultiplierOS = 1;
