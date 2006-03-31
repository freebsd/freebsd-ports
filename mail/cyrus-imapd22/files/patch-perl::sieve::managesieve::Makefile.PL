Index: perl/sieve/managesieve/Makefile.PL
diff -u perl/sieve/managesieve/Makefile.PL.orig perl/sieve/managesieve/Makefile.PL
--- perl/sieve/managesieve/Makefile.PL.orig	Fri Oct 14 05:30:03 2005
+++ perl/sieve/managesieve/Makefile.PL	Sat Apr  1 01:22:10 2006
@@ -66,3 +66,10 @@
     'CC'	=> $ENV{CC},
     'LD'	=> $ENV{CC}
 );
+
+package MY;
+sub install {
+    my $inherited = shift->SUPER::install(@_);
+    $inherited =~ s/(install :: all pure_install) doc_install/$1/;
+    $inherited;
+}
