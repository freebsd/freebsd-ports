--- lavtools/liblavrec.c.orig
+++ lavtools/liblavrec.c
@@ -45,9 +45,14 @@
 #include <sys/time.h>
 #include <sys/resource.h>
 #include <sys/wait.h>
+#ifdef __linux
 #include <sys/statfs.h>
-#include <mjpeg_types.h>
 #include <sys/vfs.h>
+#else
+#include <sys/param.h>
+#include <sys/mount.h>
+#endif
+#include <mjpeg_types.h>
 #include <stdlib.h>
 
 /* Because of some really cool feature in video4linux1, also known as
@@ -758,7 +763,11 @@
    {
 	   int fd = lav_fileno( settings->video_file );
 	   if( fd >= 0 )
+#ifdef __linux
 		   fdatasync(fd);
+#else
+		   fsync(fd);
+#endif
    }
    return 1;
 }
