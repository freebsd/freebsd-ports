--- src/cpuset.c.orig	2021-12-23 16:47:51 UTC
+++ src/cpuset.c
@@ -53,7 +53,11 @@ void ha_cpuset_and(struct hap_cpuset *dst, const struc
 	CPU_AND(&dst->cpuset, &dst->cpuset, &src->cpuset);
 
 #elif defined(CPUSET_USE_FREEBSD_CPUSET)
+#if defined(CPU_ALLOC)
+	CPU_AND(&dst->cpuset, &dst->cpuset, &src->cpuset);
+#else
 	CPU_AND(&dst->cpuset, &src->cpuset);
+#endif
 
 #elif defined(CPUSET_USE_ULONG)
 	dst->cpuset &= src->cpuset;
