--- src/tcs/tcs_aik.c.orig	2014-04-24 18:05:44 UTC
+++ src/tcs/tcs_aik.c
@@ -66,7 +66,7 @@ UnloadBlob_SYMMETRIC_KEY(UINT64 *offset,
 	UnloadBlob_UINT16(offset, &key->size, blob);
 
 	if (key->size > 0) {
-		key->data = (BYTE *)malloc(key->size);
+		key->data = malloc(key->size);
 		if (key->data == NULL) {
 			LogError("malloc of %hu bytes failed.", key->size);
 			key->size = 0;
