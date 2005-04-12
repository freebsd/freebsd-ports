
$FreeBSD$

--- esm_cipher.c.orig
+++ esm_cipher.c
@@ -157,7 +157,7 @@
 	unsigned int n;
 	int i;
 	struct timeval tv;
-	unsigned long truerand();
+	uint32_t truerand();
 	unsigned char b[20];
 	
 	R_RandomInit(&rs);
