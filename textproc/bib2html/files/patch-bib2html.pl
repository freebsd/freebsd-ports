--- bib2html.pl.orig	Tue Jan 13 09:00:38 2004
+++ bib2html.pl	Tue Jan 13 09:01:05 2004
@@ -33,7 +33,7 @@
 my $PERLSCRIPTDIR ;
 BEGIN{
   # Where is this script?
-  $PERLSCRIPTDIR = "$0";
+  $PERLSCRIPTDIR = "%%SITE_PERL%%/Bib2HTML";
   my $scriptdir = dirname( $PERLSCRIPTDIR );
   while ( -e $PERLSCRIPTDIR && -l $PERLSCRIPTDIR ) {
     $PERLSCRIPTDIR = readlink($PERLSCRIPTDIR);
