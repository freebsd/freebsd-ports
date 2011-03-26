--- server/recplayer.c.orig
+++ server/recplayer.c
@@ -196,8 +196,10 @@ unsigned long RecPlayer::getBlock(unsign
     fseek(file, filePosition, SEEK_SET);
     if (fread(&buffer[got], getFromThisSegment, 1, file) != 1) return 0; // umm, big problem.
 
+#ifdef __linux__
     // Tell linux not to bother keeping the data in the FS cache
     posix_fadvise(file->_fileno, filePosition, getFromThisSegment, POSIX_FADV_DONTNEED);
+#endif
 
     got += getFromThisSegment;
     currentPosition += getFromThisSegment;
