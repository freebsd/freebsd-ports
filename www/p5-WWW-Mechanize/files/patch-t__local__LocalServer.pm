--- t/local/LocalServer.pm.orig	2011-08-05 12:48:08.000000000 -0800
+++ t/local/LocalServer.pm	2012-04-06 14:37:36.000000000 -0800
@@ -152,7 +152,7 @@
 sub stop {
     my ($self) = @_;
     get( $self->quit_server );
-    undef $self->{_server_url};
+    $self->kill();
     if ( $self->{_fh} ) {
         close $self->{_fh};
         delete $self->{_fh};
