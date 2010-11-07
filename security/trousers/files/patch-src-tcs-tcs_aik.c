--- src/tcs/tcs_aik.c.orig	2010-06-10 05:20:44.000000000 +0900
+++ src/tcs/tcs_aik.c	2010-10-24 21:04:04.834556754 +0900
@@ -66,7 +66,7 @@
 	UnloadBlob_UINT16(offset, &key->size, blob);
 
 	if (key->size > 0) {
-		key->data = (BYTE *)malloc(key->size);
+		key->data = malloc(key->size);
 		if (key->data == NULL) {
 			LogError("malloc of %hu bytes failed.", key->size);
 			key->size = 0;
