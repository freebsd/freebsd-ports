--- src/mutex/mutex_free.c.orig	2015-02-20 20:48:13 UTC
+++ src/mutex/mutex_free.c
@@ -20,7 +20,7 @@
 #elif defined(HAVE_PRAGMA_CRI_DUP)
 #pragma _CRI duplicate MPIX_Mutex_free as PMPIX_Mutex_free
 #elif defined(HAVE_WEAK_ATTRIBUTE)
-int MPIX_Mutex_free(MPIX_Mutex * hdl_ptr) __attribute__((weak,alias("MPIX_Mutex_free")));
+int MPIX_Mutex_free(MPIX_Mutex * hdl_ptr) __attribute__((weak,alias("PMPIX_Mutex_free")));
 #endif
 /* -- End Profiling Symbol Block */
 
