--- testmemcli.cpp.orig	2008-02-18 12:24:33.000000000 +0800
+++ testmemcli.cpp	2008-02-18 12:24:40.000000000 +0800
@@ -98,7 +98,7 @@
 
 int main( int argc, char * argv[] )
 {
-	assert ( sigset ( SIGPIPE, SIG_IGN ) != SIG_ERR ) ;
+	assert ( signal ( SIGPIPE, SIG_IGN ) != SIG_ERR ) ;
 
 	const char * config = "testmemcli.ini";
 	int loops = 100;
