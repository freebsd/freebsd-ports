--- src/data_mgmt/data_import.c.orig	2017-02-21 02:12:00 UTC
+++ src/data_mgmt/data_import.c
@@ -39,6 +39,16 @@
 #include <openssl/evp.h>
 #include <openssl/err.h>
 
+#if OPENSSL_VERSION_NUMBER < 0x1010000fL
+#define	RSA_get0_n(x)	((x)->n)
+#define	RSA_get0_e(x)	((x)->e)
+#define	RSA_get0_d(x)	((x)->d)
+#define	RSA_get0_p(x)	((x)->p)
+#define	RSA_get0_q(x)	((x)->q)
+#define	RSA_get0_dmp1(x)	((x)->dmp1)
+#define	RSA_get0_dmq1(x)	((x)->dmq1)
+#define	RSA_get0_iqmp(x)	((x)->iqmp)
+#endif
 
 /*
  * Global variables
@@ -372,7 +382,7 @@ readX509Cert( const char  *a_pszFile,
 		goto out;
 	}
 
-	if ( EVP_PKEY_type( pKey->type ) != EVP_PKEY_RSA ) {
+	if ( EVP_PKEY_type( EVP_PKEY_id(pKey) ) != EVP_PKEY_RSA ) {
 		logError( TOKEN_RSA_KEY_ERROR );
 
 		X509_free( pX509 );
@@ -691,8 +701,8 @@ createRsaPubKeyObject( RSA               *a_pRsa,
 
 	int  rc = -1;
 
-	int  nLen = BN_num_bytes( a_pRsa->n );
-	int  eLen = BN_num_bytes( a_pRsa->e );
+	int  nLen = BN_num_bytes( RSA_get0_n(a_pRsa) );
+	int  eLen = BN_num_bytes( RSA_get0_e(a_pRsa) );
 
 	CK_RV  rv;
 
@@ -732,8 +742,8 @@ createRsaPubKeyObject( RSA               *a_pRsa,
 	}
 
 	// Get binary representations of the RSA key information
-	BN_bn2bin( a_pRsa->n, n );
-	BN_bn2bin( a_pRsa->e, e );
+	BN_bn2bin( RSA_get0_n(a_pRsa), n );
+	BN_bn2bin( RSA_get0_e(a_pRsa), e );
 
 	// Create the RSA public key object
 	rv = createObject( a_hSession, tAttr, ulAttrCount, a_hObject );
@@ -760,14 +770,14 @@ createRsaPrivKeyObject( RSA               *a_pRsa,
 
 	int  rc = -1;
 
-	int  nLen = BN_num_bytes( a_pRsa->n );
-	int  eLen = BN_num_bytes( a_pRsa->e );
-	int  dLen = BN_num_bytes( a_pRsa->d );
-	int  pLen = BN_num_bytes( a_pRsa->p );
-	int  qLen = BN_num_bytes( a_pRsa->q );
-	int  dmp1Len = BN_num_bytes( a_pRsa->dmp1 );
-	int  dmq1Len = BN_num_bytes( a_pRsa->dmq1 );
-	int  iqmpLen = BN_num_bytes( a_pRsa->iqmp );
+	int  nLen = BN_num_bytes( RSA_get0_n(a_pRsa) );
+	int  eLen = BN_num_bytes( RSA_get0_e(a_pRsa) );
+	int  dLen = BN_num_bytes( RSA_get0_d(a_pRsa) );
+	int  pLen = BN_num_bytes( RSA_get0_p(a_pRsa) );
+	int  qLen = BN_num_bytes( RSA_get0_q(a_pRsa) );
+	int  dmp1Len = BN_num_bytes( RSA_get0_dmp1(a_pRsa) );
+	int  dmq1Len = BN_num_bytes( RSA_get0_dmq1(a_pRsa) );
+	int  iqmpLen = BN_num_bytes( RSA_get0_iqmp(a_pRsa) );
 
 	CK_RV  rv;
 
@@ -821,14 +831,14 @@ createRsaPrivKeyObject( RSA               *a_pRsa,
 	}
 
 	// Get binary representations of the RSA key information
-	BN_bn2bin( a_pRsa->n, n );
-	BN_bn2bin( a_pRsa->e, e );
-	BN_bn2bin( a_pRsa->d, d );
-	BN_bn2bin( a_pRsa->p, p );
-	BN_bn2bin( a_pRsa->q, q );
-	BN_bn2bin( a_pRsa->dmp1, dmp1 );
-	BN_bn2bin( a_pRsa->dmq1, dmq1 );
-	BN_bn2bin( a_pRsa->iqmp, iqmp );
+	BN_bn2bin( RSA_get0_n(a_pRsa), n );
+	BN_bn2bin( RSA_get0_e(a_pRsa), e );
+	BN_bn2bin( RSA_get0_d(a_pRsa), d );
+	BN_bn2bin( RSA_get0_p(a_pRsa), p );
+	BN_bn2bin( RSA_get0_q(a_pRsa), q );
+	BN_bn2bin( RSA_get0_dmp1(a_pRsa), dmp1 );
+	BN_bn2bin( RSA_get0_dmq1(a_pRsa), dmq1 );
+	BN_bn2bin( RSA_get0_iqmp(a_pRsa), iqmp );
 
 	// Create the RSA private key object
 	rv = createObject( a_hSession, tAttr, ulAttrCount, a_hObject );
