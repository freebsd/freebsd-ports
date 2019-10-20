--- Makefile.PL.orig	2014-02-21 16:08:09 UTC
+++ Makefile.PL
@@ -121,13 +121,14 @@ if (!defined($curl_h)) {
     open (H, "<", $curl_h) or die ("Cannot open $curl_h: ".$!);
     while(<H>) {
         if (/^#define (CURL[A-Za-z0-9_]*)/) {
+            next if ($1 eq 'CURL_DID_MEMORY_FUNC_TYPEDEFS' || $1 eq 'CURL_STRICTER' || $1 eq 'CURLINC_CURL_H' );
             push @syms, $1;
         }
     }
     close H;
 
     for my $e (sort @syms) {
-       if($e =~ /(OBSOLETE|^CURL_EXTERN|_LAST\z|_LASTENTRY\z)/) {
+       if($e =~ /(OBSOLETE|^CURL_EXTERN|_LAST\z|_LASTENTRY\z|^CURLINC_)/) {
           next;
        }
        my ($group) = $e =~ m/^([^_]+_)/;
