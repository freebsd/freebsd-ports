See http://sphinxsearch.com/bugs/view.php?id=326

--- src/searchd.cpp.orig	2009-04-07 00:08:27.000000000 +0200
+++ src/searchd.cpp		2009-05-16 17:15:34.000000000 +0200
@@ -3878,8 +3878,19 @@
 	if ( !g_bCpuStats )
 		return 0;
 
+#if defined(CLOCK_PROCESS_CPUTIME_ID)
+// CPU time (user+sys), Linux style
+#define LOC_CLOCK CLOCK_PROCESS_CPUTIME_ID
+#elif defined(CLOCK_PROF)
+// CPU time (user+sys), FreeBSD style
+#define LOC_CLOCK CLOCK_PROF
+#else
+// POSIX fallback (wall time)
+#define LOC_CLOCK CLOCK_REALTIME
+#endif
+
 	struct timespec tp;
-	if ( clock_gettime ( CLOCK_PROCESS_CPUTIME_ID, &tp ) )
+	if ( clock_gettime ( LOC_CLOCK, &tp ) )
 		return 0;
 
 	return tp.tv_sec*1000000 + tp.tv_nsec/1000;
