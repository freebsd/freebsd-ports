--- os/linux/linux.c.orig	Fri Mar 17 16:03:55 2006
+++ os/linux/linux.c	Fri Mar 17 16:04:27 2006
@@ -39,7 +39,7 @@
 
 #include "../osLayer.h"
 
-#if defined(__i386__) || defined(RDTSC)
+#if (defined(__i386__) || defined(RDTSC))&& !defined(__FreeBSD__)
 #include <asm/timex.h>
 /*
 	As defined in asm/timex.h for x386:
@@ -86,7 +86,7 @@
 /*
 	Initialize times
 */
-#if defined(__i386__) || defined(RDTSC)
+#if (defined(__i386__) || defined(RDTSC)) && !defined(__FreeBSD__)
 	if ((cpuInfo = fopen ("/proc/cpuinfo","r")) == NULL) {
 		matrixStrDebugMsg("Error opening /proc/cpuinfo\n", NULL);
 		return -2;
@@ -122,7 +122,11 @@
 #ifdef USE_MULTITHREADING
 	pthread_mutexattr_init(&attr);
 #ifndef OSX
+#ifndef PTHREAD_MUTEX_RECURSIVE_NP
+	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
+#else
 	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE_NP);
+#endif /* PTHREAD_MUTEX_RECURSIVE_NP */
 #endif /* !OSX */
 #endif /* USE_MULTITHREADING */
 	return psOpenMalloc(MAX_MEMORY_USAGE);
@@ -252,7 +256,7 @@
 /*
 	Use a platform specific high resolution timer
 */
-#if defined(__i386__) || defined(RDTSC)
+#if (defined(__i386__) || defined(RDTSC)) && !defined(__FreeBSD__)
 
 int32 sslInitMsecs(sslTime_t *t)
 {
