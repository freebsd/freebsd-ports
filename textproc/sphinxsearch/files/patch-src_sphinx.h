--- src/sphinx.h.orig	2018-02-03 10:16:36 UTC
+++ src/sphinx.h
@@ -433,7 +433,7 @@ class CSphLowercaser (public)
 	{
 		if ( iCode<0 || iCode>=MAX_CODE )
 			return iCode;
-		register int * pChunk = m_pChunk [ iCode >> CHUNK_BITS ];
+		int * pChunk = m_pChunk [ iCode >> CHUNK_BITS ];
 		if ( pChunk )
 			return pChunk [ iCode & CHUNK_MASK ];
 		return 0;
