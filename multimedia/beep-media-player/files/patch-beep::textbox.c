--- beep/textbox.c.orig	Sat Feb  7 17:49:22 2004
+++ beep/textbox.c	Sat Feb  7 17:49:58 2004
@@ -142,9 +142,9 @@
 
 void textbox_set_text(TextBox * tb, gchar * text)
 {
-
-    lock_widget(tb);
-    gchar *utf8text;
+	gchar *utf8text;
+    
+	lock_widget(tb);
     if (tb->tb_text) {
 	if (!strcmp(text, tb->tb_text)) {
 	    unlock_widget(tb);
