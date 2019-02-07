--- source/iked/conf.parse.yy.orig	2013-04-03 07:10:43 UTC
+++ source/iked/conf.parse.yy
@@ -41,7 +41,7 @@
 
 %skeleton "lalr1.cc"
 %defines
-%define "parser_class_name" "conf_parser"
+%define api.parser.class {conf_parser}
 
 %{
 
@@ -56,7 +56,7 @@
 %lex-param   { IKED & iked }
 %locations
 %debug
-%error-verbose
+%define parse.error verbose
 
 // Symbols.
 %union
