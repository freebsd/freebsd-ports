Index: perl/sieve/acap/Makefile.PL
diff -u perl/sieve/acap/Makefile.PL.orig perl/sieve/acap/Makefile.PL
--- perl/sieve/acap/Makefile.PL.orig	Wed Jun 14 05:32:21 2000
+++ perl/sieve/acap/Makefile.PL	Mon Dec 20 00:37:38 2004
@@ -51,3 +51,10 @@
     'DEFINE'	=> '-DPERL_POLLUTE',     # e.g., '-DHAVE_SOMETHING' 
     'INC'	=> "-I../../../acap/ $SASL_INC",     # e.g., '-I/usr/include/other' 
 );
+
+package MY;
+sub install {
+    my $inherited = shift->SUPER::install(@_);
+    $inherited =~ s/(install :: all pure_install) doc_install/$1/;
+    $inherited;
+}
