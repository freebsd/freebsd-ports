--- content/common/user_agent.cc.orig	2022-03-28 18:11:04 UTC
+++ content/common/user_agent.cc
@@ -244,6 +244,16 @@ std::string BuildOSCpuInfoFromOSVersionAndCpuType(cons
                       "Android %s", os_version.c_str()
 #elif BUILDFLAG(IS_FUCHSIA)
                       "Fuchsia"
+#elif BUILDFLAG(IS_BSD)
+#if defined(__x86_64__)
+                      "Linux x86_64; %s %s",
+#elif defined(__aarch64__)
+                      "Linux aarch64; %s %s",
+#else
+                      "Linux i686; %s %s",
+#endif
+                      unixinfo.sysname,  // e.g. Linux
+                      cpu_type.c_str()   // e.g. i686
 #elif BUILDFLAG(IS_POSIX)
                       "%s %s",
                       unixinfo.sysname,  // e.g. Linux
