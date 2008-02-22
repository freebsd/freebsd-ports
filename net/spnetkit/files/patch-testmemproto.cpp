--- testmemproto.cpp.orig	2008-02-18 12:24:14.000000000 +0800
+++ testmemproto.cpp	2008-02-18 12:24:24.000000000 +0800
@@ -138,7 +138,7 @@
 
 int main( int argc, char * argv[] )
 {
-	assert ( sigset ( SIGPIPE, SIG_IGN ) != SIG_ERR ) ;
+	assert ( signal ( SIGPIPE, SIG_IGN ) != SIG_ERR ) ;
 
 	const char * host = "127.0.0.1";
 	int port = 11211, loops = 100;
