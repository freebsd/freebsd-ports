--- Makefile.PL.orig	2022-05-03 17:53:35 UTC
+++ Makefile.PL
@@ -22,7 +22,7 @@ my $api_ver = '0x10100000L';  # (version 1.1.0)
 my $cc_option_flags = " -DOPENSSL_API_COMPAT=$api_ver -O2 -g";
 
 if ($Config::Config{cc} =~ /gcc/i) {
-  $cc_option_flags .= $ENV{AUTHOR_TESTING} ? ' -Wall -Werror' : ' -Wall';
+  $cc_option_flags .= $ENV{AUTHOR_TESTING} ? ' -Wall' : ' -Wall';
 } else {
   $cc_option_flags .= '';
 }
