--- xmlparser.c.orig	Tue Apr  6 14:16:09 2004
+++ xmlparser.c	Wed Apr 21 12:38:50 2004
@@ -526,8 +526,9 @@
 		       XML_Content *model)
 {
   XMLParser* parser;
+  VALUE content;
   GET_PARSER(recv, parser);
-  VALUE content = makeContentArray(parser, model);
+  content = makeContentArray(parser, model);
   rb_yield(rb_ary_new3(4, symELEMENT_DECL,
 		       TO_(rb_str_new2(name)),
 		       content, recv));
@@ -929,8 +930,9 @@
 		     XML_Content *model)
 {
   XMLParser* parser;
+  VALUE content;
   GET_PARSER(recv, parser);
-  VALUE content = makeContentArray(parser, model);
+  content = makeContentArray(parser, model);
   rb_funcall((VALUE)recv, id_elementDeclHandler, 2,
 	     TO_(rb_str_new2(name)), content);
 }
