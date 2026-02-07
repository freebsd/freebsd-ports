--- lib/XML/Doctype.pm.orig	2016-06-20 16:08:38 UTC
+++ lib/XML/Doctype.pm
@@ -62,7 +62,9 @@ XML::Doctype::ENITITY
 =cut
 
 use strict ;
+use Config;
 use vars qw( $VERSION %_default_dtds ) ;
+use lib $Config{sitelib};
 use fields (
    'ELTS',       # A hash of declared & undeclared elements, keyed by name
    'NAME',       # The root node (the name from the DOCTYPE decl).
