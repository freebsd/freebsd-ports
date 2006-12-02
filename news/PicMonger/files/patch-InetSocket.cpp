--- InetSocket.cpp.orig	Tue Mar 14 23:43:09 2000
+++ InetSocket.cpp	Fri Dec  1 22:20:58 2006
@@ -31,7 +31,7 @@
 #include <errno.h>
 #include <unistd.h>
 
-InetSocket::InetSocket(int type=SOCK_STREAM, int protocol=0)
+InetSocket::InetSocket(int type, int protocol)
 	: type_(type), protocol_(protocol)
 {
 	local_fd = socket( PF_INET, type_, protocol_ );
@@ -58,7 +58,7 @@
 	return result;
 }
 
-int InetSocket::s_bind( int port, const char *dotquad = (const char *)0)
+int InetSocket::s_bind( int port, const char *dotquad)
 {
 	// construct local address to which we want our unnamed socket bound
 	if (!dotquad)
