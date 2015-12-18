--- crypto.h.orig	2004-05-14 10:42:56.000000000 +0200
+++ crypto.h	2015-02-28 13:01:05.491296206 +0100
@@ -108,7 +108,7 @@
 	u_int8_t        iv2[MAXBLK];
 	u_int8_t       *riv, *liv;
 	union {
-		des_key_schedule desks[3];
+		DES_key_schedule desks[3];
 #ifdef USE_BLOWFISH
 		blf_ctx         blfks;
 #endif
