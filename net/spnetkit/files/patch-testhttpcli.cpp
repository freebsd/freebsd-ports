--- testhttpcli.cpp.orig	2008-02-18 12:22:11.000000000 +0800
+++ testhttpcli.cpp	2008-02-18 12:24:00.000000000 +0800
@@ -35,7 +35,7 @@
 
 int main( int argc, char * argv[] )
 {
-	assert ( sigset ( SIGPIPE, SIG_IGN ) != SIG_ERR ) ;
+    assert ( signal ( SIGPIPE, SIG_IGN ) != SIG_ERR ) ;
 
 	SP_NKLog::init4test( "testhttpcli" );
 	SP_NKLog::setLogLevel( LOG_DEBUG );
