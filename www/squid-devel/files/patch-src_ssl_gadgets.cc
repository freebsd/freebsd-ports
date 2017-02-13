--- src/ssl/gadgets.cc.orig	2017-02-05 21:15:41 UTC
+++ src/ssl/gadgets.cc
@@ -387,7 +387,7 @@ mimicExtensions(Security::CertPointer & 
         DecipherOnly
     };
 
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER))
     const int mimicAlgo = OBJ_obj2nid(mimicCert.get()->cert_info->key->algor->algorithm);
     const bool rsaPkey = (mimicAlgo == NID_rsaEncryption);
 #else
