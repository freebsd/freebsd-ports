Index: src/mail.c
diff -u src/mail.c.orig src/mail.c
--- src/mail.c.orig	Sat Dec 13 02:26:21 2003
+++ src/mail.c	Sat Dec 13 14:35:20 2003
@@ -72,11 +72,17 @@
 # endif
 #endif
 
+#if defined(HAVE_SSL)
+#define MD5Init		MD5_Init
+#define MD5Update	MD5_Update
+#define MD5Final	MD5_Final
+#else
 #if defined(HAVE_MD5_H)
 #include <md5.h>
 #else
 #include "md5.h"
 #endif
+#endif
 
 #define MUTE_FLAG	-1
 
@@ -654,7 +660,7 @@
 	unsigned char opad[64];
 	unsigned char hash_passwd[16];
 
-	MD5_CTX_ ctx;
+	MD5_CTX ctx;
     
 	if (resp_len != 16)
 		return;
@@ -846,7 +852,7 @@
 	if (account->authtype == AUTH_POP3_APOP)
 		{
 		static const gchar hex[] = "0123456789abcdef";
-		MD5_CTX_ ctx;
+		MD5_CTX ctx;
 		gint	i;
 		gchar	*key, *p;
 		guchar	digest[16];
