Index: Makefile.PL
diff -u Makefile.PL.orig Makefile.PL
--- Makefile.PL.orig	2013-12-09 17:30:29.282987698 +0900
+++ Makefile.PL	2013-12-09 17:30:35.243986223 +0900
@@ -101,3 +101,10 @@
     close(OUT) || die "Failed to close file 'config.h' [$!]";
     close(IN)  || die "Failed to close file 'config.h.in' [$!]";
 }
+
+package MY;
+sub install {
+    my $inherited = shift->SUPER::install(@_);
+    $inherited =~ s/(install :: (all )?pure_install) doc_install/$1/;
+    $inherited;
+}
