--- src/parser/GifParser.cc.orig	2006-11-17 07:24:49 UTC
+++ src/parser/GifParser.cc
@@ -99,7 +99,11 @@ bool GifParser::parseImage()
 void GifParser::openImage()
 {
   m_nextByteIndex = 0;
+#if GIFLIB_MAJOR >= 5
+  m_gif = DGifOpen(this, readFromBuffer, NULL);
+#else
   m_gif = DGifOpen(this, readFromBuffer);
+#endif
   if (!m_gif) {
     throw runtime_error("open gif failed");
   }
