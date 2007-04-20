--- disktool.c.orig	Fri Oct 28 14:10:55 2005
+++ disktool.c	Fri Oct 28 14:13:09 2005
@@ -168,9 +168,9 @@
 }
 
 /* ==========================================================================*/
-long kbytes(blocks, blocksize)
-     long blocks;
-     long blocksize;
+int64_t kbytes(blocks, blocksize)
+     int64_t blocks;
+     uint64_t blocksize;
 {
   /* Return number of kilobytes given the number of blocks and the block size.
      This isn't quite trivial because a 32 bit signed long integer could easily
