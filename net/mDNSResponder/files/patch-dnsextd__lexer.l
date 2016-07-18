--- mDNSShared/dnsextd_lexer.l.orig	2016-07-01 01:07:18 UTC
+++ mDNSShared/dnsextd_lexer.l
@@ -23,6 +23,13 @@
 
 extern YYSTYPE yylval;
 
+#if !defined YYSTYPE_yylineno
+#if YY_FLEX_MAJOR_VERSION <= 2 && YY_FLEX_MINOR_VERSION <= 5 && YY_FLEX_SUBMINOR_VERSION <= 4
+int yylineno = 1;
+#endif
+#endif
+
+
 #define YY_NO_INPUT 1
 int  yylex(void);
 
