--- Makefile.PL.orig	2020-11-05 20:37:56 UTC
+++ Makefile.PL
@@ -18,11 +18,11 @@ inc '-I/usr/local/opt/openssl/include -I/usr/local/inc
 libs '-L/usr/local/opt/openssl/lib -L/usr/local/lib -L/usr/lib -L/usr/local/ssl/lib -lcrypto -lssl';
 
 if ($Config::Config{myuname} =~ /darwin/i) {
-  cc_optimize_flags('-O2 -g -Wall -Werror -Wno-deprecated-declarations');
+  cc_optimize_flags('-O2 -g -Wall -Wno-deprecated-declarations');
 } elsif ($Config::Config{myuname} =~ /sunos|solaris/i) {
   # Any SunStudio flags?
 } else {
-  cc_optimize_flags('-O2 -g -Wall -Werror');
+  cc_optimize_flags('-O2 -g -Wall');
 }
 
 auto_install();
