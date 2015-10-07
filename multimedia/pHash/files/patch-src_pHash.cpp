--- src/pHash.cpp.orig	2013-04-13 17:23:12 UTC
+++ src/pHash.cpp
@@ -34,14 +34,18 @@
 int ph_num_threads()
 {
 	int numCPU = 1;
-#ifdef __GLIBC__
+#ifdef _SC_NPROCESSORS_ONLN
 		numCPU = sysconf( _SC_NPROCESSORS_ONLN );
 #else
 		int mib[2];
 		size_t len; 
 
 		mib[0] = CTL_HW;
+#ifdef HW_AVAILCPU
 		mib[1] = HW_AVAILCPU;
+#else
+		mib[1] = HW_NCPU;
+#endif
 
 		sysctl(mib, 2, &numCPU, &len, NULL, 0);
 
