--- content/common/user_agent.cc.orig	2020-11-13 06:36:43 UTC
+++ content/common/user_agent.cc
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
 
