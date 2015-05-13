--- Makefile.PL.orig	2006-02-08 15:06:06 UTC
+++ Makefile.PL
@@ -6,8 +6,7 @@ use ExtUtils::MakeMaker;
 # the package requires modern perl
 require 5.005_03;
 
-my $self = 0; # just to fake $self
-my $version = ExtUtils::MM_Unix::parse_version($self, 'lib/PerlPoint/Converters.pm');
+my $version = ExtUtils::MM_Unix->parse_version('lib/PerlPoint/Converters.pm');
 
 $ok=WriteMakefile(
     'NAME'	=> 'PerlPoint-Converters',
