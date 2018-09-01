--- zxsig.c.orig	2016-02-29 00:16:50 UTC
+++ zxsig.c
@@ -887,8 +887,13 @@ int zx_report_openssl_err(const char* lo
 #endif
 
   D("%s: len=%d data(%.*s)", lk, len, len, data);
+#if __FreeBSD__
+  D("%s: data above %d", lk, hexdump_zxid("data: ", data, data+len, 4096));
+  D("%s: digest above %d", lk, hexdump_zxid("digest: ", mdbuf, mdbuf+mdlen, 64));
+#else
   D("%s: data above %d", lk, hexdump("data: ", data, data+len, 4096));
   D("%s: digest above %d", lk, hexdump("digest: ", mdbuf, mdbuf+mdlen, 64));
+#endif
 
   if (!priv_key) {
     ERR(priv_key_missing_msg, geteuid(), getegid());
@@ -906,7 +911,11 @@ int zx_report_openssl_err(const char* lo
     if (RSA_sign(EVP_MD_type(evp_digest), mdbuf, mdlen, (unsigned char*)*sig, (unsigned int*)&len, rsa)) {
       DD("data = %s, SHA1 sig = %s, siglen = %d", data, *sig, len);
       D("RSA siglen = %d", len);
+#if __FreeBSD__
+      D("%s: sig above %d", lk, hexdump_zxid("sig: ", *sig, *sig+len, 1024));
+#else
       D("%s: sig above %d", lk, hexdump("sig: ", *sig, *sig+len, 1024));
+#endif
       return len;
     }
 #else
@@ -1042,9 +1051,15 @@ int zxsig_verify_data(int len, char* dat
   else if (!strcmp(mdalg, "SHA512")) { SHA512((unsigned char*)data, len, mdbuf); nid = NID_sha512; }
   else { SHA1((unsigned char*)data, len, mdbuf); nid = NID_sha1; }
 #endif
+#if __FreeBSD__
+  D("%s: vfy data len=%d above %d", lk, len, hexdump_zxid("data: ", data, data+len, 8192));
+  D("%s: vfy sig above %d",  lk, hexdump_zxid("sig: ",  sig,  sig+siglen, 8192));
+  D("%s: vfy md above %d", lk, hexdump_zxid("md: ", mdbuf, mdbuf+64, 64));
+#else
   D("%s: vfy data len=%d above %d", lk, len, hexdump("data: ", data, data+len, 8192));
   D("%s: vfy sig above %d",  lk, hexdump("sig: ",  sig,  sig+siglen, 8192));
   D("%s: vfy md above %d", lk, hexdump("md: ", mdbuf, mdbuf+64, 64));
+#endif
   
   evp_pubk = X509_get_pubkey(cert);
   if (!evp_pubk) {
@@ -1080,7 +1095,11 @@ int zxsig_verify_data(int len, char* dat
     if (!verdict) {
       ERR("RSA signature verify in %s data failed. Perhaps you have bad or no certificate(%p) len=%d data=%p siglen=%d sig=%p", lk, cert, len, data, siglen, sig);
       zx_report_openssl_err(lk);
+#if __FreeBSD__
+      D("RSA_vfy(%s) bad sig above %d",  lk, hexdump_zxid("sig: ",  sig,  sig+siglen, 4096));
+#else
       D("RSA_vfy(%s) bad sig above %d",  lk, hexdump("sig: ",  sig,  sig+siglen, 4096));
+#endif
       return ZXSIG_VFY_FAIL;
     } else {
       D("RSA verify OK %d", verdict);
@@ -1115,7 +1134,11 @@ int zxsig_verify_data(int len, char* dat
     if (!verdict) {
       ERR("DSA signature verify in %s data failed. Perhaps you have bad or no certificate(%p) len=%d data=%p siglen=%d sig=%p", lk, cert, len, data, siglen, sig);
       zx_report_openssl_err(lk);
+#if __FreeBSD__
+      D("DSA_vfy(%s) sig above %d",  lk, hexdump_zxid("sig: ",  sig,  sig+siglen, 4096));
+#else
       D("DSA_vfy(%s) sig above %d",  lk, hexdump("sig: ",  sig,  sig+siglen, 4096));
+#endif
       return ZXSIG_VFY_FAIL;
     } else {
       D("DSA verify OK %d", verdict);

