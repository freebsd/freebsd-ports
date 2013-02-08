$FreeBSD$

--- inc/Devel/CheckLib.pm.orig	2013-01-11 11:43:02.293444337 +0900
+++ inc/Devel/CheckLib.pm	2013-01-11 11:48:47.556449831 +0900
@@ -222,7 +222,7 @@
     for my $header (@headers) {
         push @use_headers, $header;
         my($ch, $cfile) = File::Temp::tempfile(
-            'assertlibXXXXXXXX', SUFFIX => '.c'
+            'assertlibXXXXXXXX', SUFFIX => '.c', TMPDIR => 1,
         );
         print $ch qq{#include <$_>\n} for @use_headers;
         print $ch qq{int main(void) { return 0; }\n};
@@ -262,7 +262,7 @@
 
     # now do each library in turn with headers
     my($ch, $cfile) = File::Temp::tempfile(
-        'assertlibXXXXXXXX', SUFFIX => '.c'
+        'assertlibXXXXXXXX', SUFFIX => '.c', TMPDIR => 1,
     );
     print $ch qq{#include <$_>\n} foreach (@headers);
     print $ch "int main(void) { ".($args{function} || 'return 0;')." }\n";
