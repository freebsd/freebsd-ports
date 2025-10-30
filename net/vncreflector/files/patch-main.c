--- main.c.orig	2003-01-11 09:44:02 UTC
+++ main.c
@@ -464,7 +464,7 @@ static int init_screen_info(void)
 
 static int init_screen_info(void)
 {
-  union _LITTLE_ENDIAN {
+  union {
     CARD32 value32;
     CARD8 test;
   } little_endian;
