--- src/input/input_cdda.c.orig	Sat Oct  4 01:35:54 2003
+++ src/input/input_cdda.c	Sat Nov 15 21:05:51 2003
@@ -32,6 +32,7 @@
 #include <unistd.h>
 
 #include <sys/types.h>
+#include <sys/param.h>
 #include <dirent.h>
 #include <sys/stat.h>
 #include <fcntl.h>
@@ -666,18 +667,26 @@
   unsigned char *data) {
 
   int fd = this_gen->fd;
+#if  __FreeBSD_version < 501106
   struct ioc_read_audio cdda;
+#endif
 
   while( num_frames ) {
+#if  __FreeBSD_version < 501106
     cdda.address_format = CD_MSF_FORMAT;
     cdda.address.msf.minute = frame / CD_SECONDS_PER_MINUTE / CD_FRAMES_PER_SECOND;
     cdda.address.msf.second = (frame / CD_FRAMES_PER_SECOND) % CD_SECONDS_PER_MINUTE;
     cdda.address.msf.frame = frame % CD_FRAMES_PER_SECOND;
     cdda.nframes = 1;
     cdda.buffer = data;
+#endif
 
+#if  __FreeBSD_version >= 501106
+    if (pread(fd, data, CD_RAW_FRAME_SIZE, frame * CD_RAW_FRAME_SIZE) != CD_RAW_FRAME_SIZE) {
+#else
     /* read a frame */
     if(ioctl(fd, CDIOCREADAUDIO, &cdda) < 0) {
+#endif
       perror("CDIOCREADAUDIO");
       return -1;
     }
