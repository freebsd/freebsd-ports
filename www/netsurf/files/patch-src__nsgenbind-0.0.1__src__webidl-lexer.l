--- ./src/nsgenbind-0.0.1/src/webidl-lexer.l.orig	2013-04-18 23:59:18.000000000 +0200
+++ ./src/nsgenbind-0.0.1/src/webidl-lexer.l	2013-06-13 18:54:25.000000000 +0200
@@ -27,6 +27,15 @@
     yylloc->first_column = yylloc->last_column + 1; \
     yylloc->last_column += yyleng;
 
+/* Ensure compatability with bison 2.6 and later */
+#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED && defined WEBIDL_STYPE_IS_DECLARED
+#define YYSTYPE WEBIDL_STYPE
+#endif
+
+#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED && defined WEBIDL_LTYPE_IS_DECLARED
+#define YYLTYPE WEBIDL_LTYPE
+#endif
+
 %}
 
 
