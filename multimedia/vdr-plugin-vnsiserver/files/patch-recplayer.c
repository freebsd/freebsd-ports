--- a/recplayer.c
+++ b/recplayer.c
@@ -34,6 +34,10 @@
 #include <sys/stat.h>
 #include <unistd.h>
 
+#ifndef O_NOATIME
+#define O_NOATIME 0
+#endif
+
 cRecPlayer::cRecPlayer(cRecording* rec)
 {
   m_file          = -1;
@@ -199,8 +203,10 @@ int cRecPlayer::getBlock(unsigned char* 
     return 0;
   }
 
+#ifndef __FreeBSD__
   // Tell linux not to bother keeping the data in the FS cache
   posix_fadvise(m_file, filePosition, bytes_read, POSIX_FADV_DONTNEED);
+#endif
 
   // divide and conquer
   if(bytes_read < amount) {
