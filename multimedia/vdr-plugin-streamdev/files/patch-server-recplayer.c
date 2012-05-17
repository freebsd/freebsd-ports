--- server/recplayer.c.orig
+++ server/recplayer.c
@@ -199,8 +199,10 @@ unsigned long RecPlayer::getBlock(unsign
     fseek(file, filePosition, SEEK_SET);
     if (fread(&buffer[got], getFromThisSegment, 1, file) != 1) return 0; // umm, big problem.
 
+#ifdef __linux__
     // Tell linux not to bother keeping the data in the FS cache
     posix_fadvise(fileno(file), filePosition, getFromThisSegment, POSIX_FADV_DONTNEED);
+#endif
 
     got += getFromThisSegment;
     currentPosition += getFromThisSegment;
