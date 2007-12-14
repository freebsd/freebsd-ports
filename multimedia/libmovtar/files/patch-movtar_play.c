--- movtar_play.c.orig	2007-12-12 22:22:44.000000000 +0100
+++ movtar_play.c	2007-12-12 22:27:09.000000000 +0100
@@ -141,9 +141,9 @@
 #if defined(__GNUC__)
 #define int64 unsigned long long
 #endif
-static const int64 te0 = 0x0080008000800080; // -128 << 2
-static const int64 te1 = 0xe9fa7168e9fa7168; // for cb 
-static const int64 te2 = 0x59bad24d59bad24d; // for cr
+static const int64 te0 = 0x0080008000800080ULL; // -128 << 2
+static const int64 te1 = 0xe9fa7168e9fa7168ULL; // for cb 
+static const int64 te2 = 0x59bad24d59bad24dULL; // for cr
 
 METHODDEF(void)
 ycc_rgb32_convert_mmx (j_decompress_ptr cinfo,
@@ -263,9 +263,9 @@
   asm ("emms");
 }
 
-static int64 rb16mask = 0x00f800f800f800f8; // just red and blue remain
-static int64 rb16mult = 0x2000000820000008; // mult/Add factor (see intel appnote 553)
-static int64 g16mask = 0x0000f8000000f800; // just green remains
+static int64 rb16mask = 0x00f800f800f800f8ULL; // just red and blue remain
+static int64 rb16mult = 0x2000000820000008ULL; // mult/Add factor (see intel appnote 553)
+static int64 g16mask = 0x0000f8000000f800ULL; // just green remains
 static int64 rgb16offset = 6; // shift right after the whole stuff
 static const int64 shiftmask = 0xffff; // shift right after the whole stuff
 
