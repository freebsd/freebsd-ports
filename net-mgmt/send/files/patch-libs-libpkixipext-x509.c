--- libs/libpkixipext/x509.c.orig	2019-02-27 16:25:45 UTC
+++ libs/libpkixipext/x509.c
@@ -57,34 +57,54 @@ static char nbuf[1024];
 extern int pkixip_verify_cb(int, X509_STORE_CTX *);
 
 X509V3_EXT_METHOD pkix_ip_ext_method = {
-	ext_flags : X509V3_EXT_MULTILINE,
-	it : ASN1_ITEM_ref(IPAddrBlocks),
-	i2v : (X509V3_EXT_I2V)i2v_IPAddrBlocks,
+	.ext_flags = X509V3_EXT_MULTILINE,
+	.it = ASN1_ITEM_ref(IPAddrBlocks),
+	.i2v = (X509V3_EXT_I2V)i2v_IPAddrBlocks,
 };
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 static STACK *stores[PKIXIP_MAX_STORES];
+#else
+static STACK_OF(X509_OBJECT) *stores[PKIXIP_MAX_STORES];
+#endif
 static X509_STORE_CTX *ctx_bysubj;
 static int next_store = 1;
 static void *(*wrap_store_cert)(X509 *x);
 static void (*trustanchor_cb)(X509 *x);
 pthread_mutex_t stores_lock = PTHREAD_MUTEX_INITIALIZER;
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 static STACK *mychain;
+#else
+static STACK_OF(X509_OBJECT) *mychain;
+#endif
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#define	X509_OBJECT_get_type(a)	((a)->type)
+#define	X509_OBJECT_get0_X509(a)	((a)->data.x509)
+#define	X509_OBJECT_get0_X509_CRL(a)	((a)->data.crl)
+#define	X509_STORE_get0_objects(a)	((a)->objs)
+#define	X509_STORE_CTX_get0_chain(a)	((a)->chain)
+#endif
 /* Lifted from openssl x509_lu.c */
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 static int
 x509_object_cmp(X509_OBJECT **a, X509_OBJECT **b)
