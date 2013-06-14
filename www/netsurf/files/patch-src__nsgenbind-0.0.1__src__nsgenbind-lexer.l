--- ./src/nsgenbind-0.0.1/src/nsgenbind-lexer.l.orig	2013-04-18 23:59:18.000000000 +0200
+++ ./src/nsgenbind-0.0.1/src/nsgenbind-lexer.l	2013-06-13 18:54:25.000000000 +0200
@@ -19,6 +19,16 @@
     yylloc->first_column = yylloc->last_column + 1; \
     yylloc->last_column += yyleng;
 
+
+/* Ensure compatability with bison 2.6 and later */
+#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED && defined NSGENBIND_STYPE_IS_DECLARED
+#define YYSTYPE NSGENBIND_STYPE
+#endif
+
+#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED && defined NSGENBIND_LTYPE_IS_DECLARED
+#define YYLTYPE NSGENBIND_LTYPE
+#endif
+
 %}
 
 /* lexer options */
