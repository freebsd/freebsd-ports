--- dfasyn/parse.y.orig	Sat Jul 15 22:28:52 2006
+++ dfasyn/parse.y	Tue Aug 15 19:35:07 2006
@@ -242,6 +242,7 @@
                 ;
 
 tag_decl : TAG STRING EQUAL expr { define_tag($2, $4); }
+         ;
 
 entrystruct_decl :
               ENTRYSTRUCT STRING STRING   { define_entrystruct($2, $3); }
