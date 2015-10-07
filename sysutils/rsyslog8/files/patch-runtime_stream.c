--- runtime/stream.c.orig	2015-06-30 12:26:24 UTC
+++ runtime/stream.c
@@ -1097,12 +1097,30 @@ doWriteCall(strm_t *pThis, uchar *pBuf, 
 	char *pWriteBuf;
 	DEFiRet;
 	ISOBJ_TYPE_assert(pThis, strm);
+#ifdef __FreeBSD__
+	sbool crnlNow = 0;
+#endif /* __FreeBSD__ */
 
 	lenBuf = *pLenBuf;
 	pWriteBuf = (char*) pBuf;
 	iTotalWritten = 0;
 	do {
+#ifdef __FreeBSD__
+		if (pThis->bIsTTY && !pThis->iZipLevel && !pThis->cryprov) {
+			char *pNl = NULL;
+			if (crnlNow == 0) pNl = strchr(pWriteBuf, '\n');
+			else crnlNow = 0;
+			if (pNl == pWriteBuf) {
+		  		iWritten = write(pThis->fd, "\r", 1);
+		  		if (iWritten > 0) {
+		      			crnlNow = 1;
+		      			iWritten = 0;
+		    		}
+		  	} else iWritten = write(pThis->fd, pWriteBuf, pNl ? pNl - pWriteBuf : lenBuf);
+		} else
+#endif /* __FreeBSD__ */
 		iWritten = write(pThis->fd, pWriteBuf, lenBuf);
+	
 		if(iWritten < 0) {
 			char errStr[1024];
 			int err = errno;
