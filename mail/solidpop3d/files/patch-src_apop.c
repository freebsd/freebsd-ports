--- src/apop.c.orig	Tue Nov  7 09:00:11 2000
+++ src/apop.c	Tue Nov  7 09:02:38 2000
@@ -26,11 +26,15 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 
+#define md5_finish_ctx(ctx, dig) MD5Final((unsigned char *)dig, ctx)
+#define md5_init_ctx(ctx) MD5Init(ctx)
+#define md5_process_bytes(buf, len, ctx) MD5Update (ctx, (unsigned char *)buf, len)
+
 extern char apop_secret[];
 
 int apop_authenticate(char *username, char *apoptimestamp, char *udigest) {
 	char adigest[16], digest[16];
-	struct md5_ctx context;
+	MD5_CTX context;
 	int tmp;
 	
 	for (tmp = 0; tmp < 16; tmp++) {
