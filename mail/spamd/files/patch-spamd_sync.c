# PR: 235496
# patch id: 201721
#
--- spamd/sync.c.orig	2010-04-24 10:33:47 UTC
+++ spamd/sync.c
@@ -53,6 +53,22 @@ extern char   *SHA1_File(const char *, char *);
 
 #include <openssl/hmac.h>
 
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+# define spamd_hmac_ctx HMAC_CTX *
+# define spamd_hmac_ctx_init(ctx) ctx = HMAC_CTX_new()
+# define spamd_hmac_sha1_init(ctx, key, keylen) HMAC_Init_ex(ctx, key, keylen, EVP_sha1(), NULL)
+# define spamd_hmac_update(ctx, data, datalen) HMAC_Update(ctx, data, datalen)
+# define spamd_hmac_final(ctx, data, datalen) HMAC_Final(ctx, data, datalen)
+# define spamd_hmac_cleanup(ctx) HMAC_CTX_free(ctx)
+#else
+# define spamd_hmac_ctx HMAC_CTX
+# define spamd_hmac_ctx_init(ctx) HMAC_CTX_init(&(ctx))
+# define spamd_hmac_sha1_init(ctx, key, keylen) HMAC_Init_ex(&(ctx), key, keylen, EVP_sha1(), NULL)
+# define spamd_hmac_update(ctx, data, datalen) HMAC_Update(&(ctx), data, datalen)
+# define spamd_hmac_final(ctx, data, datalen) HMAC_Final(&(ctx), data, datalen)
+# define spamd_hmac_cleanup(ctx) HMAC_cleanup(&(ctx))
+#endif
+
 #include "sdl.h"
 #include "grey.h"
 #include "sync.h"
