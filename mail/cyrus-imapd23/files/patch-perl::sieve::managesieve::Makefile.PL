Index: perl/sieve/managesieve/Makefile.PL
diff -u perl/sieve/managesieve/Makefile.PL.orig perl/sieve/managesieve/Makefile.PL
--- perl/sieve/managesieve/Makefile.PL.orig	Thu Oct 23 03:50:27 2003
+++ perl/sieve/managesieve/Makefile.PL	Sun Dec 12 04:21:55 2004
@@ -64,3 +64,10 @@
     'DEFINE'	=> '-DPERL_POLLUTE',     # e.g., '-DHAVE_SOMETHING' 
     'INC'	=> "-I../lib/ -I../../../lib/ $SASL_INC $OPENSSL_INC",
 );
+
+package MY;
+sub install {
+    my $inherited = shift->SUPER::install(@_);
+    $inherited =~ s/(install :: all pure_install) doc_install/$1/;
+    $inherited;
+}
