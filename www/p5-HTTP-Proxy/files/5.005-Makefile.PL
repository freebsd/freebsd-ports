--- Makefile.PL~	Tue Mar 23 17:31:09 2004
+++ Makefile.PL	Tue Mar 23 17:31:28 2004
@@ -1,5 +1,21 @@
 use ExtUtils::MakeMaker;
 
+if ($] < 5.006) {
+       for my $f (<lib/HTTP/Proxy/*/*.pm>) {
+	       open F,$f;
+	       my @f = <F>;
+	       close F;
+	       for (@f) {
+		       if (/^use base qw\( (.*) \);/o) {
+			       $_ = "use $1;\nuse vars '\@ISA';\n\@ISA = qw( $1 );\n";
+		       }
+	       }
+	       open F, ">$f";
+	       print F @f;
+	       close F;
+       }
+}
+
 WriteMakefile(
     NAME         => 'HTTP::Proxy',
     VERSION_FROM => 'lib/HTTP/Proxy.pm',
