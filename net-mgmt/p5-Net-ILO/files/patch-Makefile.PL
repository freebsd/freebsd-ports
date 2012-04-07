--- Makefile.PL.orig	2012-04-06 04:48:50.000000000 -0400
+++ Makefile.PL	2012-04-06 04:51:58.000000000 -0400
@@ -16,3 +16,14 @@
     dist                => { COMPRESS => 'gzip -9f', SUFFIX => 'gz', },
     clean               => { FILES => 'Net-ILO-*' },
 );
+
+package MY;
+
+sub init_PM {
+  my $self = shift;
+
+  $self->SUPER::init_PM(@_);
+
+  # Do not install README.pod
+  delete $self->{PM}{"README.pod"};
+}
