--- callbacks.c.orig	Thu Feb 13 19:14:15 2003
+++ callbacks.c	Thu Feb 13 19:14:42 2003
@@ -66,7 +66,7 @@
 extern Widget hex_text_widget;        /* hex (bottom) window */
 extern Widget packet_label;
 
-extern char *sys_errlist[];
+extern __const char *__const sys_errlist[];
 
 #ifdef __STDC__
 void redisplay_current_list(void);
