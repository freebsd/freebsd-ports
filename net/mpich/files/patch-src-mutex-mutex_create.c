--- src/mutex/mutex_create.c.orig	2015-02-20 20:48:13 UTC
+++ src/mutex/mutex_create.c
@@ -23,7 +23,7 @@
 #elif defined(HAVE_PRAGMA_CRI_DUP)
 #pragma _CRI duplicate MPIX_Mutex_create as PMPIX_Mutex_create
 #elif defined(HAVE_WEAK_ATTRIBUTE)
-int MPIX_Mutex_create(int my_count, MPI_Comm comm, MPIX_Mutex * hdl_out) __attribute__((weak,alias("MPIX_Mutex_create")));
+int MPIX_Mutex_create(int my_count, MPI_Comm comm, MPIX_Mutex * hdl_out) __attribute__((weak,alias("PMPIX_Mutex_create")));
 #endif
 /* -- End Profiling Symbol Block */
 
