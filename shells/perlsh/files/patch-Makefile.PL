--- Makefile.PL.orig	Thu Apr  7 08:01:59 2005
+++ Makefile.PL	Thu Apr  7 08:01:42 2005
@@ -67,6 +67,7 @@
 
 WriteMakefile (
 	NAME         => 'psh',
+	PREFIX       => '${PREFIX}',
 	VERSION_FROM => 'lib/Psh.pm',
 	AUTHOR       => 'Gregor N. Purdy (gregor@focusresearch.com)',
 	ABSTRACT     => 'Perl Shell',
