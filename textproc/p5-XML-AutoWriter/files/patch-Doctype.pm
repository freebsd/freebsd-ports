--- lib/XML/Doctype.pm.orig	Mon May  3 13:57:15 2004
+++ lib/XML/Doctype.pm	Mon May  3 14:04:55 2004
@@ -62,7 +62,9 @@
 =cut
 
 use strict ;
+use Config;
 use vars qw( $VERSION %_default_dtds ) ;
+use lib $Config{sitelib};
 use fields (
    'ELTS',       # A hash of declared & undeclared elements, keyed by name
    'NAME',       # The root node (the name from the DOCTYPE decl).
