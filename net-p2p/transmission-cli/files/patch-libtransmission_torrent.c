Index: /branches/0.8x/libtransmission/torrent.c
===================================================================
--- /branches/0.8x/libtransmission/torrent.c (revision 2573)
+++ libtransmission/torrent.c (revision 2650)
@@ -736,6 +736,6 @@
     assert( 0<=fileIndex && fileIndex<tor->info.fileCount );
     assert( file->offset + file->length <= tor->info.totalSize );
-    assert( (int)firstBlock < tor->blockCount );
-    assert( (int)lastBlock < tor->blockCount );
+    assert( ( (int)firstBlock < tor->blockCount ) || (!file->length && file->offset==tor->info.totalSize) );
+    assert( ( (int)lastBlock < tor->blockCount ) || (!file->length && file->offset==tor->info.totalSize) );
     assert( firstBlock <= lastBlock );
     assert( (int)tr_torBlockPiece( tor, firstBlock ) == file->firstPiece );
