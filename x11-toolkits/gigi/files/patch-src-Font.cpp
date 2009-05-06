--- src/Font.cpp.orig	2009-04-13 08:50:10.000000000 +0200
+++ src/Font.cpp	2009-04-13 08:51:06.000000000 +0200
@@ -1218,7 +1218,7 @@
                     boost::uint8_t*  src = src_start + row * glyph_bitmap.pitch;
                     boost::uint16_t* dst = dst_start + (row + Value(y_offset)) * Value(BUF_WIDTH);
                     for (int col = 0; col < glyph_bitmap.width; ++col) {
-#ifdef __BIG_ENDIAN__
+#if (_BYTE_ORDER == _BIG_ENDIAN)
                         *dst++ = *src++ | (255 << 8); // big-endian uses different byte ordering
 #else
                         *dst++ = (*src++ << 8) | 255; // alpha is the value from glyph_bitmap; luminance is always 100% white
