--- a/src/recordings/recplayer.c
+++ b/src/recordings/recplayer.c
@@ -36,6 +36,10 @@
 
 #include "config/config.h"
 
+#ifndef O_NOATIME
+#define O_NOATIME 0
+#endif
+
 cRecPlayer::cRecPlayer(cRecording* rec)
 {
   m_file          = -1;
@@ -220,8 +220,10 @@ int cRecPlayer::getBlock(unsigned char* 
     return 0;
   }
 
+#ifndef __FreeBSD__
   // Tell linux not to bother keeping the data in the FS cache
   posix_fadvise(m_file, filePosition, bytes_read, POSIX_FADV_DONTNEED);
+#endif
 
   // divide and conquer
   if(bytes_read < amount) {
