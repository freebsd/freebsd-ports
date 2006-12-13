--- cbuffer.h.orig	Wed Dec 13 23:37:53 2006
+++ cbuffer.h	Wed Dec 13 23:38:06 2006
@@ -15,7 +15,7 @@
 		CBUFPTR		SearchStreamId(CBUFPTR ptr, int len, unsigned char pattern, unsigned char mask, unsigned char * p_id=0);
 		int		GetByteCount(void);
 		int             CopyBuffer(CBUFPTR ptr, unsigned char * pBuf, int len=16);
-		int 		CBuffer::RemovePadding(CBUFPTR lptr, int len);
+		int 		RemovePadding(CBUFPTR lptr, int len);
 		
 
 	private:
