--- lib/Apache/GopherHandler.pm.orig	Tue Jul 26 16:19:15 2005
+++ lib/Apache/GopherHandler.pm	Tue Jul 26 16:19:33 2005
@@ -5,9 +5,9 @@
 
 our $VERSION = 0.1;
 
-use Apache::Connection ();
+use Apache2::Connection ();
 use APR::Socket ();
-use Apache::Const -compile => 'OK';
+use Apache2::Const -compile => 'OK';
 use Gopher::Server::ParseRequest;
 #use Gopher::Server::RequestHandler::File;
 use Apache::GopherHandler::TiedSocket;
@@ -54,7 +54,7 @@
 	tie *OUT, 'Apache::GopherHandler::TiedSocket' => $socket;
 	$response->print_to( *OUT );
 
-	return Apache::OK;
+	return Apache2::Const::OK;
 }
 
 1;
