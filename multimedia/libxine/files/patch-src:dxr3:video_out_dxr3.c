--- src/dxr3/video_out_dxr3.c.orig	Sat Feb  1 22:26:00 2003
+++ src/dxr3/video_out_dxr3.c	Sat Feb  1 22:26:38 2003
@@ -278,7 +278,7 @@
   }
   
   snprintf (tmpstr, sizeof(tmpstr), "%s_mv%s", class->devname, class->devnum);
-  if ((this->fd_video = open (tmpstr, O_WRONLY | O_SYNC )) < 0) {
+  if ((this->fd_video = open (tmpstr, O_WRONLY | O_FSYNC )) < 0) {
     printf("video_out_dxr3: Failed to open video device %s (%s)\n",
       tmpstr, strerror(errno));
     return 0;
