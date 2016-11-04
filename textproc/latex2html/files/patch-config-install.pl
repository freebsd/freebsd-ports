--- config/install.pl.orig	2016-04-19 16:52:35 UTC
+++ config/install.pl
@@ -372,7 +372,7 @@ foreach $item (sort keys %Install_items)
 
 if($cfg{TEXPATH}) {
   print "\nNote: trying to install LaTeX2HTML style files in TeX directory tree\n     ($cfg{TEXPATH})\n";
-  unless(mkpath($cfg{TEXPATH})) {
+  unless(mkpath($ENV{DESTDIR}.$cfg{TEXPATH})) {
   #my $testpath = $cfg{TEXPATH}; # to strip (latex2)html
   #$testpath =~ s/[$dd$dd][^$dd$dd]*$//;
   #if((-d $cfg{TEXPATH} && !-w _) || (-d $testpath && !-w _)) {
