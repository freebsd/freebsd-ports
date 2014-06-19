--- lib/XML/TreeBuilder.pm.orig	2014-06-02 15:04:05.800362621 +0200
+++ lib/XML/TreeBuilder.pm	2014-06-02 15:04:16.800023360 +0200
@@ -8,7 +8,7 @@
 use XML::Parser  ();
 use Carp;
 use IO::File;
-use XML::Catalog 1.02;
+use XML::Catalog 1.0.2;
 use File::Basename;
 use File::Spec;
 use vars qw(@ISA $VERSION);
