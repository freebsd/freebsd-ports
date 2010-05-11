--- lib/Test/HTTP.pm.orig	2009-12-04 12:44:29.000000000 -0800
+++ lib/Test/HTTP.pm	2009-12-04 12:45:12.000000000 -0800
@@ -234,7 +234,7 @@
 sub new_request {
     my ( $self, $method, $uri, @args ) = @_;
     $self->request(
-        HTTP::Request->new( $method => encode_utf8($uri), @args ) );
+        HTTP::Request->new( $method => (is_utf8($uri) ? encode_utf8($uri) : $uri), @args ) );
     $self->request->authorization_basic($self->username, $self->password)
         if (defined $self->username) || (defined $self->password);
     return $self->request;
