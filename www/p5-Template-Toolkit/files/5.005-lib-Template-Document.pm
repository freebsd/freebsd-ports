--- lib/Template/Document.pm~	Mon Oct  4 12:27:39 2004
+++ lib/Template/Document.pm	Tue Oct  5 16:08:42 2004
@@ -37,17 +37,7 @@
 
 BEGIN {
     # UNICODE is supported in versions of Perl from 5.008 onwards
-    if ($UNICODE = $] > 5.007 ? 1 : 0) {
-        if ($^V gt v5.8.0) {
-            # utf8::is_utf8() available from Perl 5.8.1 onwards
-            *is_utf8 = \&utf8::is_utf8;
-        }
-        elsif ($^V eq v5.8.0) {
-            # use Encode::is_utf8() for Perl 5.8.0
-            require Encode;
-            *is_utf8 = \&Encode::is_utf8;
-        }
-    }
+    $UNICODE = 0;
 }
 
 
