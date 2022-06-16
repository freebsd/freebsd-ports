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
@@ -255,13 +243,13 @@ static const char *flavors(H5F_mem_t m)
         snprintf(msg, sizeof(msg), Msg "(errno=%d, \"%s\")",	\
             Errno, strerror(Errno));					\
     ret_value = Ret;							\
-    H5Epush_ret(Func, Cls, Maj, Min, msg, Ret)				\
+    H5Epush_ret(Func, Cls, Maj, Min, msg, Ret);				\
 }
 #else
 #define H5E_PUSH_HELPER(Func,Cls,Maj,Min,Msg,Ret,Errno)			\
 {									\
     ret_value = Ret;							\
-    H5Epush_ret(Func, Cls, Maj, Min, Msg, Ret)				\
+    H5Epush_ret(Func, Cls, Maj, Min, Msg, Ret);				\
 }
 #endif
 
@@ -1308,7 +1296,7 @@ H5FD_silo_sb_encode(H5FD_t *_file, char *name/*out*/,
     assert(sizeof(hsize_t)<=8);
     memcpy(p, &file->block_size, sizeof(hsize_t));
     if (H5Tconvert(H5T_NATIVE_HSIZE, H5T_STD_U64LE, 1, buf+8, NULL, H5P_DEFAULT)<0)
-        H5Epush_ret(func, H5E_ERR_CLS, H5E_DATATYPE, H5E_CANTCONVERT, "can't convert superblock info", -1)
+        H5Epush_ret(func, H5E_ERR_CLS, H5E_DATATYPE, H5E_CANTCONVERT, "can't convert superblock info", -1);
 
     return 0;
 }
@@ -1336,14 +1324,14 @@ H5FD_silo_sb_decode(H5FD_t *_file, const char *name, c
 
     /* Make sure the name/version number is correct */
     if (strcmp(name, "LLNLsilo"))
-        H5Epush_ret(func, H5E_ERR_CLS, H5E_FILE, H5E_BADVALUE, "invalid silo superblock", -1)
+        H5Epush_ret(func, H5E_ERR_CLS, H5E_FILE, H5E_BADVALUE, "invalid silo superblock", -1);
 
     buf += 8;
     /* Decode block size */
     assert(sizeof(hsize_t)<=8);
     memcpy(x, buf, 8);
     if (H5Tconvert(H5T_STD_U64LE, H5T_NATIVE_HSIZE, 1, x, NULL, H5P_DEFAULT)<0)
-        H5Epush_ret(func, H5E_ERR_CLS, H5E_DATATYPE, H5E_CANTCONVERT, "can't convert superblock info", -1)
+        H5Epush_ret(func, H5E_ERR_CLS, H5E_DATATYPE, H5E_CANTCONVERT, "can't convert superblock info", -1);
     ap = (hsize_t*)x;
     /*file->block_size = *ap; ignore stored value for now */
 
