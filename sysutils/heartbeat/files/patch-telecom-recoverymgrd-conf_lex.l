--- telecom/recoverymgrd/conf_lex.l.orig	2008-08-18 07:32:19.000000000 -0500
+++ telecom/recoverymgrd/conf_lex.l	2013-09-05 19:11:32.000000000 -0500
@@ -56,9 +56,11 @@
 %{
 FILE *yyget_out(void);
 %}
+/*
 %{
 int yyget_leng(void);
 %}
+*/
 %{
 char *yyget_text(void);
 %}
