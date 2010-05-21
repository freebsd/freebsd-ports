--- ./qca-ossl.cpp.orig	2007-12-11 09:34:57.000000000 +0300
+++ ./qca-ossl.cpp	2010-05-15 20:12:08.151288762 +0400
@@ -42,6 +42,15 @@
 #define OSSL_097
 #endif
 
+#if defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER >= 0x10000000L
+// OpenSSL 1.0.0 makes a few changes that aren't very C++ friendly...
+// Among other things, CHECKED_PTR_OF returns a void*, but is used in
+// contexts requiring STACK pointers.
+#undef CHECKED_PTR_OF
+#define CHECKED_PTR_OF(type, p) \
+	            ((_STACK*) (1 ? p : (type*)0))
+#endif
+
 using namespace QCA;
 
 namespace opensslQCAPlugin {
@@ -327,7 +336,7 @@
 	X509V3_CTX ctx;
 	X509V3_set_ctx_nodb(&ctx);
 	X509V3_set_ctx(&ctx, NULL, cert, NULL, NULL, 0);
-	X509_EXTENSION *ex = X509V3_EXT_conf_nid(NULL, &ctx, NID_subject_key_identifier, "hash");
+	X509_EXTENSION *ex = X509V3_EXT_conf_nid(NULL, &ctx, NID_subject_key_identifier, (char *)"hash");
 	return ex;
 }
 
@@ -1182,6 +1191,7 @@
 	{
 		pkey = from.pkey;
 		CRYPTO_add(&pkey->references, 1, CRYPTO_LOCK_EVP_PKEY);
+		raw_type = false;
 		state = Idle;
 	}
 
@@ -1226,6 +1236,7 @@
 		}
 		else
 		{
+			raw_type = false;
 			EVP_MD_CTX_init(&mdctx);
 			if(!EVP_VerifyInit_ex(&mdctx, type, NULL))
 				state = VerifyError;
@@ -1771,8 +1782,10 @@
 			md = EVP_sha1();
 		else if(alg == EMSA3_MD5)
 			md = EVP_md5();
+#ifdef HAVE_OPENSSL_MD2
 		else if(alg == EMSA3_MD2)
 			md = EVP_md2();
+#endif
 		else if(alg == EMSA3_RIPEMD160)
 			md = EVP_ripemd160();
 		else if(alg == EMSA3_Raw)
@@ -1789,8 +1802,10 @@
 			md = EVP_sha1();
 		else if(alg == EMSA3_MD5)
 			md = EVP_md5();
+#ifdef HAVE_OPENSSL_MD2
 		else if(alg == EMSA3_MD2)
 			md = EVP_md2();
+#endif
 		else if(alg == EMSA3_RIPEMD160)
 			md = EVP_ripemd160();
 		else if(alg == EMSA3_Raw)
@@ -3385,9 +3400,11 @@
 		case NID_md5WithRSAEncryption:
 		    p.sigalgo = QCA::EMSA3_MD5;
 		    break;
+#ifdef HAVE_OPENSSL_MD2
 		case NID_md2WithRSAEncryption:
 		    p.sigalgo = QCA::EMSA3_MD2;
 		    break;
+#endif
 		case NID_ripemd160WithRSA:
 		    p.sigalgo = QCA::EMSA3_RIPEMD160;
 		    break;
@@ -3871,9 +3888,11 @@
 		case NID_md5WithRSAEncryption:
 		    p.sigalgo = QCA::EMSA3_MD5;
 		    break;
+#ifdef HAVE_OPENSSL_MD2
 		case NID_md2WithRSAEncryption:
 		    p.sigalgo = QCA::EMSA3_MD2;
 		    break;
+#endif
 		case NID_ripemd160WithRSA:
 		    p.sigalgo = QCA::EMSA3_RIPEMD160;
 		    break;
@@ -4061,9 +4080,11 @@
 		case NID_md5WithRSAEncryption:
 		    p.sigalgo = QCA::EMSA3_MD5;
 		    break;
+#ifdef HAVE_OPENSSL_MD2
 		case NID_md2WithRSAEncryption:
 		    p.sigalgo = QCA::EMSA3_MD2;
 		    break;
+#endif
 		case NID_ripemd160WithRSA:
 		    p.sigalgo = QCA::EMSA3_RIPEMD160;
 		    break;
@@ -5128,6 +5149,16 @@
 		v_eof = false;
 	}
 
+	// dummy verification function for SSL_set_verify()
+	static int ssl_verify_callback(int preverify_ok, X509_STORE_CTX *x509_ctx)
+	{
+		Q_UNUSED(preverify_ok);
+		Q_UNUSED(x509_ctx);
+
+		// don't terminate handshake in case of verification failure
+		return 1;
+	}
+
 	virtual QStringList supportedCipherSuites(const TLS::Version &version) const
 	{
 		OpenSSL_add_ssl_algorithms();
@@ -5692,6 +5723,14 @@
 			}
 		}
 
