--- Makefile.PL.orig	2015-02-28 21:17:47.891583000 +0100
+++ Makefile.PL	2015-02-28 21:21:30.013978756 +0100
@@ -78,7 +78,7 @@
     or die "Couldn't run `$exe_path' ($?)\n";
 
 unless (($lib_name, $maj, $min, $letter) = $vers =~
-	/^(OpenSSL)\s+(\d+\.\d+)\.(\d+)([a-z]*)/) {
+	/^(OpenSSL|LibreSSL)\s+(\d+\.\d+)\.(\d+)([a-z]*)/) {
     die "OpenSSL version test failed (`$vers' was returned, but\n"
     . "couldn't be parsed). Either you have bogus OpenSSL or a new version\n"
     . "has changed the version number format.\n";
