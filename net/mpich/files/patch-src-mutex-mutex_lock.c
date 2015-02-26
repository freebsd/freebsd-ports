--- src/mutex/mutex_lock.c.orig	2015-02-20 20:48:13 UTC
+++ src/mutex/mutex_lock.c
@@ -21,7 +21,7 @@
 #elif defined(HAVE_PRAGMA_CRI_DUP)
 #pragma _CRI duplicate MPIX_Mutex_lock as PMPIX_Mutex_lock
 #elif defined(HAVE_WEAK_ATTRIBUTE)
-int MPIX_Mutex_lock(MPIX_Mutex hdl, int mutex, int proc) __attribute__((weak,alias("MPIX_Mutex_lock")));
+int MPIX_Mutex_lock(MPIX_Mutex hdl, int mutex, int proc) __attribute__((weak,alias("PMPIX_Mutex_lock")));
 #endif
 /* -- End Profiling Symbol Block */
 
