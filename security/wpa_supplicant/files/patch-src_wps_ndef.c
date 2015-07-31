--- src/wps/ndef.c.orig	2015-03-15 17:30:39 UTC
+++ src/wps/ndef.c
@@ -48,6 +48,8 @@ static int ndef_parse_record(const u8 *d
 		if (size < 6)
 			return -1;
 		record->payload_length = ntohl(*(u32 *)pos);
+		if (record->payload_length > size - 6)
+			return -1;
 		pos += sizeof(u32);
 	}
 
@@ -68,7 +70,8 @@ static int ndef_parse_record(const u8 *d
 	pos += record->payload_length;
 
 	record->total_length = pos - data;
-	if (record->total_length > size)
+	if (record->total_length > size ||
+	    record->total_length < record->payload_length)
 		return -1;
 	return 0;
 }
