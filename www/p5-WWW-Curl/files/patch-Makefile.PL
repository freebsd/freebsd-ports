--- Makefile.PL.orig	2014-02-21 16:08:09 UTC
+++ Makefile.PL
@@ -121,6 +121,7 @@ if (!defined($curl_h)) {
     open (H, "<", $curl_h) or die ("Cannot open $curl_h: ".$!);
     while(<H>) {
         if (/^#define (CURL[A-Za-z0-9_]*)/) {
+            next if $1 eq 'CURL_DID_MEMORY_FUNC_TYPEDEFS';
             push @syms, $1;
         }
     }
