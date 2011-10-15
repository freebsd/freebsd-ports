--- ./cache.c.orig	2009-12-15 07:18:40.000000000 -0500
+++ ./cache.c	2011-10-14 22:36:47.000000000 -0400
@@ -27,6 +27,7 @@
 #include "sysfs.h"
 #include "cache.h"
 
+#ifdef __Linux__
 struct cache { 
 	unsigned level;
 	/* Numerical values must match MCACOD */
@@ -164,6 +165,15 @@
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
