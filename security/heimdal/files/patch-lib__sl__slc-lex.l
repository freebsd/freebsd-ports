--- lib/sl/slc-lex.l.orig	2016-11-29 01:35:27 UTC
+++ lib/sl/slc-lex.l
@@ -47,8 +47,6 @@ unsigned lineno = 1;
 static void handle_comment(void);
 static char * handle_string(void);
 
-#define YY_NO_UNPUT
-
 #undef ECHO
 
 %}
