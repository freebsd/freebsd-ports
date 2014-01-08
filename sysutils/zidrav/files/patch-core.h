--- core.h.orig	2005-05-19 22:58:40.000000000 +0200
+++ core.h	2014-01-07 06:40:24.000000000 +0100
@@ -48,7 +48,7 @@
 #define QSV		KSigver( ZQ, QVER )
 
 
-const long crc_table[256] = {		// it's just easier this way, alright? It's one K of data, I'm allowed a global if I want one
+const crc32_type crc_table[256] = {		// it's just easier this way, alright? It's one K of data, I'm allowed a global if I want one
   0x00000000L, 0x77073096L, 0xee0e612cL, 0x990951baL, 0x076dc419L,
   0x706af48fL, 0xe963a535L, 0x9e6495a3L, 0x0edb8832L, 0x79dcb8a4L,
   0xe0d5e91eL, 0x97d2d988L, 0x09b64c2bL, 0x7eb17cbdL, 0xe7b82d07L,
@@ -111,7 +111,6 @@
 int VerifyStream( istream &input, int datalen, int emsg, KSigver sigver );
 
 void MakeOverallChecksum( iostream &st, long size );
-void CreateChecksum( char *buffer, long size, unsigned long *crc );
-void CreateChecksum( char *buffer, long size, signed long *crc );
+void CreateChecksum( char *buffer, long size, crc32_type *crc );
 
 #endif