+#else
+static int
+x509_object_cmp(const X509_OBJECT * const *a, const X509_OBJECT * const *b)
+#endif
 {
  	int ret;
 
- 	ret=((*a)->type - (*b)->type);
+ 	ret=(X509_OBJECT_get_type(*a) - X509_OBJECT_get_type(*b));
  	if (ret) return ret;
- 	switch ((*a)->type) {
+ 	switch (X509_OBJECT_get_type(*a)) {
  	case X509_LU_X509:
- 		ret=X509_subject_name_cmp((*a)->data.x509,(*b)->data.x509);
+ 		ret=X509_subject_name_cmp(X509_OBJECT_get0_X509(*a),X509_OBJECT_get0_X509(*b));
  		break;
  	case X509_LU_CRL:
- 		ret=X509_CRL_cmp((*a)->data.crl,(*b)->data.crl);
+ 		ret=X509_CRL_cmp(X509_OBJECT_get0_X509_CRL(*a),X509_OBJECT_get0_X509_CRL(*b));
  		break;
 	default:
 		/* abort(); */
@@ -243,7 +263,11 @@ pkixip_load_pkey(const char *f)
 	return (pkey);
 }
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 static STACK *
+#else
+static STACK_OF(X509_OBJECT) *
+#endif
 pkixip_get_store(int handle)
 {
 	if (handle >= PKIXIP_MAX_STORES || handle < 0) {
@@ -257,7 +281,11 @@ pkixip_get_store(int handle)
 void
 pkixip_walk_store(int (*cb)(X509 *, void *), void *cookie, int handle)
 {
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 	STACK *objs;
+#else
+	STACK_OF(X509_OBJECT) *objs;
+#endif
 	int i;
 	X509_OBJECT *xo;
 
@@ -266,12 +294,16 @@ pkixip_walk_store(int (*cb)(X509 *, void *), void *coo
 		goto done;
 	}
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 	for (i = 0; i < sk_num(objs); i++) {
+#else
+	for (i = 0; i < sk_X509_OBJECT_num(objs); i++) {
+#endif
 		xo = sk_X509_OBJECT_value(objs, i);
-		if (xo->type != X509_LU_X509) {
+		if (X509_OBJECT_get_type(xo) != X509_LU_X509) {
 			continue;
 		}
-		if (!cb(xo->data.x509, cookie)) {
+		if (!cb(X509_OBJECT_get0_X509(xo), cookie)) {
 			break;
 		}
 	}
@@ -282,7 +314,11 @@ done:
 void *
 pkixip_find_cert(void *k, int handle)
 {
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 	STACK *store;
+#else
+	STACK_OF(X509_OBJECT) *store;
+#endif
 	int i;
 	void *r = NULL;
 
@@ -291,11 +327,19 @@ pkixip_find_cert(void *k, int handle)
 		goto done;
 	}
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 	if ((i = sk_find(store, k)) < 0) {
+#else
+	if ((i = sk_X509_OBJECT_find(store, k)) < 0) {
+#endif
 		goto done;
 	}
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 	r = sk_value(store, i);
+#else
+	r = sk_X509_OBJECT_value(store, i);
+#endif
 
 done:
 	pthread_mutex_unlock(&stores_lock);
@@ -304,8 +348,13 @@ done:
 
 /* Caller must hold stores_lock */
 static int
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 pkixip_do_add_store(int handle, int (*cmp)(X509_OBJECT **, X509_OBJECT **),
     STACK *objs)
+#else
+pkixip_do_add_store(int handle, int (*cmp)(const X509_OBJECT * const *, X509_OBJECT * const *),
+    STACK_OF(X509_OBJECT) *objs)
+#endif
 {
 	if (objs == NULL && (objs = sk_X509_OBJECT_new(cmp)) == NULL) {
 		applog(LOG_CRIT, "no memory");
@@ -316,8 +365,13 @@ pkixip_do_add_store(int handle, int (*cmp)(X509_OBJECT
 	return (0);
 }
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 int
 pkixip_add_store(int *handle, int (*cmp)(X509_OBJECT **, X509_OBJECT **))
+#else
+int
+pkixip_add_store(int *handle, int (*cmp)(const X509_OBJECT * const *, const X509_OBJECT * const *))
+#endif
 {
 	int r = 0;
 
@@ -369,7 +423,7 @@ pkixip_get_store_ctx(void)
 	}
 
 	pthread_mutex_lock(&stores_lock);
-	if (pkixip_do_add_store(PKIXIP_STORE_BYSUBJ, x509_object_cmp, st->objs)
+	if (pkixip_do_add_store(PKIXIP_STORE_BYSUBJ, x509_object_cmp, X509_STORE_get0_objects(st))
 	    < 0) {
 		X509_STORE_free(st);
 		X509_STORE_CTX_free(ctx_bysubj);
@@ -396,17 +450,24 @@ pkixip_store_ctx_light_cleanup(X509_STORE_CTX *ctx)
 {
 //	X509_STORE_CTX_cleanup(ctx);
 
-	if (ctx->chain != NULL) {
-		sk_X509_pop_free(ctx->chain, noop_free);
+	if (X509_STORE_CTX_get0_chain(ctx) != NULL) {
+		sk_X509_pop_free(X509_STORE_CTX_get0_chain(ctx), noop_free);
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 		ctx->chain=NULL;
+#endif
 	}
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 	CRYPTO_free_ex_data(CRYPTO_EX_INDEX_X509_STORE_CTX, ctx,
 			    &(ctx->ex_data));
 	memset(&ctx->ex_data,0,sizeof(CRYPTO_EX_DATA));
+#else
+	CRYPTO_free_ex_data(CRYPTO_EX_INDEX_X509_STORE_CTX, ctx,
+			    X509_STORE_CTX_get_app_data(ctx));
+#endif
 
 #if 0
-	while (sk_num(ctx->chain) > 0) {
-		sk_pop(ctx->chain);
+	while (sk_num(X509_STORE_CTX_get0_chain(ctx)) > 0) {
+		sk_pop(X509_STORE_CTX_get0_chain(ctx));
 	}
 #endif
 }
@@ -445,10 +506,19 @@ pkixip_add2stores_cert(X509 *x)
 	int i, r = 0;
 	X509_STORE_CTX *ctx;
 	void *wrapper;
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 	X509_OBJECT o[1];
+#else
+	X509_OBJECT *o;
 
-	if ((ctx = pkixip_get_store_ctx()) == NULL) {
+	o = X509_OBJECT_new();
+	if (o == NULL)
 		return (-1);
+#endif
+
+	if ((ctx = pkixip_get_store_ctx()) == NULL) {
+		r = -1;
+		goto done2;
 	}
 
 	pthread_mutex_lock(&stores_lock);
@@ -459,7 +529,11 @@ pkixip_add2stores_cert(X509 *x)
 		goto done;
 	}
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 	if (X509_STORE_add_cert(ctx->ctx, x) != 1) {
+#else
+	if (X509_STORE_add_cert(X509_STORE_CTX_get0_store(ctx), x) != 1) {
+#endif
 		pkixip_ssl_err(__FUNCTION__, "X509_STORE_add_cert() failed");
 		r = -1;
 		goto done;
@@ -467,7 +541,8 @@ pkixip_add2stores_cert(X509 *x)
 
 	if (wrap_store_cert) {
 		if ((wrapper = wrap_store_cert(x)) == NULL) {
-			return (-1);
+			r = -1;
+			goto done2;
 		}
 	} else {
 		wrapper = x;
@@ -475,7 +550,11 @@ pkixip_add2stores_cert(X509 *x)
 
 	for (i = 1; i < PKIXIP_MAX_STORES; i++) {
 		if (stores[i]) {
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 			sk_push(stores[i], wrapper);
+#else
+			sk_X509_OBJECT_push(stores[i], wrapper);
+#endif
 		}
 	}
 
@@ -484,6 +563,10 @@ pkixip_add2stores_cert(X509 *x)
 
 done:
 	pthread_mutex_unlock(&stores_lock);
+done2:
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+	free(o);
+#endif
 	return (r);
 }
 
@@ -523,14 +606,26 @@ pkixip_my_chain_init(X509 *mycert)
 	}
 
 	if (mychain != NULL) {
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 		sk_free(mychain);
+#else
+		sk_X509_OBJECT_free(mychain);
+#endif
 	}
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 	if ((mychain = sk_dup(ctx->chain)) == NULL) {
+#else
+	if ((mychain = sk_X509_OBJECT_dup(X509_STORE_CTX_get0_chain(ctx))) == NULL) {
+#endif
 		APPLOG_NOMEM();
 		r = -1;
 		goto done;
 	}
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 	sk_set_cmp_func(mychain, x509_bysubj_cmp);
+#else
+	sk_X509_OBJECT_set_cmp_func(mychain, x509_bysubj_cmp);
+#endif
 	DBG(&dbg_x509, "mychain verified and set");
 
 done:
@@ -538,7 +633,11 @@ done:
 	return (r);
 }
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 STACK *
+#else
+STACK_OF(X509_OBJECT) *
+#endif
 pkixip_get_mychain(void)
 {
 	return (mychain);
