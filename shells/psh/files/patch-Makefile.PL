--- Makefile.PL.orig	2007-07-06 00:42:01.000000000 -0300
+++ Makefile.PL	2013-10-23 21:22:44.000000000 -0200
@@ -22,7 +22,7 @@
 	my $tmp="
 
 install ::
-	\$(PERL) postinstall.pl \$(SITEPREFIX) \$(PREFIX)
+	\$(PERL) postinstall.pl \$(DESTDIR)\$(SITEPREFIX) \$(DESTDIR)\$(PREFIX)
 
 
 lib/Psh/StrategyBunch.pm : $sb_depends
@@ -67,6 +67,7 @@
 
 WriteMakefile (
 	NAME         => 'psh',
+	PREFIX       => '${PREFIX}',
 	VERSION_FROM => 'lib/Psh.pm',
 	AUTHOR       => 'Gregor N. Purdy (gregor@focusresearch.com)',
 	ABSTRACT     => 'Perl Shell',
