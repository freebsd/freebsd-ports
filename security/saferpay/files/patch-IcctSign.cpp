--- saferpay/IcctSign.cpp.orig	Wed Sep 24 15:13:06 2003
+++ saferpay/IcctSign.cpp	Tue Jan  6 15:46:01 2004
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
@@ -64,7 +68,12 @@
 	return -1;
 }
 
+#ifdef HAVE_SSLENGINE_H
+HRESULT ICCT_Verify(const UCHAR* pucPublicKey, int cbPublicKey, UCHAR* pMessage, ULONG cbMessage,
+#else
 HRESULT ICCT_Verify(UCHAR* pucPublicKey, int cbPublicKey, UCHAR* pMessage, ULONG cbMessage,
+#endif
+
 					/*[in]*/ UCHAR* pDigest, ULONG cbDigest)
 {
 	RSA *pPublicKey = RSA_new();
@@ -255,3 +264,4 @@
 	}
 }
 */
+
