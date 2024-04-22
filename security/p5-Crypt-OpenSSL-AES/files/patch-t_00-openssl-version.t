--- t/00-openssl-version.t.orig	2023-11-10 22:50:53 UTC
+++ t/00-openssl-version.t
@@ -3,7 +3,7 @@ use Test::More tests => 1;
 use File::Which qw(which);
 use Test::More tests => 1;
 
-my $openssl = which('openssl');
+my $openssl = "SSLBIN";
 like($openssl, qr/openssl/, "Found openssl");
 print "$openssl version: ";
 
