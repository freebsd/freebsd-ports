--- Makefile.PL.orig	2014-02-21 08:08:09.000000000 -0800
+++ Makefile.PL	2020-04-20 15:36:35.008798000 -0700
@@ -100,6 +100,13 @@
      print "Found curl.h in $curl_h\n";
      my @syms;
      my $has_cpp = 0;
+     my @skiplist = qw/
+        CURL_DID_MEMORY_FUNC_TYPEDEFS
+        CURL_STRICTER
+        CURLINC_CURL_H
+        CURL_WIN32
+        CURLOPT
+     /;
      open(H_IN, "-|", "cpp", $curl_h) and $has_cpp++;
      unless ($has_cpp) {
          warn "No working cpp ($!).  Parsing curl.h in Perl";
@@ -121,6 +128,7 @@
     open (H, "<", $curl_h) or die ("Cannot open $curl_h: ".$!);
     while(<H>) {
         if (/^#define (CURL[A-Za-z0-9_]*)/) {
+            next if $1 ~~ @skiplist;
             push @syms, $1;
         }
     }
