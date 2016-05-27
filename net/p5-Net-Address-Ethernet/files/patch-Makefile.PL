--- Makefile.PL.orig	2016-05-26 14:56:06 UTC
+++ Makefile.PL
@@ -33,11 +33,11 @@ if ($ENV{MTHURN_PERL_DEV})
     {
     warn " EEE did not find DIRFILESEP in Makefile\n";
     } # if
-  if ($s !~ s/(pm_to_blib\(){{\@ARGV}}/$1 . '{@ARGV}'/e)
+  if ($s !~ s/(pm_to_blib\()\{\{\@ARGV\}\}/$1 . '{@ARGV}'/e)
     {
     warn " EEE did not find pm_to_blib@ARGV in Makefile\n";
     } # if
-  if ($s !~ s/(from_to\s+=>\s+){{\@ARGV}}/$1 . '{@ARGV}'/e)
+  if ($s !~ s/(from_to\s+=>\s+)\{\{\@ARGV\}\}/$1 . '{@ARGV}'/e)
     {
     warn " EEE did not find from_to@ARGV in Makefile\n";
     } # if
