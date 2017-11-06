--- src/vmime/platforms/posix/posixSocket.cpp.orig	2017-01-03 20:00:08 UTC
+++ src/vmime/platforms/posix/posixSocket.cpp
@@ -873,7 +873,7 @@ void posixSocket::throwSocketError(const
 
 		char errbuf[512];
 
-	#if (_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600) && ! _GNU_SOURCE
+	#if 1
 
 		// XSI-compliant strerror_r()
 		strerror_r(err, errbuf, sizeof(errbuf));
