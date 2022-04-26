--- Makefile.PL.orig	2022-03-08 11:03:33 UTC
+++ Makefile.PL
@@ -182,7 +182,7 @@ if(!defined($have_float128)) { # __float128 support, h
 
   print $SAVE "\n\n" if $save;
 
-  my $mylibs = $mklib . " " . $mylibpth . " -lquadmath";
+  my $mylibs = $mklib . " " . $mylibpth;
 
   # First up, build have_f128.exe from have_f128.c.
   # This simply establishes whether the __float128 type is available.
@@ -392,7 +392,7 @@ my %options = (
   AUTHOR       => 'Sisyphus (sisyphus at (@) cpan dot (.) org)',
   ABSTRACT     => 'Perl interface to the MPFR (floating point) library',
   DEFINE       => $defines,
-  LIBS         => [ '-lmpfr -lgmp -lquadmath' ],
+  LIBS         => [ '-lmpfr -lgmp' ],
   PREREQ_PM    => { 'Test::More' => '0.88', },
   #OBJECT       => '$(O_FILES)', # set below if $Config{nvsize} == 8
   LICENSE      => 'perl',
