--- ./functions.c.orig	1993-06-02 19:13:52.000000000 +0200
+++ ./functions.c	2012-08-24 12:53:33.505914506 +0200
@@ -233,6 +233,7 @@
 }
 
 
+void
 do_help()         /* Show online help facility. */
 {
   char help_str[MAXLINE], nextline[MAXLINE], *p ;
@@ -333,6 +334,7 @@
 }
 
 
+void
 do_number()
 {
   int n ;
@@ -371,6 +373,7 @@
 }
 
 
+void
 do_pending()
 {
   if (base != DEC) grey_buttons(DEC) ;    /* Reshow all the keys. */
