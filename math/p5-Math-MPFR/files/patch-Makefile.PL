--- Makefile.PL.orig	2020-07-13 12:00:38 UTC
+++ Makefile.PL
@@ -193,7 +193,7 @@ else { # we still need to determine whether__float128 
       $mycc = defined($Config{cc}) ? $Config{cc} : 'cc';
     }
 
-    $mylibs = '-lmpfr -lgmp -lquadmath' unless $mylibs;
+    $mylibs = '-lmpfr -lgmp' unless $mylibs;
 
     # Include $mylibs to ensure that -lquadmath is locatable.
     my $out = `$mycc -o have_f128.exe -x c have_f128.in $mylibs 2>&1`;
@@ -336,7 +336,7 @@ my %options = (
   ABSTRACT => 'Perl interface to the MPFR (floating point) library',
   DEFINE   => $defines,
   LIBS => [
-    '-lmpfr -lgmp -lquadmath'
+    '-lmpfr -lgmp'
   ],
   PREREQ_PM => {
                 'Test::More' => '0.88',
