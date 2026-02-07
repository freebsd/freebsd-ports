--- MyTcpSocket.cpp.orig	2010-01-12 14:14:30.000000000 +0800
+++ MyTcpSocket.cpp	2010-01-12 14:14:46.000000000 +0800
@@ -149,7 +149,7 @@
 
 void MyTcpSocket::InitSSLServer()
 {
-	InitializeContext("comb.pem","");
+	InitializeContext("comb.pem",(SSL_METHOD*)"");
 }
 
 
