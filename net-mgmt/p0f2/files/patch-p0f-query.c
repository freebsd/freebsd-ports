--- p0f-query.c.orig	2021-09-08 15:25:07 UTC
+++ p0f-query.c
@@ -46,8 +46,8 @@ static _u16 flags;
 static _s16 score = NO_SCORE;
 
 /* Imports for statistics */
-_u32 packet_count, matched_packets, st_time, file_cksum;
-_u8  operating_mode;
+extern _u32 packet_count, matched_packets, st_time, file_cksum;
+extern _u8  operating_mode;
 
 #define SAD_HASH(a)	((((a) << 16) ^ ((a) << 8) ^ (a)))
 
