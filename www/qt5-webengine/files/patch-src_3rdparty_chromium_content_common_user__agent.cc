--- src/3rdparty/chromium/content/common/user_agent.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/content/common/user_agent.cc
@@ -125,6 +125,14 @@ std::string BuildOSCpuInfo() {
 #endif
   );  // NOLINT
 
+#if defined(OS_BSD)
+#if defined(__x86_64__)
+  base::StringAppendF(&os_cpu, "; Linux x86_64");
+#else
+  base::StringAppendF(&os_cpu, "; Linux i686");
+#endif
+#endif
+
   return os_cpu;
 }
 
