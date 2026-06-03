--- t/00-openssl-version.t.orig	2026-04-03 14:37:18 UTC
+++ t/00-openssl-version.t
@@ -3,7 +3,7 @@ use Test::More tests => 1;
 use Crypt::OpenSSL::Guess qw(find_openssl_exec find_openssl_prefix);
 use Test::More tests => 1;
 
-my $openssl = find_openssl_exec(find_openssl_prefix());
+my $openssl = "%%SSLBIN%%";
 ok($openssl, "Found OpenSSL full path");
 if ($openssl) {
     my $version = `$openssl version`;
