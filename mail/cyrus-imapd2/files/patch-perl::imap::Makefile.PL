Index: perl/imap/Makefile.PL
diff -u perl/imap/Makefile.PL.orig perl/imap/Makefile.PL
--- perl/imap/Makefile.PL.orig	Thu Oct 23 03:50:18 2003
+++ perl/imap/Makefile.PL	Sun Dec 12 04:20:10 2004
@@ -70,3 +70,10 @@
     'INC'	=> "-I../../lib $SASL_INC $OPENSSL_INC", 
     'EXE_FILES' => [cyradm],
 );
+
+package MY;
+sub install {
+    my $inherited = shift->SUPER::install(@_);
+    $inherited =~ s/(install :: all pure_install) doc_install/$1/;
+    $inherited;
+}
