# Correct type in a couple format strings
#
--- src/savage_video.c.orig	2017-01-17 22:43:40 UTC
+++ src/savage_video.c
@@ -303,10 +303,10 @@ unsigned int GetBlendForFourCC2000( int 
 
 void savageOUTREG( SavagePtr psav, unsigned long offset, unsigned long value )
 {
-    ErrorF( "MMIO %08lx, was %08lx, want %08lx,", 
+    ErrorF( "MMIO %08lx, was %08x, want %08lx,", 
 	offset, (CARD32)MMIO_IN32( psav->MapBase, offset ), value );
     MMIO_OUT32( psav->MapBase, offset, value );
-    ErrorF( " now %08lx\n", (CARD32)MMIO_IN32( psav->MapBase, offset ) );
+    ErrorF( " now %08x\n", (CARD32)MMIO_IN32( psav->MapBase, offset ) );
 }
 
 #if 0
