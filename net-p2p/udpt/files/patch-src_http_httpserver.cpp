--- src/http/httpserver.cpp.orig	2020-02-02 18:34:05 UTC
+++ src/http/httpserver.cpp
@@ -52,7 +52,7 @@ namespace UDPT
 			sa.sin_family = AF_INET;
 			sa.sin_port = htons (port);
 
-			r = bind (this->srv, (SOCKADDR*)&sa, sizeof(sa));
+			r = ::bind (this->srv, (SOCKADDR*)&sa, sizeof(sa));
 			if (r == SOCKET_ERROR)
 			{
 				throw ServerException (2, "Failed to bind socket");
