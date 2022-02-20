--- content/common/user_agent.cc.orig	2022-02-07 13:39:41 UTC
+++ content/common/user_agent.cc
@@ -252,6 +252,16 @@ std::string BuildOSCpuInfoFromOSVersionAndCpuType(cons
   );
 #endif
 
+#if defined(OS_BSD)
+#if defined(__x86_64__)
+  base::StringAppendF(&os_cpu, "; Linux x86_64");
+#elif defined(__aarch64__)
+  base::StringAppendF(&os_cpu, "; Linux aarch64");
+#else
+  base::StringAppendF(&os_cpu, "; Linux i686");
+#endif
+#endif
+
   return os_cpu;
 }
 
