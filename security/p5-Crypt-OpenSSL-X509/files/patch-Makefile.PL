--- Makefile.PL.orig	2021-05-13 16:03:15 UTC
+++ Makefile.PL
@@ -25,7 +25,7 @@ if ($^O ne 'MSWin32' and my $prefix = `brew --prefix -
   libs '-L/usr/local/opt/openssl/lib -L/usr/local/lib -L/usr/lib -L/usr/local/ssl/lib -lcrypto -lssl';
 }
 
-my $cc_option_flags = '-O2 -g -Wall -Werror';
+my $cc_option_flags = '-O2 -g -Wall';
 
 if ($Config::Config{gccversion} =~ /llvm/i) {
   if ($Config::Config{perl_version} <= 20) {
