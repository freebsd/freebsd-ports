--- src/lang-bison.y.orig	2012-02-21 14:12:06.000000000 +0100
+++ src/lang-bison.y	2012-02-21 14:12:27.000000000 +0100
@@ -15,7 +15,7 @@
 
 std::stack<PhraseBlock *> pbs;
 
-int yy_lang_error (char *s);
+int yy_lang_error (const char *s);
 int yy_lang_lex (void);
 %}
 
@@ -121,7 +121,7 @@
 
 extern char *yy_lang_text;
 
-int yy_lang_error (char *s)
+int yy_lang_error (const char *s)
 {
 	fprintf (stderr, "lang-parse: %s in line %i, at symbol \"%s\"\n",
 			s, lang_lineno, yy_lang_text);
