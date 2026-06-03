--- mpifileutils/src/common/mfu_flist_copy.c.orig	2025-02-19 22:20:52 UTC
+++ mpifileutils/src/common/mfu_flist_copy.c
@@ -39,8 +39,10 @@
 #include <sys/ioctl.h>
 #include <sys/param.h>
 
+#ifdef __linux__
 #include <linux/fs.h>
 #include <linux/fiemap.h>
+#endif
 
 /* define PRI64 */
 #include <inttypes.h>
@@ -69,8 +71,10 @@
 #endif
 
 #ifdef HPSS_SUPPORT
+#ifdef __linux__
 #include <linux/hpssfs.h>
 #endif
+#endif
 
 /****************************************
  * Define types
@@ -1864,6 +1868,7 @@ static int mfu_copy_file_normal(
     return 0;
 }
 
+#ifdef __linux__
 static int mfu_copy_file_fiemap(
     const char* src,
     const char* dest,
@@ -2053,6 +2058,7 @@ fail_normal_copy:
 fail_normal_copy:
     return -1;
 }
+#endif
 
 static int mfu_copy_file(
     const char* src,
@@ -2084,6 +2090,7 @@ static int mfu_copy_file(
         return -1;
     }
 
+#ifdef __linux__
     if (copy_opts->sparse) {
         bool normal_copy_required;
         ret = mfu_copy_file_fiemap(src, dest, offset, length, file_size,
@@ -2093,6 +2100,7 @@ static int mfu_copy_file(
             return ret;
         }
     }
+#endif
 
     ret = mfu_copy_file_normal(src, dest, offset, length, file_size,
                                copy_opts, mfu_src_file, mfu_dst_file);
