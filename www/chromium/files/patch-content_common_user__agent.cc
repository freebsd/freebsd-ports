--- content/common/user_agent.cc.orig	2019-12-16 21:51:26 UTC
+++ content/common/user_agent.cc
@@ -128,6 +128,14 @@ std::string BuildOSCpuInfo(bool include_android_build_
 #endif
   );
 
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
 
