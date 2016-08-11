--- Makefile.PL.orig	2012-05-28 13:24:29 UTC
+++ Makefile.PL
@@ -59,7 +59,7 @@ sub _load_words {
         my ( $file ) = @_;
         my $fh = new FileHandle $file;
         while ( <$fh> ){
-                my ( $key, $data ) = m/^"?([^{"]+)"?: { (.*) }/;
+                my ( $key, $data ) = m/^"?([^{"]+)"?: \{ (.*) }/;
                 next unless $key and $data;
                 my %tags = split /[:,]\s+/, $data;
                 foreach( keys %tags ){
@@ -73,7 +73,7 @@ sub _load_tags {
         my ( $file ) = @_;
         my $fh = new FileHandle $file;
         while ( <$fh> ){
-                my ( $key, $data ) = m/^"?([^{"]+)"?: { (.*) }/;
+                my ( $key, $data ) = m/^"?([^{"]+)"?: \{ (.*) }/;
                 next unless $key and $data;
                 my %tags = split /[:,]\s+/, $data;
                 foreach( keys %tags ){
