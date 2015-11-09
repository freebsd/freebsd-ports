--- Makefile.PL.orig	2010-08-09 13:49:20 UTC
+++ Makefile.PL
@@ -1,8 +1,7 @@
 use ExtUtils::MakeMaker;
 use ExtUtils::Command qw(cp);
 
-my $build_simplex = prompt("Do you wish to include some simple protocol extensions (pulls in Parse::RecDescent)? ",
-    $ENV{OVERRIDE_DEFAULT_SX} ? $ENV{OVERRIDE_DEFAULT_SX} : "y");
+my $build_simplex = $ENV{WITH_SX} ? 'Y' : '';
 
 if( $build_simplex =~ m/[Yy]/ ) {
     local @ARGV = qw(contrib/SimpleX.pod contrib/SimpleX.pm .);
