diff -ubwr video/grabber-video4linux.cpp ../../test/vic-2.8ucl1.1.6/video/grabber-video4linux.cpp
--- video/grabber-video4linux.cpp	Fri Sep 12 19:36:19 2003
+++ ../../test/vic-2.8ucl1.1.6/video/grabber-video4linux.cpp	Fri Feb  9 16:15:12 2007
@@ -36,7 +36,7 @@
 
 
 extern "C" {
-#include <asm/types.h>
+//#include <asm/types.h>
 #include <linux/videodev.h>
 }
 
@@ -312,9 +314,20 @@
     }
 
     if( !( have_422P || have_422 || have_420P))   {
-      debug_msg("No suituable palette found\n");
+      debug_msg("No suituable palette found, try normal\n");
+	/* this needs to cleaned up heavily */
+      have_420P = 1;	/* assume no mmap and try 420 is default */
+      struct video_picture vp;
+      if(ioctl(fd_,VIDIOCGPICT,&vp) == -1) {
+	debug_msg("Failed to get current picture info");
       exit(1);
     }
+      vp.palette = VIDEO_PALETTE_YUV420P;
+      if(ioctl(fd_,VIDIOCSPICT,&vp) == -1) {
+	debug_msg("Failed to set current picture info");
+	exit(1);
+      }
+    }
 
     /* Release device */
     close(fd_);
@@ -551,10 +564,15 @@
     Grabber::stop();
 }
 
+/*
+ * quick hack - support only a single device of this kind,
+ * with a static max-sized buffer for reads.
+ */
+static char buf1[1024*768*3/2];
+
 int V4lGrabber::grab()
 {
     char  *fr=NULL;
-
     debug_msg((sync_count % 2) ? "o" : "e");
 
     if (have_mmap) {
@@ -566,6 +584,8 @@
 	else
 	    sync_count++;
     } else {
+	read(fd_, buf1, (size_t)height_*width_*3/2);
+	fr = buf1;
 	/* FIXME: read() */
     }
 
