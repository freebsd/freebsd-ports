--- src/sas/ieee.c.orig	2018-12-15 15:27:55 UTC
+++ src/sas/ieee.c
@@ -16,7 +16,7 @@ static void ieee2xpt(unsigned char *ieee, unsigned cha
 
 #ifndef FLOATREP
 #define FLOATREP get_native()
-int get_native();
+int get_native(void);
 #endif
 
 void memreverse(void *intp_void, int l) {
@@ -96,7 +96,7 @@ int cnxptiee(const void *from_bytes, int fromtype, voi
     return(0);
 }
 
-int get_native() {
+int get_native(void) {
     static unsigned char float_reps[][8] = {
         {0x41,0x10,0x00,0x00,0x00,0x00,0x00,0x00},
         {0x3f,0xf0,0x00,0x00,0x00,0x00,0x00,0x00},
