--- Makefile.PL.orig	2021-02-12 11:08:52 UTC
+++ Makefile.PL
@@ -206,7 +206,7 @@ else { # we still need to determine whether__float128 
 
     print $SAVE "\n\n" if $save;
 
-    my $mylibs = $mklib . " " . $mylibpth . " -lquadmath";
+    my $mylibs = $mklib . " " . $mylibpth;
 
     my $out = `$mycc -o have_f128.exe -x c have_f128.in 2>&1`;
 
@@ -347,7 +347,7 @@ my %options = (
   AUTHOR       => 'Sisyphus (sisyphus at (@) cpan dot (.) org)',
   ABSTRACT     => 'Perl interface to the MPFR (floating point) library',
   DEFINE       => $defines,
-  LIBS         => [ '-lmpfr -lgmp -lquadmath' ],
+  LIBS         => [ '-lmpfr -lgmp' ],
   PREREQ_PM    => { 'Test::More' => '0.88', },
   #OBJECT       => '$(O_FILES)', # set below if $Config{nvsize} == 8
   LICENSE      => 'perl',
