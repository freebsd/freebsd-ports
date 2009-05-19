--- ./rkward/rbackend/DetectPthreads.cmake.orig	2008-01-21 19:58:24.000000000 +0100
+++ ./rkward/rbackend/DetectPthreads.cmake	2009-05-06 23:51:31.000000000 +0200
@@ -1,7 +1,7 @@
 INCLUDE(CheckIncludeFile)
 INCLUDE(CheckFunctionExists)
 
-CHECK_INCLUDE_FILE(phthread_np.h HAVE_PTHREAD_NP_H)
+CHECK_INCLUDE_FILE(pthread_np.h HAVE_PTHREAD_NP_H)
 
 SET (CMAKE_REQUIRED_FLAGS ${CMAKE_THREAD_LIBS_INIT})
 CHECK_FUNCTION_EXISTS (pthread_getattr_np HAVE_PTHREAD_GETATTR_NP)
@@ -9,4 +9,4 @@
 CHECK_FUNCTION_EXISTS (pthread_get_stacksize_np HAVE_PTHREAD_GET_STACKSIZE_NP)
 CHECK_FUNCTION_EXISTS (pthread_get_stackaddr_np HAVE_PTHREAD_GET_STACKADDR_NP)
 
-CONFIGURE_FILE(pthread_config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/pthread_config.h)
\ No newline at end of file
+CONFIGURE_FILE(pthread_config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/pthread_config.h)
