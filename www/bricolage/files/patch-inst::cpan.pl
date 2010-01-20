--- inst/cpan.pl.orig	2008-03-10 04:33:51.000000000 +0900
+++ inst/cpan.pl	2010-01-20 08:42:44.824399835 +0900
@@ -46,6 +46,7 @@
     my $need;
     for my $i (0 .. $#$MOD) {
         next if $MOD->[$i]{found};
+        print "Not found ", $MOD->[$i]->{name}, "\n";
         $need = 1;
         last;
     }
