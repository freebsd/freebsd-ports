--- doc/info/extract_categories1.sed.orig	2011-08-01 00:39:51.000000000 -0400
+++ doc/info/extract_categories1.sed	2011-12-16 08:12:32.000000000 -0500
@@ -1,6 +1,9 @@
-s/^@def\(fn\|vr\)  *{[^}]*}  *\([^[:blank:]]*\).*/items = ["\2"]/
-s/^@def\(fn\|vr\)x  *{[^}]*}  *\([^[:blank:]]*\).*/if not "\2" in items: items.append ("\2")/
-s/^@end def\(fn\|vr\)/items = []/
+s/^@deffn  *{[^}]*}  *\([^[:blank:]]*\).*/items = ["\1"]/
+s/^@defvr  *{[^}]*}  *\([^[:blank:]]*\).*/items = ["\1"]/
+s/^@deffnx  *{[^}]*}  *\([^[:blank:]]*\).*/if not "\1" in items: items.append ("\1")/
+s/^@defvrx  *{[^}]*}  *\([^[:blank:]]*\).*/if not "\1" in items: items.append ("\1")/
+s/^@end deffn/items = []/
+s/^@end defvr/items = []/
 s/^@node  *\([^,]*\).*/items = ["\1"] # extracted from node/
 s/@opencatbox//
 s/@closecatbox//
