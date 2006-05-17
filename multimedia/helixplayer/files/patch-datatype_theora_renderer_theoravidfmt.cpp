--- datatype/theora/renderer/theoravidfmt.cpp.orig	Wed Nov 24 19:29:04 2004
+++ datatype/theora/renderer/theoravidfmt.cpp	Sat Mar 26 15:46:37 2005
@@ -244,7 +244,7 @@
 }
 
 static
-void CopyPixelData(REF(UINT8*) pDest, char* pSrc, UINT32 width, UINT32 height, 
+void CopyPixelData(REF(UINT8*) pDest, unsigned char* pSrc, UINT32 width, UINT32 height, 
 		   int stride)
 {
     for (int i = 0; i < height; i++)
@@ -256,7 +256,7 @@
 }
 
 static
-void CopyAndStretchX(REF(UINT8*) pDest, const char* pSrc, 
+void CopyAndStretchX(REF(UINT8*) pDest, unsigned char* pSrc, 
                      UINT32 uWidth, UINT32 uHeight, int stride,
                      UINT32 uAspectNum, UINT32 uAspectDen,
                      UINT32 uAdjustedWidth,
@@ -303,7 +303,7 @@
 }
 
 static
-void CopyAndStretchY(REF(UINT8*) pDest, const char* pSrc, 
+void CopyAndStretchY(REF(UINT8*) pDest, unsigned char* pSrc, 
                      UINT32 uWidth, UINT32 uHeight, int stride,
                      UINT32 uAspectNum, UINT32 uAspectDen,
                      UINT32 uAdjustedHeight,
