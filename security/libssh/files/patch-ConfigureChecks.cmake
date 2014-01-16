--- ./ConfigureChecks.cmake
+++ ./ConfigureChecks.cmake
@@ -169,11 +169,9 @@ if (GCRYPT_FOUND)
     endif (GCRYPT_VERSION VERSION_GREATER "1.4.6")
 endif (GCRYPT_FOUND)
 
-if (CMAKE_HAVE_THREADS_LIBRARY)
-    if (CMAKE_USE_PTHREADS_INIT)
-        set(HAVE_PTHREAD 1)
-    endif (CMAKE_USE_PTHREADS_INIT)
-endif (CMAKE_HAVE_THREADS_LIBRARY)
+if (CMAKE_USE_PTHREADS_INIT)
+    set(HAVE_PTHREAD 1)
+endif (CMAKE_USE_PTHREADS_INIT)
 
 # OPTIONS
 check_c_source_compiles("

