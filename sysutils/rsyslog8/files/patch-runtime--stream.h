--- runtime/stream.h.ori	2013-05-24 20:21:51.000000000 -0600
+++ runtime/stream.h	2013-05-24 20:21:11.000000000 -0600
@@ -207,6 +207,6 @@
 
 /* prototypes */
 PROTOTYPEObjClassInit(strm);
-rsRetVal strmMultiFileSeek(strm_t *pThis, int fileNum, off64_t offs, off64_t *bytesDel);
+rsRetVal strmMultiFileSeek(strm_t *pThis, int fileNum, off_t offs, off_t *bytesDel);
 
 #endif /* #ifndef STREAM_H_INCLUDED */
