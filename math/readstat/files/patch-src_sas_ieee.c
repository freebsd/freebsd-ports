--- src/sas/ieee.c.orig	2023-02-19 12:37:34 UTC
+++ src/sas/ieee.c
@@ -16,7 +16,7 @@ static void ieee2xpt(unsigned char *ieee, unsigned cha
 
 #ifndef FLOATREP
 #define FLOATREP get_native()
-int get_native();
+int get_native(void);
 #endif
 
 void memreverse(void *intp_void, int l) {
