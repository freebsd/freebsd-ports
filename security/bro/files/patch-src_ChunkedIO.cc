$OpenBSD: patch-src_ChunkedIO_cc,v 1.1 2015/07/19 16:38:48 sthen Exp $
--- src/ChunkedIO.cc.orig	2015-01-23 18:49:03 UTC
+++ src/ChunkedIO.cc
@@ -689,7 +689,7 @@ bool ChunkedIOSSL::Init()
 		{
 		SSL_load_error_strings();
 
-		ctx = SSL_CTX_new(SSLv3_method());
+		ctx = SSL_CTX_new(SSLv23_method());
 		if ( ! ctx )
 			{
 			Log("can't create SSL context");
