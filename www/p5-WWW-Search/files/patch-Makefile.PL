--- Makefile.PL.orig	2015-11-28 15:17:09 UTC
+++ Makefile.PL
@@ -116,11 +116,11 @@ if (0 && $ENV{MTHURN_PERL_DEV})
     {
     print " EEE did not find DIRFILESEP in Makefile\n";
     } # if
-  if ($s !~ s/(pm_to_blib\(){{\@ARGV}}/$1 . '{@ARGV}'/e)
+  if ($s !~ s/(pm_to_blib\()\{\{\@ARGV\}\}/$1 . '{@ARGV}'/e)
     {
     print " EEE did not find pm_to_blib@ARGV in Makefile\n";
     } # if
-  if ($s !~ s/(from_to\s+=>\s+){{\@ARGV}}/$1 . '{@ARGV}'/e)
+  if ($s !~ s/(from_to\s+=>\s+)\{\{\@ARGV\}\}/$1 . '{@ARGV}'/e)
     {
     print " EEE did not find from_to@ARGV in Makefile\n";
     } # if
