--- src/parser/GifParser.cc.orig	2006-11-17 07:24:49 UTC
+++ src/parser/GifParser.cc
@@ -81,7 +81,11 @@ GifParser::GifParser(Message *message,
 GifParser::~GifParser()
 {
   if (m_gif) {
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+    DGifCloseFile(m_gif, NULL);
+#else
     DGifCloseFile(m_gif);
+#endif
   }
 }
 
@@ -99,7 +103,11 @@ bool GifParser::parseImage()
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
