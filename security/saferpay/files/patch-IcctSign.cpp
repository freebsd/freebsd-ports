--- saferpay/IcctSign.cpp.orig	Wed Feb 19 12:17:14 2003
+++ saferpay/IcctSign.cpp	Wed Feb 19 12:19:52 2003
@@ -32,7 +32,11 @@
 	#define RSA_generate_key_S RSA_generate_key
 #endif
 
+#ifdef HAVE_SSLENGINE_H
+HRESULT ICCT_Signature(const UCHAR* pucPrivateKey, int cbPrivateKey, UCHAR* pMessage,
+#else
 HRESULT ICCT_Signature(UCHAR* pucPrivateKey, int cbPrivateKey, UCHAR* pMessage,
+#endif
 					   ULONG cbMessage, /*[out]*/ UCHAR* pDigest, ULONG* pcbDigest)
 {
 	RSA *pPrivateKey = RSA_new();
@@ -59,7 +63,11 @@
 	return -1;
 }
 
+#ifdef HAVE_SSLENGINE_H
+HRESULT ICCT_Verify(const UCHAR* pucPublicKey, int cbPublicKey, UCHAR* pMessage, ULONG cbMessage,
+#else
 HRESULT ICCT_Verify(UCHAR* pucPublicKey, int cbPublicKey, UCHAR* pMessage, ULONG cbMessage,
+#endif
 					/*[in]*/ UCHAR* pDigest, ULONG cbDigest)
 {
 	RSA *pPublicKey = RSA_new();
@@ -91,7 +99,11 @@
 	return -1;
 }
 
+#ifdef HAVE_SSLENGINE_H
+HRESULT ICCT_CryptDigest(const UCHAR* pucPublicKey, int cbPublicKey,
+#else
 HRESULT ICCT_CryptDigest(UCHAR* pucPublicKey, int cbPublicKey,
+#endif
 					UCHAR* pDigest, ULONG cbDigest, UCHAR * pOut, ULONG * cbOut)
 {
 	RSA *pPublicKey = RSA_new();
@@ -126,7 +138,11 @@
 	return -1;
 }
 
+#ifdef HAVE_SSLENGINE_H
+HRESULT ICCT_DecryptDigest(const UCHAR* pucPrivateKey, int cbPrivateKey,
+#else
 HRESULT ICCT_DecryptDigest(UCHAR* pucPrivateKey, int cbPrivateKey,
+#endif
 					UCHAR * pIn, ULONG cbIn, UCHAR* pDigest, ULONG * cbDigest)
 {
 	RSA *pPrivateKey = RSA_new();
@@ -158,7 +174,11 @@
 						  int* cbPrivateKey, UCHAR* Seed,
 						  int cbSeed)
 {
+#ifdef HAVE_SSLENGINE_H
+	RSA *pPrivateKey = RSA_new_method((ENGINE *)RSA_PKCS1_SSLeay());
+#else
 	RSA *pPrivateKey = RSA_new_method(RSA_PKCS1_SSLeay());
+#endif
 
 	UCHAR* pPubK = pucPublicKey;
 	UCHAR* pPrivK = pucPrivateKey;