+		// request a certificate from the client, if in server mode
+		if(serv)
+		{
+			SSL_set_verify(ssl,
+				SSL_VERIFY_PEER|SSL_VERIFY_CLIENT_ONCE,
+				ssl_verify_callback);
+		}
+
 		return true;
 	}
 
@@ -6155,6 +6194,7 @@
 				i2d_PKCS7_bio(bo, p7);
 				//PEM_write_bio_PKCS7(bo, p7);
 				out = bio2ba(bo);
+				PKCS7_free(p7);
 			}
 			else
 			{
@@ -6582,7 +6622,9 @@
 	list += "sha1";
 	list += "sha0";
 	list += "ripemd160";
+#ifdef HAVE_OPENSSL_MD2
 	list += "md2";
+#endif
 	list += "md4";
 	list += "md5";
 #ifdef SHA224_DIGEST_LENGTH
@@ -6597,9 +6639,11 @@
 #ifdef SHA512_DIGEST_LENGTH
 	list += "sha512";
 #endif
+/*
 #ifdef OBJ_whirlpool
 	list += "whirlpool";
 #endif
+*/
 	return list;
 }
 
@@ -6671,7 +6715,7 @@
 	{
 	}
 
-	Context *clone() const
+	Provider::Context *clone() const
 	{
 		return new opensslInfoContext(*this);
 	}
@@ -6692,6 +6736,34 @@
 	}
 };
 
+class opensslRandomContext : public RandomContext
+{
+public:
+	opensslRandomContext(QCA::Provider *p) : RandomContext(p)
+	{
+	}
+
+	Context *clone() const
+	{
+		return new opensslRandomContext(*this);
+	}
+
+	QCA::SecureArray nextBytes(int size)
+	{
+		QCA::SecureArray buf(size);
+		int r;
+		// FIXME: loop while we don't have enough random bytes.
+		while (true) {
+			r = RAND_bytes((unsigned char*)(buf.data()), size);
+			if (r == 1) break; // success
+			r = RAND_pseudo_bytes((unsigned char*)(buf.data()),
+						size);
+			if (r >= 0) break; // accept insecure random numbers
+		}
+		return buf;
+	}
+};
+
 }
 
 using namespace opensslQCAPlugin;
@@ -6711,11 +6783,14 @@
 		OpenSSL_add_all_algorithms();
 		ERR_load_crypto_strings();
 
-		srand(time(NULL));
-		char buf[128];
-		for(int n = 0; n < 128; ++n)
-			buf[n] = rand();
-		RAND_seed(buf, 128);
+		// seed the RNG if it's not seeded yet
+		if (RAND_status() == 0) {
+			qsrand(time(NULL));
+			char buf[128];
+			for(int n = 0; n < 128; ++n)
+				buf[n] = qrand();
+			RAND_seed(buf, 128);
+		}
 
 		openssl_initted = true;
 	}
@@ -6754,10 +6829,13 @@
 	QStringList features() const
 	{
 		QStringList list;
+		list += "random";
 		list += all_hash_types();
 		list += all_mac_types();
 		list += all_cipher_types();
+#ifdef HAVE_OPENSSL_MD2
 		list += "pbkdf1(md2)";
+#endif
 		list += "pbkdf1(sha1)";
 		list += "pbkdf2(sha1)";
 		list += "pkey";
@@ -6780,7 +6858,9 @@
 	Context *createContext(const QString &type)
 	{
 		//OpenSSL_add_all_digests();
-		if ( type == "info" )
+		if ( type == "random" )
+			return new opensslRandomContext(this);
+		else if ( type == "info" )
 			return new opensslInfoContext(this);
 		else if ( type == "sha1" )
 			return new opensslHashContext( EVP_sha1(), this, type);
@@ -6788,8 +6868,10 @@
 			return new opensslHashContext( EVP_sha(), this, type);
 		else if ( type == "ripemd160" )
 			return new opensslHashContext( EVP_ripemd160(), this, type);
+#ifdef HAVE_OPENSSL_MD2
 		else if ( type == "md2" )
 			return new opensslHashContext( EVP_md2(), this, type);
+#endif
 		else if ( type == "md4" )
 			return new opensslHashContext( EVP_md4(), this, type);
 		else if ( type == "md5" )
@@ -6810,14 +6892,18 @@
 		else if ( type == "sha512" )
 			return new opensslHashContext( EVP_sha512(), this, type);
 #endif
+/*
 #ifdef OBJ_whirlpool
 		else if ( type == "whirlpool" )
 			return new opensslHashContext( EVP_whirlpool(), this, type);
 #endif
+*/
 		else if ( type == "pbkdf1(sha1)" )
 			return new opensslPbkdf1Context( EVP_sha1(), this, type );
+#ifdef HAVE_OPENSSL_MD2
 		else if ( type == "pbkdf1(md2)" )
 			return new opensslPbkdf1Context( EVP_md2(), this, type );
+#endif
 		else if ( type == "pbkdf2(sha1)" )
 			return new opensslPbkdf2Context( this, type );
 		else if ( type == "hmac(md5)" )
