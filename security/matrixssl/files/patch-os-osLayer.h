--- os/osLayer.h.orig	Fri Mar 17 16:06:31 2006
+++ os/osLayer.h	Fri Mar 17 16:06:34 2006
@@ -119,7 +119,7 @@
 		long sec;
 		long usec;
 	} sslTime_t;
-#elif (defined(__i386__) || defined(RDTSC))
+#elif (defined(__i386__) || defined(RDTSC)) && !defined(__FreeBSD__)
 typedef unsigned long long LARGE_INTEGER;
 typedef LARGE_INTEGER sslTime_t;
 #elif WINCE
