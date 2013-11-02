--- Makefile.PL.orig	2001-06-04 13:38:11.000000000 +0000
+++ Makefile.PL
@@ -6,7 +6,7 @@ eval {
     require pdflib_pl;
     die unless $pdflib_pl::VERSION >= 4.0;
 };
-if ($@) {
+if (0) {
     die <<DEATH;
 
 PDFLib requires the pdflib package from http://www.pdflib.com/ version
@@ -20,5 +20,4 @@ DEATH
 WriteMakefile(
     'NAME'	=> 'PDFLib',
     'VERSION_FROM' => 'PDFLib.pm', # finds $VERSION
-    'PREREQ_PM' => { pdflib_pl => 4.0 },
 );