@@ -439,7 +455,7 @@ sync_update(time_t now, char *helo, char *ip, char *fr
 	u_int16_t sglen, fromlen, tolen, helolen, padlen;
 	char pad[SPAM_ALIGNBYTES];
 	int i = 0;
-	HMAC_CTX ctx;
+	spamd_hmac_ctx ctx;
 	u_int hmac_len;
 
 	if (debug)
@@ -455,8 +471,8 @@ sync_update(time_t now, char *helo, char *ip, char *fr
 	tolen = strlen(to) + 1;
 	helolen = strlen(helo) + 1;
 
-	HMAC_CTX_init(&ctx);
-	HMAC_Init(&ctx, sync_key, strlen(sync_key), EVP_sha1());
+	spamd_hmac_ctx_init(ctx);
+	spamd_hmac_sha1_init(ctx, sync_key, strlen(sync_key));
 
 	sglen = sizeof(sg) + fromlen + tolen + helolen;
 	padlen = SPAM_ALIGN(sglen) - sglen;
@@ -468,7 +484,7 @@ sync_update(time_t now, char *helo, char *ip, char *fr
 	hdr.sh_length = htons(sizeof(hdr) + sglen + padlen + sizeof(end));
 	iov[i].iov_base = &hdr;
 	iov[i].iov_len = sizeof(hdr);
-	HMAC_Update(&ctx, iov[i].iov_base, iov[i].iov_len);
+	spamd_hmac_update(ctx, iov[i].iov_base, iov[i].iov_len);
 	i++;
 
 	/* Add single SPAM sync greylisting entry */
@@ -481,27 +497,27 @@ sync_update(time_t now, char *helo, char *ip, char *fr
 	sg.sg_helo_length = htons(helolen);
 	iov[i].iov_base = &sg;
 	iov[i].iov_len = sizeof(sg);
-	HMAC_Update(&ctx, iov[i].iov_base, iov[i].iov_len);
+	spamd_hmac_update(ctx, iov[i].iov_base, iov[i].iov_len);
 	i++;
 
 	iov[i].iov_base = from;
 	iov[i].iov_len = fromlen;
-	HMAC_Update(&ctx, iov[i].iov_base, iov[i].iov_len);
+	spamd_hmac_update(ctx, iov[i].iov_base, iov[i].iov_len);
 	i++;
 
 	iov[i].iov_base = to;
 	iov[i].iov_len = tolen;
-	HMAC_Update(&ctx, iov[i].iov_base, iov[i].iov_len);
+	spamd_hmac_update(ctx, iov[i].iov_base, iov[i].iov_len);
 	i++;
 
 	iov[i].iov_base = helo;
 	iov[i].iov_len = helolen;
-	HMAC_Update(&ctx, iov[i].iov_base, iov[i].iov_len);
+	spamd_hmac_update(ctx, iov[i].iov_base, iov[i].iov_len);
 	i++;
 
 	iov[i].iov_base = pad;
 	iov[i].iov_len = padlen;
-	HMAC_Update(&ctx, iov[i].iov_base, iov[i].iov_len);
+	spamd_hmac_update(ctx, iov[i].iov_base, iov[i].iov_len);
 	i++;
 
 	/* Add end marker */
@@ -509,14 +525,14 @@ sync_update(time_t now, char *helo, char *ip, char *fr
 	end.st_length = htons(sizeof(end));
 	iov[i].iov_base = &end;
 	iov[i].iov_len = sizeof(end);
-	HMAC_Update(&ctx, iov[i].iov_base, iov[i].iov_len);
+	spamd_hmac_update(ctx, iov[i].iov_base, iov[i].iov_len);
 	i++;
 
-	HMAC_Final(&ctx, hdr.sh_hmac, &hmac_len);
+	spamd_hmac_final(ctx, hdr.sh_hmac, &hmac_len);
 
 	/* Send message to the target hosts */
 	sync_send(iov, i);
-	HMAC_CTX_cleanup(&ctx);
+	spamd_hmac_cleanup(ctx);
 }
 
 void
@@ -527,7 +543,7 @@ sync_addr(time_t now, time_t expire, char *ip, u_int16
 	struct spam_synctlv_addr sd;
 	struct spam_synctlv_hdr end;
 	int i = 0;
-	HMAC_CTX ctx;
+	spamd_hmac_ctx ctx;
 	u_int hmac_len;
 
 	if (debug)
@@ -537,8 +553,8 @@ sync_addr(time_t now, time_t expire, char *ip, u_int16
 	bzero(&hdr, sizeof(hdr));
 	bzero(&sd, sizeof(sd));
 
-	HMAC_CTX_init(&ctx);
-	HMAC_Init(&ctx, sync_key, strlen(sync_key), EVP_sha1());
+	spamd_hmac_ctx_init(ctx);
+	spamd_hmac_sha1_init(ctx, sync_key, strlen(sync_key));
 
 	/* Add SPAM sync packet header */
 	hdr.sh_version = SPAM_SYNC_VERSION;
@@ -547,7 +563,7 @@ sync_addr(time_t now, time_t expire, char *ip, u_int16
 	hdr.sh_length = htons(sizeof(hdr) + sizeof(sd) + sizeof(end));
 	iov[i].iov_base = &hdr;
 	iov[i].iov_len = sizeof(hdr);
-	HMAC_Update(&ctx, iov[i].iov_base, iov[i].iov_len);
+	spamd_hmac_update(ctx, iov[i].iov_base, iov[i].iov_len);
 	i++;
 
 	/* Add single SPAM sync address entry */
@@ -558,7 +574,7 @@ sync_addr(time_t now, time_t expire, char *ip, u_int16
 	sd.sd_ip = inet_addr(ip);
 	iov[i].iov_base = &sd;
 	iov[i].iov_len = sizeof(sd);
-	HMAC_Update(&ctx, iov[i].iov_base, iov[i].iov_len);
+	spamd_hmac_update(ctx, iov[i].iov_base, iov[i].iov_len);
 	i++;
 
 	/* Add end marker */
@@ -566,14 +582,14 @@ sync_addr(time_t now, time_t expire, char *ip, u_int16
 	end.st_length = htons(sizeof(end));
 	iov[i].iov_base = &end;
 	iov[i].iov_len = sizeof(end);
-	HMAC_Update(&ctx, iov[i].iov_base, iov[i].iov_len);
+	spamd_hmac_update(ctx, iov[i].iov_base, iov[i].iov_len);
 	i++;
 
-	HMAC_Final(&ctx, hdr.sh_hmac, &hmac_len);
+	spamd_hmac_final(ctx, hdr.sh_hmac, &hmac_len);
 
 	/* Send message to the target hosts */
 	sync_send(iov, i);
-	HMAC_CTX_cleanup(&ctx);
+	spamd_hmac_cleanup(ctx);
 }
 
 void
