--- src/3rdparty/chromium/content/common/user_agent.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/content/common/user_agent.cc
@@ -214,6 +214,14 @@ std::string BuildOSCpuInfoFromOSVersionAndCpuType(cons
   );
 #endif
 
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
 
