--- src/modules/auth/srp/auth_srp.c.orig	2001-12-12 21:35:02.000000000 +0100
+++ src/modules/auth/srp/auth_srp.c	2007-10-17 09:48:57.000000000 +0200
@@ -289,7 +289,7 @@
 _get_srppass(AUTHCON *ct, BIGNUM *v, BIGNUM *s, unsigned char *bs)
 {
 	RESOURCE	*r;
-	BN_CTX		 bnctx;
+	BN_CTX		*bnctx = BN_CTX_new();
 	BIGNUM		 tmp;
 
 	if (ct->rlist != NULL) {
@@ -308,12 +308,12 @@
 
 	/* Generate fake verifier and salt (try to avoid timing attack) */
 	log_debug(AUTH_SRP "Generating fake verifier and salt.");
-	BN_CTX_init(&bnctx);
+	BN_CTX_init(bnctx);
 	BN_init(&tmp);
-	_rand_bn(v, &tmp, &bnctx);
-	_rand_bn(s, &tmp, &bnctx);
+	_rand_bn(v, &tmp, bnctx);
+	_rand_bn(s, &tmp, bnctx);
 	BN_free(&tmp);
-	BN_CTX_free(&bnctx);
+	BN_CTX_free(bnctx);
 	BN_bn2bin(s, bs);
 	return (-1);
 }
@@ -460,7 +460,7 @@
 			 USER_M1[SHA1_DIGESTSIZE],
 			 bs[NBYTES];
 	BIGNUM		 A, B, S, b, u, v, s, tmp;
-	BN_CTX		 bnctx;
+	BN_CTX		*bnctx = BN_CTX_new();
 	void		*buffer;
 	size_t		 bufsiz;
 	char		 hostname[MAXHOSTNAMELEN]; /* XXX: move to engine */
@@ -483,7 +483,7 @@
 	BN_init(&u);
 	BN_init(&v);
 	BN_init(&tmp);
-	BN_CTX_init(&bnctx);
+	BN_CTX_init(bnctx);
 
 	clnt_st = LOGIN_FAILED;
 
@@ -508,10 +508,10 @@
 	 *	u = rand(); 1 < u < p - 1
 	 *	B = (g exp b + v) % p = ((g exp b) % p + v) % p
 	 */
-	_rand_bn(&b, &tmp, &bnctx);
-	_rand_bn(&u, &tmp, &bnctx);
-	if (!BN_mod_exp(&B, &g, &b, &p, &bnctx) ||
-	    !BN_add(&tmp, &B, &v) || !BN_mod(&B, &tmp, &p, &bnctx))
+	_rand_bn(&b, &tmp, bnctx);
+	_rand_bn(&u, &tmp, bnctx);
+	if (!BN_mod_exp(&B, &g, &b, &p, bnctx) ||
+	    !BN_add(&tmp, &B, &v) || !BN_mod(&B, &tmp, &p, bnctx))
 		_fatal_bn("srvr_auth()");
 
 	/* Receive A, send B and u */
@@ -527,9 +527,9 @@
 	 *	K  = HASH(S)
 	 *	M1 = HASH(A, B, K)
 	 */
-	if (!BN_mod_exp(&S, &v, &u, &p, &bnctx) ||
-	    !BN_mod_mul(&tmp, &A, &S, &p, &bnctx) ||
-	    !BN_mod_exp(&S, &tmp, &b, &p, &bnctx))
+	if (!BN_mod_exp(&S, &v, &u, &p, bnctx) ||
+	    !BN_mod_mul(&tmp, &A, &S, &p, bnctx) ||
+	    !BN_mod_exp(&S, &tmp, &b, &p, bnctx))
 		_fatal_bn("srvr_auth()");
 	_hash_bn(K, &S, &buffer, &bufsiz);
 	_auth_digest1(M1, &A, &B, K, &buffer, &bufsiz);
@@ -581,7 +581,7 @@
 	BN_clear_free(&u);
 	BN_clear_free(&v);
 	BN_clear_free(&tmp);
-	BN_CTX_free(&bnctx);
+	BN_CTX_free(bnctx);
 	free(buffer);
 
 	/* Init encryption */
@@ -624,7 +624,7 @@
 			 M2[SHA1_DIGESTSIZE],
 			 SERVER_M2[SHA1_DIGESTSIZE];
 	BIGNUM		 a, u, x, A, B, S, tmp1, tmp2, tmp3;
-	BN_CTX		 bnctx;
+	BN_CTX		*bnctx = BN_CTX_new();
 	SHA1_CTX	 sha1_ctx;
 	void		*buffer;
 	size_t		 bufsiz;
@@ -643,7 +643,7 @@
 	BN_init(&tmp1);
 	BN_init(&tmp2);
 	BN_init(&tmp3);
-	BN_CTX_init(&bnctx);
+	BN_CTX_init(bnctx);
 
 	srvr_st = clnt_st = LOGIN_FAILED;
 
@@ -681,7 +681,7 @@
 	SHA1Final(xdigest, &sha1_ctx);
 	bzero(args->pass, sizeof(args->pass));
 	if (BN_bin2bn(xdigest, sizeof(xdigest), &tmp1) == NULL ||
-	    !BN_mod(&x, &tmp1, &pm1, &bnctx))
+	    !BN_mod(&x, &tmp1, &pm1, bnctx))
 		_fatal_bn("_auth_clnt()");
 	
 	/*
@@ -689,8 +689,8 @@
 	 *	a = rand(); 1 < a < n - 1
 	 *	A = (g exp a) % n
 	 */
