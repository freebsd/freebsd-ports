--- lib/sl/slc-lex.l.orig	2013-03-28 14:22:37.561924559 +1030
+++ lib/sl/slc-lex.l	2013-03-28 14:23:21.647677881 +1030
@@ -47,8 +47,6 @@
 static void handle_comment(void);
 static char * handle_string(void);
 
-#define YY_NO_UNPUT
-
 #undef ECHO
 
 %}
