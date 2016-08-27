--- src/hdf5_drv/H5FDsilo.c.orig	2014-10-14 00:22:32 UTC
+++ src/hdf5_drv/H5FDsilo.c
@@ -160,27 +160,15 @@ product endorsement purposes.
  * xxx64 versions if available.
  */
 #if !defined(HDfstat) || !defined(HDstat)
-    #if H5_SIZEOF_OFF_T!=8 && H5_SIZEOF_OFF64_T==8 && defined(H5_HAVE_STAT64)
-        #ifndef HDfstat
-            #define HDfstat(F,B)        fstat64(F,B)
-        #endif /* HDfstat */
-        #ifndef HDstat
-            #define HDstat(S,B)         stat64(S,B)
-        #endif /* HDstat */
-        typedef struct stat64       h5_stat_t;
-        typedef off64_t             h5_stat_size_t;
-        #define H5_SIZEOF_H5_STAT_SIZE_T H5_SIZEOF_OFF64_T
-    #else /* H5_SIZEOF_OFF_T!=8 && ... */
-        #ifndef HDfstat
-            #define HDfstat(F,B)        fstat(F,B)
-        #endif /* HDfstat */
-        #ifndef HDstat
-            #define HDstat(S,B)         stat(S,B)
-        #endif /* HDstat */
-        typedef struct stat         h5_stat_t;
-        typedef off_t               h5_stat_size_t;
-        #define H5_SIZEOF_H5_STAT_SIZE_T H5_SIZEOF_OFF_T
-    #endif /* H5_SIZEOF_OFF_T!=8 && ... */
+    #ifndef HDfstat
+        #define HDfstat(F,B)        fstat(F,B)
+    #endif /* HDfstat */
+    #ifndef HDstat
+        #define HDstat(S,B)         stat(S,B)
+    #endif /* HDstat */
+    typedef struct stat         h5_stat_t;
+    typedef off_t               h5_stat_size_t;
+    #define H5_SIZEOF_H5_STAT_SIZE_T H5_SIZEOF_OFF_T
 #endif /* !defined(HDfstat) || !defined(HDstat) */
 #ifndef HDlseek
     #ifdef H5_HAVE_LSEEK64
