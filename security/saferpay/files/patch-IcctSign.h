--- saferpay/IcctSign.h.orig	Wed Apr 17 13:40:14 2002
+++ saferpay/IcctSign.h	Wed Feb 19 12:22:17 2003
@@ -11,11 +11,19 @@
 						  int* cbPrivateKey, UCHAR* Seed,
 						  int cbSeed = 0);
 
+#ifdef HAVE_SSLENGINE_H
+HRESULT ICCT_Signature(const UCHAR* pucPrivateKey, int cbPrivateKey, UCHAR* pMessage,
+					   ULONG cbMessage, /*[out]*/ UCHAR* pDigest, ULONG* pcbDigest);
+
+HRESULT ICCT_Verify(const UCHAR* pucPublicKey, int cbPublicKey, UCHAR* pMessage,
+					ULONG cbMessage, /*[in]*/ UCHAR* pDigest, ULONG cbDigest);
+#else
 HRESULT ICCT_Signature(UCHAR* pucPrivateKey, int cbPrivateKey, UCHAR* pMessage,
 					   ULONG cbMessage, /*[out]*/ UCHAR* pDigest, ULONG* pcbDigest);
 
 HRESULT ICCT_Verify(UCHAR* pucPublicKey, int cbPublicKey, UCHAR* pMessage,
 					ULONG cbMessage, /*[in]*/ UCHAR* pDigest, ULONG cbDigest);
+#endif
 
 
 HRESULT ICCT_CryptDigest(UCHAR* pucPublicKey, int cbPublicKey,
