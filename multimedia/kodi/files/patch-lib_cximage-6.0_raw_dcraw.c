--- lib/cximage-6.0/raw/dcraw.c.orig	2015-03-26 18:25:20 UTC
+++ lib/cximage-6.0/raw/dcraw.c
@@ -820,7 +820,8 @@ struct jhead {
 
 int CLASS ljpeg_start (struct jhead *jh, int info_only)
 {
-  int c, tag, len;
+  int c, tag;
+  ushort len;
   uchar data[0x10000], *dp;
 
   init_decoder();
