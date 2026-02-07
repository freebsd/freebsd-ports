--- cache.c.orig	2016-02-10 18:38:43 UTC
+++ cache.c
@@ -27,6 +27,7 @@
 #include "sysfs.h"
 #include "cache.h"
 
+#ifdef __Linux__
 struct cache { 
 	unsigned level;
 	/* Numerical values must match MCACOD */
@@ -173,6 +174,15 @@ int cache_to_cpus(int cpu, unsigned leve
 	Wprintf("Cannot find sysfs cache for CPU %d", cpu);
 	return -1;
 }
+#endif
+
+#ifdef __FreeBSD__
+int cache_to_cpus(int cpu, unsigned level, unsigned type, 
+		   int *cpulen, unsigned **cpumap)
+{
+	return -1;
+}
+#endif
 
 #ifdef TEST
 main()
