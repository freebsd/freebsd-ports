--- t/local/LocalServer.pm.orig	2019-10-10 13:12:38 UTC
+++ t/local/LocalServer.pm
@@ -155,7 +155,7 @@ url.
 sub stop {
     my ($self) = @_;
     get( $self->quit_server );
-    undef $self->{_server_url};
+    $self->kill();
     if ( $self->{_fh} ) {
         close $self->{_fh};
         delete $self->{_fh};
