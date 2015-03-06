--- src/mpi/pt2pt/greq_start.c.orig	2015-02-20 20:48:13 UTC
+++ src/mpi/pt2pt/greq_start.c
@@ -236,7 +236,7 @@ int MPIX_Grequest_class_create(MPI_Grequ
         MPI_Grequest_cancel_function *cancel_fn,
         MPIX_Grequest_poll_function *poll_fn,
         MPIX_Grequest_wait_function *wait_fn,
-        MPIX_Grequest_class *greq_class) __attribute__((weak,alias("MPIX_Grequest_class_create")));
+        MPIX_Grequest_class *greq_class) __attribute__((weak,alias("PMPIX_Grequest_class_create")));
 #endif
 /* -- End Profiling Symbol Block */
 
@@ -328,7 +328,7 @@ fn_fail:
 #elif defined(HAVE_PRAGMA_CRI_DUP)
 #pragma _CRI duplicate MPIX_Grequest_class_allocate as PMPIX_Grequest_class_allocate
 #elif defined(HAVE_WEAK_ATTRIBUTE)
-int MPIX_Grequest_class_allocate(MPIX_Grequest_class greq_class, void *extra_state, MPI_Request *request) __attribute__((weak,alias("MPIX_Grequest_class_allocate")));
+int MPIX_Grequest_class_allocate(MPIX_Grequest_class greq_class, void *extra_state, MPI_Request *request) __attribute__((weak,alias("PMPIX_Grequest_class_allocate")));
 #endif
 /* -- End Profiling Symbol Block */
 
@@ -379,7 +379,7 @@ int MPIX_Grequest_start( MPI_Grequest_qu
         MPIX_Grequest_poll_function *poll_fn,
         MPIX_Grequest_wait_function *wait_fn,
         void *extra_state,
-        MPI_Request *request ) __attribute__((weak,alias("MPIX_Grequest_start")));
+        MPI_Request *request ) __attribute__((weak,alias("PMPIX_Grequest_start")));
 #endif
 /* -- End Profiling Symbol Block */
 