-	_rand_bn(&a, &tmp1, &bnctx);
-	if (!BN_mod_exp(&A, &g, &a, &p, &bnctx))
+	_rand_bn(&a, &tmp1, bnctx);
+	if (!BN_mod_exp(&A, &g, &a, &p, bnctx))
 		_fatal_bn("_auth_clnt()");
 
 	/* Send A, receive B and u */
@@ -704,14 +704,14 @@
 	 *	  = ( (B - (g exp x) % n) exp
 	 *	    ((a + ((u * x) % (n - 1))) % (n - 1)) ) % n
 	 */
-	if (!BN_mod_mul(&tmp1, &u, &x, &pm1, &bnctx) ||
+	if (!BN_mod_mul(&tmp1, &u, &x, &pm1, bnctx) ||
 	    !BN_add(&S, &tmp1, &a) ||
-	    !BN_mod(&tmp1, &S, &pm1, &bnctx) ||
-	    !BN_mod_exp(&tmp2, &g, &x, &p, &bnctx) ||
+	    !BN_mod(&tmp1, &S, &pm1, bnctx) ||
+	    !BN_mod_exp(&tmp2, &g, &x, &p, bnctx) ||
 	    !BN_add(&tmp3, &B, &p) ||	/* Workaround for the BN_mod() bug */
 	    !BN_sub(&S, &tmp3, &tmp2) ||
-	    !BN_mod(&tmp2, &S, &p, &bnctx) ||
-	    !BN_mod_exp(&S, &tmp2, &tmp1, &p, &bnctx))
+	    !BN_mod(&tmp2, &S, &p, bnctx) ||
+	    !BN_mod_exp(&S, &tmp2, &tmp1, &p, bnctx))
 		_fatal_bn("_auth_clnt()");
 
 	/*
@@ -749,7 +749,7 @@
 	BN_clear_free(&S);
 	BN_clear_free(&tmp1);
 	BN_clear_free(&tmp2);
-	BN_CTX_free(&bnctx);
+	BN_CTX_free(bnctx);
 	free(buffer);
 
 	/* Init encryption */
@@ -776,7 +776,7 @@
 _filter_resource(AUTHCON *ct, struct autharg_filter *args)
 {
 	SHA1_CTX	sha1_ctx;
-	BN_CTX		bnctx;
+	BN_CTX	       *bnctx = BN_CTX_new();
 	BIGNUM		salt, verifier, x, tmp;
 	unsigned char	bsalt[NBYTES], xdigest[SHA1_DIGESTSIZE];
 
@@ -789,7 +789,7 @@
 	/* Just filter srp passwords */
 	if (!strcmp(args->rname, SRP_PASS_RNAME)) {
 
-		BN_CTX_init(&bnctx);
+		BN_CTX_init(bnctx);
 		BN_init(&salt);
 		BN_init(&x);
 		BN_init(&verifier);
@@ -801,15 +801,15 @@
 		 *	x = HASH(salt, password); 1 < x < n - 1
 		 *	verifier = (g exp x) % n
 		 */
-		_rand_bn(&salt, &tmp, &bnctx);
+		_rand_bn(&salt, &tmp, bnctx);
 		BN_bn2bin(&salt, bsalt);
 		SHA1Init(&sha1_ctx);
 		SHA1Update(&sha1_ctx, bsalt, sizeof(bsalt));
 		SHA1Update(&sha1_ctx, args->value, args->vsize);
 		SHA1Final(xdigest, &sha1_ctx);
 		if (BN_bin2bn(xdigest, sizeof(xdigest), &tmp) == NULL ||
-		    !BN_mod(&x, &tmp, &pm1, &bnctx) ||
-		    !BN_mod_exp(&verifier, &g, &x, &p, &bnctx))
+		    !BN_mod(&x, &tmp, &pm1, bnctx) ||
+		    !BN_mod_exp(&verifier, &g, &x, &p, bnctx))
 			_fatal_bn("_filter_resource()");
 
 		/* Get memory for the filtered value */
@@ -829,7 +829,7 @@
 		BN_clear_free(&verifier);
 		BN_clear_free(&x);
 		BN_clear_free(&salt);
-		BN_CTX_free(&bnctx);
+		BN_CTX_free(bnctx);
 
 		if (args->fvalue == NULL)
 			return (-1);
