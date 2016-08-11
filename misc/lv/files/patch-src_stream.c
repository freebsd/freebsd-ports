--- stream.c.orig	2003-11-13 03:08:19 UTC
+++ stream.c
@@ -43,6 +43,8 @@
 
 private byte *gz_filter = "zcat";
 private byte *bz2_filter = "bzcat";
+private byte *lzma_filter = "lzcat";
+private byte *xz_filter = "xzcat";
 
 private stream_t *StreamAlloc()
 {
@@ -75,6 +77,10 @@ public stream_t *StreamOpen( byte *file 
       filter = gz_filter;
     else if( !strcmp( "bz2", exts ) || !strcmp( "BZ2", exts ) )
       filter = bz2_filter;
+    else if( !strcmp( "lzma", exts ) || !strcmp( "LZMA", exts ) )
+      filter = lzma_filter;
+    else if( !strcmp( "xz", exts ) || !strcmp( "XZ", exts ) )
+      filter = xz_filter;
   }
   if( NULL != filter ){
     /*
