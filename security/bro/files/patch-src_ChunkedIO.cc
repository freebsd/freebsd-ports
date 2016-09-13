--- src/ChunkedIO.cc.orig	2015-09-06 19:43:16 UTC
+++ src/ChunkedIO.cc
@@ -709,7 +709,11 @@ bool ChunkedIOSSL::Init()
 		{
 		SSL_load_error_strings();
 
+#ifndef OPENSSL_NO_SSL3
 		ctx = SSL_CTX_new(SSLv3_method());
+#else
+		ctx = SSL_CTX_new(SSLv23_method());
+#endif
 		if ( ! ctx )
 			{
 			Log("can't create SSL context");
