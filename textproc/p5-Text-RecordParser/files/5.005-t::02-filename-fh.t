--- t/02-filename-fh.t.orig	Mon May 17 22:16:08 2004
+++ t/02-filename-fh.t	Mon May 17 22:19:17 2004
@@ -40,15 +40,15 @@
 {
     my $p = Text::RecordParser->new;
 
-    open my $fh, "<$Bin/data/simpsons.cvs";
-    is ( ref $p->fh( $fh ), 'GLOB', 'fh is a filehandle' );
+    open FH, "<$Bin/data/simpsons.cvs";
+    is ( ref $p->fh( \*FH ), 'GLOB', 'fh is a filehandle' );
 
     #
     # Cause an error by closing the existing fh.
     #
-    close $fh;
-    open my $fh2, "<$Bin/data/simpsons.tab";
-    eval { $p->fh( $fh2 ) };
+    close FH;
+    open FH2, "<$Bin/data/simpsons.tab";
+    eval { $p->fh( \*FH2 ) };
     my $err = $@;
     like ( $err, qr/can't close existing/i, 'fh catches bad close' );
 
@@ -105,8 +105,8 @@
     is( $rec->{'instrument'}, 'drums', 'instrument = "drums"' );
 
     my $filename = "$Bin/data/simpsons.csv";
-    open my $fh, "<$filename" or die "Can't read '$filename': $!";
-    is ( $p->data( $fh ), 1, 'data accepts a filehandle' );
+    open FH, "<$filename" or die "Can't read '$filename': $!";
+    is ( $p->data( \*FH ), 1, 'data accepts a filehandle' );
     is ( UNIVERSAL::isa( $p->fh, 'GLOB' ), 1, 'fh is a GLOB' );
 }
 
