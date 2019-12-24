--- sendmail/tls.c.orig	2015-06-20 01:37:28 UTC
+++ sendmail/tls.c
@@ -16,6 +16,9 @@ SM_RCSID("@(#)$Id: tls.c,v 8.127 2013-11-27 02:51:11 g
 # include <openssl/err.h>
 # include <openssl/bio.h>
 # include <openssl/pem.h>
+# if !NO_DH
+# include <openssl/dh.h>
+# endif /* !NO_DH */
 # ifndef HASURANDOMDEV
 #  include <openssl/rand.h>
 # endif /* ! HASURANDOMDEV */
@@ -44,6 +47,23 @@ static bool	tls_safe_f __P((char *, long, bool));
 static int	tls_verify_log __P((int, X509_STORE_CTX *, const char *));
 
 # if !NO_DH
+# if !defined(OPENSSL_VERSION_NUMBER) || OPENSSL_VERSION_NUMBER < 0x10100001L || \
+     (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L)
+static int
+DH_set0_pqg(dh, p, q, g)
+	DH *dh;
+	BIGNUM *p;
+	BIGNUM *q;
+	BIGNUM *g;
+{
+	dh->p=p;
+	if (q != NULL)
+		dh->q=q;
+	dh->g=g;
+	return 1; /* success */
+}
+# endif /* !defined() || OPENSSL_VERSION_NUMBER < 0x00907000L */
+
 static DH *get_dh512 __P((void));
 
 static unsigned char dh512_p[] =
@@ -64,13 +84,17 @@ static DH *
 get_dh512()
 {
 	DH *dh = NULL;
+	BIGNUM *dhp_bn, *dhg_bn;
 
 	if ((dh = DH_new()) == NULL)
 		return NULL;
-	dh->p = BN_bin2bn(dh512_p, sizeof(dh512_p), NULL);
-	dh->g = BN_bin2bn(dh512_g, sizeof(dh512_g), NULL);
-	if ((dh->p == NULL) || (dh->g == NULL))
+	dhp_bn = BN_bin2bn(dh512_p, sizeof (dh512_p), NULL);
+	dhg_bn = BN_bin2bn(dh512_g, sizeof (dh512_g), NULL);
+	if ((dhp_bn == NULL) || (dhg_bn == NULL) || !DH_set0_pqg(dh, dhp_bn, NULL, dhg_bn))
+	{
+		DH_free(dh);
 		return NULL;
+	}
 	return dh;
 }
 
@@ -117,15 +141,16 @@ get_dh2048()
 		};
 	static unsigned char dh2048_g[]={ 0x02, };
 	DH *dh;
+	BIGNUM *dhp_bn, *dhg_bn;
 
 	if ((dh=DH_new()) == NULL)
 		return(NULL);
-	dh->p=BN_bin2bn(dh2048_p,sizeof(dh2048_p),NULL);
-	dh->g=BN_bin2bn(dh2048_g,sizeof(dh2048_g),NULL);
-	if ((dh->p == NULL) || (dh->g == NULL))
+	dhp_bn = BN_bin2bn(dh2048_p, sizeof (dh2048_p), NULL);
+	dhg_bn = BN_bin2bn(dh2048_g, sizeof (dh2048_g), NULL);
+	if ((dhp_bn == NULL) || (dhg_bn == NULL) || !DH_set0_pqg(dh, dhp_bn, NULL, dhg_bn))
 	{
 		DH_free(dh);
-		return(NULL);
+		return NULL;
 	}
 	return(dh);
 }
@@ -708,6 +733,29 @@ load_certkey(ssl, srv, certfile, keyfile)
 
 static char server_session_id_context[] = "sendmail8";
 
+# if !TLS_NO_RSA
+static RSA *
+sm_RSA_generate_key(num, e)
+	int num;
+	unsigned long e;
+{
+	RSA *rsa = NULL;
+	BIGNUM *bn_rsa_r4;
+
+	bn_rsa_r4 = BN_new();
+	if ((bn_rsa_r4 != NULL) && BN_set_word(bn_rsa_r4, e) && (rsa = RSA_new()) != NULL)
+	{
+		if (!RSA_generate_key_ex(rsa, num, bn_rsa_r4, NULL))
+		{
+			RSA_free(rsa);
+			rsa = NULL;
+		}
+	}
+	BN_free(bn_rsa_r4);
+	return rsa;
+}
+# endif /* !TLS_NO_RSA */
+
 /* 0.9.8a and b have a problem with SSL_OP_TLS_BLOCK_PADDING_BUG */
 #if (OPENSSL_VERSION_NUMBER >= 0x0090800fL)
 # define SM_SSL_OP_TLS_BLOCK_PADDING_BUG	1
@@ -926,7 +974,7 @@ inittls(ctx, req, options, srv, certfile, keyfile, cac
 	{
 		/* get a pointer to the current certificate validation store */
 		store = SSL_CTX_get_cert_store(*ctx);	/* does not fail */
-		crl_file = BIO_new(BIO_s_file_internal());
+		crl_file = BIO_new(BIO_s_file());
 		if (crl_file != NULL)
 		{
 			if (BIO_read_filename(crl_file, CRLFile) >= 0)
@@ -1003,8 +1051,7 @@ inittls(ctx, req, options, srv, certfile, keyfile, cac
 	if (bitset(TLS_I_RSA_TMP, req)
 #  if SM_CONF_SHM
 	    && ShmId != SM_SHM_NO_ID &&
-	    (rsa_tmp = RSA_generate_key(RSA_KEYLENGTH, RSA_F4, NULL,
-					NULL)) == NULL
+	    (rsa_tmp = sm_RSA_generate_key(RSA_KEYLENGTH, RSA_F4)) == NULL
 #  else /* SM_CONF_SHM */
 	    && 0	/* no shared memory: no need to generate key now */
 #  endif /* SM_CONF_SHM */
@@ -1209,9 +1256,10 @@ inittls(ctx, req, options, srv, certfile, keyfile, cac
 			if (tTd(96, 2))
 				sm_dprintf("inittls: Generating %d bit DH parameters\n", bits);
 
+			dsa=DSA_new();
 			/* this takes a while! */
-			dsa = DSA_generate_parameters(bits, NULL, 0, NULL,
-						      NULL, 0, NULL);
+			(void)DSA_generate_parameters_ex(dsa, bits, NULL, 0,
+							 NULL, NULL, NULL);
 			dh = DSA_dup_DH(dsa);
 			DSA_free(dsa);
 		}
@@ -1744,7 +1792,7 @@ tmp_rsa_key(s, export, keylength)
 
 	if (rsa_tmp != NULL)
 		RSA_free(rsa_tmp);
-	rsa_tmp = RSA_generate_key(RSA_KEYLENGTH, RSA_F4, NULL, NULL);
+	rsa_tmp = sm_RSA_generate_key(RSA_KEYLENGTH, RSA_F4);
 	if (rsa_tmp == NULL)
 	{
 		if (LogLevel > 0)
@@ -1971,9 +2019,9 @@ x509_verify_cb(ok, ctx)
 	{
 		if (LogLevel > 13)
 			tls_verify_log(ok, ctx, "x509");
-		if (ctx->error == X509_V_ERR_UNABLE_TO_GET_CRL)
+		if (X509_STORE_CTX_get_error(ctx) == X509_V_ERR_UNABLE_TO_GET_CRL)
 		{
-			ctx->error = 0;
+			X509_STORE_CTX_set_error(ctx, 0);
 			return 1;	/* override it */
 		}
 	}
