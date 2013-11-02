--- config/install.pl.orig	2002-11-29 20:49:01.000000000 +0900
+++ config/install.pl	2013-11-03 02:31:07.000000000 +0900
@@ -372,7 +372,7 @@
 
 if($cfg{TEXPATH}) {
   print "\nNote: trying to install LaTeX2HTML style files in TeX directory tree\n     ($cfg{TEXPATH})\n";
-  unless(mkpath($cfg{TEXPATH})) {
+  unless(mkpath($ENV{DESTDIR}.$cfg{TEXPATH})) {
   #my $testpath = $cfg{TEXPATH}; # to strip (latex2)html
   #$testpath =~ s/[$dd$dd][^$dd$dd]*$//;
   #if((-d $cfg{TEXPATH} && !-w _) || (-d $testpath && !-w _)) {
