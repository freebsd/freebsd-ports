--- dvdread/dvd_udf.c.orig	Fri May 25 08:31:22 2001
+++ dvdread/dvd_udf.c	Mon Jun 25 23:33:11 2001
@@ -461,8 +461,12 @@
     if( fd < 0 )
         return 0;
 
+#if defined(__FreeBSD__)    
+    lseek(fd, lb_number * DVD_VIDEO_LB_LEN, SEEK_SET);
+#else
     lseek64( fd, (int64_t) lb_number * (int64_t) DVD_VIDEO_LB_LEN, SEEK_SET );
-
+#endif
+    
     return read( fd, data, block_count * DVD_VIDEO_LB_LEN );
 }
 
