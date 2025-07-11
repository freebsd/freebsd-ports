--- lib/BibTeX/Parser/Entry.pm.orig	2025-07-11 19:47:56 UTC
+++ lib/BibTeX/Parser/Entry.pm
@@ -7,7 +7,7 @@ use BibTeX::Parser::Author;
 use strict;
 
 use BibTeX::Parser::Author;
-use BibTeX::Parser qw (_split_braced_string);
+use BibTeX::Parser;
 
 sub new {
 	my ($class, $type, $key, $parse_ok, $fieldsref) = @_;
