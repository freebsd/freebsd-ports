--- deattack.c	Tue Mar  5 01:53:05 2002
+++ deattack.c	Wed Sep 17 00:18:30 2003
@@ -100,12 +100,12 @@ detect_attack(u_char *buf, u_int32_t len
 
 	if (h == NULL) {
 		debug("Installing crc compensation attack detector.");
+		h = (u_int16_t *) xmalloc(l * HASH_ENTRYSIZE);
 		n = l;
-		h = (u_int16_t *) xmalloc(n * HASH_ENTRYSIZE);
 	} else {
 		if (l > n) {
+			h = (u_int16_t *) xrealloc(h, l * HASH_ENTRYSIZE);
 			n = l;
-			h = (u_int16_t *) xrealloc(h, n * HASH_ENTRYSIZE);
 		}
 	}
 
