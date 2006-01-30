--- lib/XML/Doctype.pm.orig	Tue Dec 27 23:27:13 2005
+++ lib/XML/Doctype.pm	Mon Jan 30 23:43:38 2006
@@ -62,7 +62,9 @@
 =cut
 
 use strict ;
+use Config;
 use vars qw( $VERSION %_default_dtds ) ;
+use lib $Config{sitelib};
 use fields (
    'ELTS',       # A hash of declared & undeclared elements, keyed by name
    'NAME',       # The root node (the name from the DOCTYPE decl).
