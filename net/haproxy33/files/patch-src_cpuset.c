--- src/cpuset.c.orig	2025-10-18 09:24:05 UTC
+++ src/cpuset.c
@@ -51,7 +51,11 @@ void ha_cpuset_and(struct hap_cpuset *dst, struct hap_
 	CPU_AND(&dst->cpuset, &dst->cpuset, &src->cpuset);
 
 #elif defined(CPUSET_USE_FREEBSD_CPUSET)
+#if defined(CPU_ALLOC)
+	CPU_AND(&dst->cpuset, &dst->cpuset, &src->cpuset);
+#else
 	CPU_AND(&dst->cpuset, &src->cpuset);
+#endif
 
 #elif defined(CPUSET_USE_ULONG)
 	dst->cpuset &= src->cpuset;
