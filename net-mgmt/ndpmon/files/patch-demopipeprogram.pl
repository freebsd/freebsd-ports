
$FreeBSD$

--- demopipeprogram.pl.orig
+++ demopipeprogram.pl
@@ -1,7 +1,7 @@
 #!/usr/bin/perl
 
 my $i=0;
-open DATA, ">>/usr/local/ndpmon/test.txt" or die "Cannot open /usr/local/ndpmon/test.txt for writing\n";
+open DATA, ">>%%PREFIX%%/var/ndpmon_test.txt" or die "Cannot open %%PREFIX%%/var/ndpmon_test.txt for writing\n";
 
 print DATA "-----\n";
 while (<STDIN>) {
@@ -14,4 +14,4 @@
 }
 print DATA "-----\n\n";
 
-close DATA;
\ No newline at end of file
+close DATA;
