--- cpucounters.cpp.orig	2017-09-17 06:31:28 UTC
+++ cpucounters.cpp
@@ -192,6 +192,9 @@ class InstanceLock (public)
 }; 
 #endif // end of _MSC_VER else
 
+#if defined(__FreeBSD__)
+#define cpu_set_t cpuset_t
+#endif
 
 class TemporalThreadAffinity  // speedup trick for Linux, FreeBSD, DragonFlyBSD
 {
