--- src/sas/ieee.c.orig	2023-02-20 19:09:20 UTC
+++ src/sas/ieee.c
@@ -96,7 +96,7 @@ int cnxptiee(const void *from_bytes, int fromtype, voi
     return(0);
 }
 
-int get_native() {
+int get_native(void) {
     static unsigned char float_reps[][8] = {
         {0x41,0x10,0x00,0x00,0x00,0x00,0x00,0x00},
         {0x3f,0xf0,0x00,0x00,0x00,0x00,0x00,0x00},
