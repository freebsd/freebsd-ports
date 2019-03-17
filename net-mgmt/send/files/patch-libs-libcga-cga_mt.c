--- libs/libcga/cga_mt.c.orig	2019-02-27 16:25:45 UTC
+++ libs/libcga/cga_mt.c
@@ -77,10 +77,10 @@ SPIN(void)
 static int
 add_mod(uint8_t *m, uint32_t s)
 {
-	BIGNUM bn[1], *bnp;
+	BIGNUM *bn, *bnp;
 	int blen;
 
-	BN_init(bn);
+	bn = BN_new();
 	if ((bnp = BN_bin2bn(m, CGA_MODLEN, bn)) == NULL) {
 		ssl_err(__FUNCTION__, "BN_bin2bin failed");
 		return (-1);
@@ -88,6 +88,7 @@ add_mod(uint8_t *m, uint32_t s)
 	BN_add_word(bnp, s);
 	blen = BN_num_bytes(bnp);
 	BN_bn2bin(bnp, m + (CGA_MODLEN - blen));
+	BN_free(bn);
 
 	return (0);
 }
@@ -177,12 +178,16 @@ done:
 static void
 opssec(struct timeval *start, uint8_t *startmod)
 {
-	BIGNUM sm[1], em[1], ops[1], t[1], dv[1];
+	BIGNUM *sm, *em, *ops, *t, *dv;
 	BN_CTX *bc;
 	struct timeval tv[1];
 	char *dec;
 
-	BN_init(sm); BN_init(em); BN_init(ops); BN_init(t); BN_init(dv);
+	sm = BN_new();
+	em = BN_new();
+	ops = BN_new();
+	t = BN_new();
+	dv = BN_new();
 	BN_bin2bn(startmod, CGA_MODLEN, sm);
 	BN_bin2bn(state->mod, CGA_MODLEN, em);
 	BN_sub(ops, em, sm);
@@ -210,6 +215,11 @@ opssec(struct timeval *start, uint8_t *startmod)
 
 	OPENSSL_free(dec);
 	BN_CTX_free(bc);
+	BN_free(sm);
+	BN_free(em);
+	BN_free(ops);
+	BN_free(t);
+	BN_free(dv);
 }
 
 void
