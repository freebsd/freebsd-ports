--- Makefile.PL.orig	2014-02-21 16:08:09 UTC
+++ Makefile.PL
@@ -100,6 +100,16 @@ if (!defined($curl_h)) {
      print "Found curl.h in $curl_h\n";
      my @syms;
      my $has_cpp = 0;
+     my @skiplist = qw/
+        CURL_DEPRECATED
+        CURL_DID_MEMORY_FUNC_TYPEDEFS
+        CURL_IGNORE_DEPRECATION
+        CURL_STRICTER
+        CURL_WIN32
+        CURLINC_CURL_H
+        CURLOPT
+        CURLOPTDEPRECATED
+     /;
      open(H_IN, "-|", "cpp", $curl_h) and $has_cpp++;
      unless ($has_cpp) {
          warn "No working cpp ($!).  Parsing curl.h in Perl";
@@ -121,6 +131,7 @@ if (!defined($curl_h)) {
     open (H, "<", $curl_h) or die ("Cannot open $curl_h: ".$!);
     while(<H>) {
         if (/^#define (CURL[A-Za-z0-9_]*)/) {
+            next if $1 ~~ @skiplist;
             push @syms, $1;
         }
     }
