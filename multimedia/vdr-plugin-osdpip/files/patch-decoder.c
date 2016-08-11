--- decoder.c.orig	2012-02-12 12:24:00 UTC
+++ decoder.c
@@ -55,13 +55,13 @@ int cDecoder::Close()
 {
 #ifndef USE_SWSCALE
     delete[] m_BufferConvert;
-    free(m_PicConvert);
+    av_free(m_PicConvert);
 #endif
     delete[] m_BufferResample;
-    free(m_PicResample);
+    av_free(m_PicResample);
     avcodec_close(m_Context);
-    free(m_Context);
-    free(m_PicDecoded);
+    av_free(m_Context);
+    av_free(m_PicDecoded);
 
     return 0;
 }
