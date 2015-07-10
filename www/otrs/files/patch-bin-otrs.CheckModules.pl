--- bin/otrs.CheckModules.pl.orig	2015-05-11 14:29:06 UTC
+++ bin/otrs.CheckModules.pl
@@ -42,7 +42,6 @@ BEGIN {
     }
 }
 
-use Linux::Distribution;
 use ExtUtils::MakeMaker;
 use File::Path;
 use Getopt::Long;
@@ -103,7 +102,7 @@ our %DistToInstType = (
     win32as => 'ppm',
 );
 
-our $OSDist = Linux::Distribution::distribution_name() || '';
+our $OSDist = '';
 
 # set win32as if active state perl is installed on windows.
 # for windows installations without active state perl we use the default.
