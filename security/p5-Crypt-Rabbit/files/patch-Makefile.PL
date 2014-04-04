--- Makefile.PL.orig	2014-04-04 14:56:24.000000000 +0000
+++ Makefile.PL	2014-04-04 14:56:41.000000000 +0000
@@ -1,6 +1,6 @@
 use ExtUtils::MakeMaker;
 
-my $opt = '-O3 -funroll-loops -fomit-frame-pointer -fschedule-insns2 -Os -fno-strength-reduce -Wall -pipe';
+my $opt = '-O3 -funroll-loops -fomit-frame-pointer -Os -fno-strength-reduce -Wall -pipe';
 
 WriteMakefile(
     'NAME' => 'Crypt::Rabbit',
