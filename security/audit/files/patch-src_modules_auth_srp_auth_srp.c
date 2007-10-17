--- src/modules/auth/srp/auth_srp.c.orig	2007-10-17 08:09:07.000000000 +0200
+++ src/modules/auth/srp/auth_srp.c	2007-10-17 08:09:09.000000000 +0200
@@ -445,7 +445,7 @@ _auth_srvr(AUTHCON *ct)
 			 USER_M1[SHA1_DIGESTSIZE],
 			 bs[NBYTES];
 	BIGNUM		 A, B, S, b, u, v, s, tmp;
-	BN_CTX		 bnctx;
+	BN_CTX		*bnctx = BN_CTX_new();
 	void		*buffer;
 	size_t		 bufsiz;
 	char		 hostname[MAXHOSTNAMELEN]; /* XXX: move to engine */
@@ -468,7 +468,7 @@ _auth_srvr(AUTHCON *ct)
 	BN_init(&u);
 	BN_init(&v);
 	BN_init(&tmp);
-	BN_CTX_init(&bnctx);
+	BN_CTX_init(bnctx);
 
 	clnt_st = LOGIN_FAILED;
 
@@ -493,7 +493,7 @@ _auth_srvr(AUTHCON *ct)
 	 */
 	_rand_bn(&b);
 	_rand_bn(&u);
-	if (!BN_mod_exp(&tmp, &g, &b, &n, &bnctx) || !BN_add(&B, &tmp, &v))
+	if (!BN_mod_exp(&tmp, &g, &b, &n, bnctx) || !BN_add(&B, &tmp, &v))
 		_fatal_bn("srvr_auth()");
 
 	/* Receive A, send B and u */
@@ -507,9 +507,9 @@ _auth_srvr(AUTHCON *ct)
 	 *	K  = HASH(S)
 	 *	M1 = HASH(A, B, K)
 	 */
-	if (!BN_mod_exp(&S, &v, &u, &n, &bnctx) ||
-	    !BN_mul(&tmp, &A, &S, &bnctx) ||
-	    !BN_mod_exp(&S, &tmp, &b, &n, &bnctx))
+	if (!BN_mod_exp(&S, &v, &u, &n, bnctx) ||
+	    !BN_mul(&tmp, &A, &S, bnctx) ||
+	    !BN_mod_exp(&S, &tmp, &b, &n, bnctx))
 		_fatal_bn("srvr_auth()");
 	_hash_bn(K, &S, &buffer, &bufsiz);
 	_auth_digest1(M1, &A, &B, K, &buffer, &bufsiz);
@@ -560,7 +560,7 @@ _auth_srvr(AUTHCON *ct)
 	BN_clear_free(&u);
 	BN_clear_free(&v);
 	BN_clear_free(&tmp);
-	BN_CTX_free(&bnctx);
+	BN_CTX_free(bnctx);
 	free(buffer);
 
 	/* Init encryption */
@@ -603,7 +603,7 @@ _auth_clnt(AUTHCON *ct, struct autharg_c
 			 M2[SHA1_DIGESTSIZE],
 			 SERVER_M2[SHA1_DIGESTSIZE];
 	BIGNUM		 a, u, x, A, B, S, tmp1, tmp2;
-	BN_CTX		 bnctx;
+	BN_CTX		*bnctx = BN_CTX_new();
 	SHA1_CTX	 sha1_ctx;
 	void		*buffer;
 	size_t		 bufsiz;
@@ -621,7 +621,7 @@ _auth_clnt(AUTHCON *ct, struct autharg_c
 	BN_init(&S);
 	BN_init(&tmp1);
 	BN_init(&tmp2);
-	BN_CTX_init(&bnctx);
+	BN_CTX_init(bnctx);
 
 	srvr_st = clnt_st = LOGIN_FAILED;
 
@@ -663,7 +663,7 @@ _auth_clnt(AUTHCON *ct, struct autharg_c
 	 *	A = g exp a
 	 */
 	_rand_bn(&a);
-	if (!BN_mod_exp(&A, &g, &a, &n, &bnctx))
+	if (!BN_mod_exp(&A, &g, &a, &n, bnctx))
 		_fatal_bn("_auth_clnt()");
 
 	/* Send A, receive B and u */
@@ -675,11 +675,11 @@ _auth_clnt(AUTHCON *ct, struct autharg_c
 	 * Calculate:
 	 *	S = ( (B - g exp x) exp (a + u * x) ) % n
 	 */
-	if (!BN_mul(&S, &u, &x, &bnctx) ||
+	if (!BN_mul(&S, &u, &x, bnctx) ||
 	    !BN_add(&tmp1, &S, &a) ||
-	    !BN_mod_exp(&S, &g, &x, &n, &bnctx) ||
+	    !BN_mod_exp(&S, &g, &x, &n, bnctx) ||
 	    !BN_sub(&tmp2, &B, &S) ||
-	    !BN_mod_exp(&S, &tmp2, &tmp1, &n, &bnctx))
+	    !BN_mod_exp(&S, &tmp2, &tmp1, &n, bnctx))
 		_fatal_bn("_auth_clnt()");
 
 	/*
@@ -717,7 +717,7 @@ _auth_clnt(AUTHCON *ct, struct autharg_c
 	BN_clear_free(&S);
 	BN_clear_free(&tmp1);
 	BN_clear_free(&tmp2);
-	BN_CTX_free(&bnctx);
+	BN_CTX_free(bnctx);
 	free(buffer);
 
 	/* Init encryption */
@@ -744,7 +744,7 @@ static int
 _filter_resource(AUTHCON *ct, struct autharg_filter *args)
 {
 	SHA1_CTX	sha1_ctx;
-	BN_CTX		bnctx;
+	BN_CTX	       *bnctx = BN_CTX_new();
 	BIGNUM		salt, verifier, x;
 	unsigned char	bsalt[NBYTES], xdigest[SHA1_DIGESTSIZE];
 
@@ -756,7 +756,7 @@ _filter_resource(AUTHCON *ct, struct aut
 	/* Just filter srp passwords */
 	if (!strcmp(args->rname, SRP_PASS_RNAME)) {
 
-		BN_CTX_init(&bnctx);
+		BN_CTX_init(bnctx);
 		BN_init(&salt);
 		BN_init(&x);
 		BN_init(&verifier);
@@ -774,7 +774,7 @@ _filter_resource(AUTHCON *ct, struct aut
 		SHA1Update(&sha1_ctx, args->value, args->vsize);
 		SHA1Final(xdigest, &sha1_ctx);
 		if (BN_bin2bn(xdigest, sizeof(xdigest), &x) == NULL ||
-		    !BN_mod_exp(&verifier, &g, &x, &n, &bnctx))
+		    !BN_mod_exp(&verifier, &g, &x, &n, bnctx))
 			_fatal_bn("_filter_resource()");
 
 		/* Get memory for the filtered value */
@@ -793,7 +793,7 @@ _filter_resource(AUTHCON *ct, struct aut
 		BN_clear_free(&verifier);
 		BN_clear_free(&x);
 		BN_clear_free(&salt);
-		BN_CTX_free(&bnctx);
+		BN_CTX_free(bnctx);
 
 		if (args->fvalue == NULL)
 			return (-1);
