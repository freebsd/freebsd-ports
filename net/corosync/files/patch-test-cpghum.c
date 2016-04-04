--- test/cpghum.c.orig	2015-06-22 14:03:28 UTC
+++ test/cpghum.c
@@ -116,7 +116,7 @@ static void cpg_bm_deliver_fn (
 {
 	int *value = msg;
 	uLong crc=0;
-	ulong recv_crc = value[1] & 0xFFFFFFFF;
+	uLong recv_crc = value[1] & 0xFFFFFFFF;
 
 	packets_recvd++;
 	g_recv_length = msg_len;
