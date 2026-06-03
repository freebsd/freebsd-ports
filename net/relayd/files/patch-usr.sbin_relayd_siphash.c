--- usr.sbin/relayd/siphash.c.orig	2025-09-02 11:44:37 UTC
+++ usr.sbin/relayd/siphash.c
@@ -64,8 +64,8 @@ SipHash_Init(SIPHASH_CTX *ctx, const SIPHASH_KEY *key)
 	uint64_t k0, k1;
 
 #ifdef __FreeBSD__
-	k0 = le64toh(&key->k0);
-	k1 = le64toh(&key->k1);
+	k0 = le64toh(key->k0);
+	k1 = le64toh(key->k1);
 #else
 	k0 = lemtoh64(&key->k0);
 	k1 = lemtoh64(&key->k1);
@@ -191,7 +191,7 @@ SipHash_CRounds(SIPHASH_CTX *ctx, int rounds)
 SipHash_CRounds(SIPHASH_CTX *ctx, int rounds)
 {
 #ifdef __FreeBSD__
-	u_int64_t m = le64toh((u_int64_t *)ctx->buf);
+	u_int64_t m = le64toh((u_int64_t)ctx->buf);
 #else
 	u_int64_t m = lemtoh64((u_int64_t *)ctx->buf);
 #endif
