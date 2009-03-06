--- source/iked/conf.parse.yy.orig	2008-06-10 04:24:20.000000000 +0200
+++ source/iked/conf.parse.yy	2009-03-06 11:40:56.000000000 +0100
@@ -43,7 +43,7 @@
 %defines
 %define "parser_class_name" "conf_parser"
 
-%{
+%code requires {
 
 #include <string>
 
@@ -51,7 +51,7 @@
 
 typedef class _IKED IKED;
 
-%}
+}
 
 // The parsing context.
 %parse-param { IKED & iked }
