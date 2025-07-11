--- lib/BibTeX/Parser/Author.pm.orig	2025-07-11 19:47:50 UTC
+++ lib/BibTeX/Parser/Author.pm
@@ -5,7 +5,7 @@ use strict;
 
 use warnings;
 use strict;
-use BibTeX::Parser qw (_split_braced_string);
+use BibTeX::Parser;
 
 use overload
 	'""' => \&to_string;
