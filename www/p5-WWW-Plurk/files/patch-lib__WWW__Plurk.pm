--- lib/WWW/Plurk.pm.orig	2009-08-02 17:46:42.000000000 -0700
+++ lib/WWW/Plurk.pm	2009-08-02 17:47:52.000000000 -0700
@@ -247,7 +247,7 @@
     );
 
     my $ok = 0;
-    $self->_cookies->scan( sub { $ok++ if $_[1] eq 'plurkcookie' } );
+    $self->_cookies->scan( sub { $ok++ if $_[1] eq 'plurkcookiea' } );
     croak "Login for $name failed, no cookie returned"
       unless $ok;
 
@@ -705,7 +705,8 @@
 
 sub _uri_for {
     my ( $self, $service ) = ( shift, shift );
-    my $uri = $self->_base_uri . $self->_path_for( $service );
+    my $uri = $self->_path_for( $service );
+    $uri = $self->_base_uri . $uri if $uri !~ m{^http};
     return $uri unless @_;
     my $params = shift;
     return join '?', $uri, HTML::Tiny->new->query_encode( $params );
