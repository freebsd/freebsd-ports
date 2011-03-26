--- a/recplayer.c
+++ b/recplayer.c
@@ -189,8 +189,10 @@ unsigned long cRecPlayer::getBlock(unsig
     fseek(m_file, filePosition, SEEK_SET);
     fread(&buffer[got], getFromThisSegment, 1, m_file);
 
+#ifndef __FreeBSD__
     // Tell linux not to bother keeping the data in the FS cache
     posix_fadvise(m_file->_fileno, filePosition, getFromThisSegment, POSIX_FADV_DONTNEED);
+#endif
 
     got += getFromThisSegment;
     currentPosition += getFromThisSegment;
