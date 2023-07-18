--- ccan/ccan/base64/base64.c.orig	2023-07-18 11:01:33 UTC
+++ ccan/ccan/base64/base64.c
@@ -31,7 +31,7 @@ static int8_t sixbit_from_b64(const base64_maps_t *map
 	int8_t ret;
 
 	ret = maps->decode_map[(unsigned char)b64letter];
-	if (ret == (char)0xff) {
+	if (ret == -1) {
 		errno = EDOM;
 		return -1;
 	}
@@ -41,7 +41,7 @@ bool base64_char_in_alphabet(const base64_maps_t *maps
 
 bool base64_char_in_alphabet(const base64_maps_t *maps, const char b64char)
 {
-	return (maps->decode_map[(const unsigned char)b64char] != (char)0xff);
+	return (maps->decode_map[(const unsigned char)b64char] != -1);
 }
 
 void base64_init_maps(base64_maps_t *dest, const char src[64])
@@ -49,7 +49,7 @@ void base64_init_maps(base64_maps_t *dest, const char 
 	unsigned char i;
 
 	memcpy(dest->encode_map,src,64);
-	memset(dest->decode_map,0xff,256);
+	memset(dest->decode_map,-1,256);
 	for (i=0; i<64; i++) {
 		dest->decode_map[(unsigned char)src[i]] = i;
 	}
