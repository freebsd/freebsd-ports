--- inc/Devel/CheckLib.pm.orig	2016-04-13 04:38:16 UTC
+++ inc/Devel/CheckLib.pm
@@ -227,7 +227,7 @@ sub assert_lib {
     # first figure out which headers we can't find ...
     for my $header (@headers) {
         push @use_headers, $header;
-        my ( $ch, $cfile ) = File::Temp::tempfile( 'assertlibXXXXXXXX', SUFFIX => '.c' );
+        my ( $ch, $cfile ) = File::Temp::tempfile( 'assertlibXXXXXXXX', SUFFIX => '.c', TMPDIR => 1 );
         my $ofile = $cfile;
         $ofile =~ s/\.c$/$Config{_o}/;
         print $ch qq{#include <$_>\n} for @use_headers;
@@ -275,7 +275,7 @@ sub assert_lib {
     }
 
     # now do each library in turn with headers
-    my ( $ch, $cfile ) = File::Temp::tempfile( 'assertlibXXXXXXXX', SUFFIX => '.c' );
+    my ( $ch, $cfile ) = File::Temp::tempfile( 'assertlibXXXXXXXX', SUFFIX => '.c', TMPDIR => 1 );
     my $ofile = $cfile;
     $ofile =~ s/\.c$/$Config{_o}/;
     print $ch qq{#include <$_>\n} foreach (@headers);
