--- cpp/client/ct.cc.orig	2017-02-11 20:58:57 UTC
+++ cpp/client/ct.cc
@@ -530,7 +530,7 @@ static void ProofToExtensionData() {
                       << " for writing:" << strerror(errno);
 
 // Work around broken PEM_write() declaration in older OpenSSL versions.
-#if OPENSSL_VERSION_NUMBER < 0x10002000L
+#if OPENSSL_VERSION_NUMBER < 0x10002000L || defined(LIBRESSL_VERSION_NUMBER)
   PEM_write(out, const_cast<char*>(kPEMLabel), const_cast<char*>(""),
             const_cast<unsigned char*>(reinterpret_cast<const unsigned char*>(
                 extension_data_out.str().data())),
