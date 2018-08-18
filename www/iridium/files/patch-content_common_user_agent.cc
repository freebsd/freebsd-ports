--- content/common/user_agent.cc.orig	2017-12-23 22:30:16.333353000 +0100
+++ content/common/user_agent.cc	2017-12-23 22:32:27.429827000 +0100
@@ -131,6 +131,14 @@
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
 
