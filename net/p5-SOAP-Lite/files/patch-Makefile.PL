--- Makefile.PL.orig	Wed Jun  2 12:27:31 2004
+++ Makefile.PL	Wed Jun  2 12:28:46 2004
@@ -67,6 +67,7 @@
 
 $help and print($helptext), exit;
 
+$prompt and
 ExtUtils::MakeMaker::prompt(<<EOI . "Press <enter> to see the detailed list.");
 
 We are about to install SOAP::Lite and for your convenience will provide
