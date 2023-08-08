--- wmclockmon-config/edit.h.orig	2022-12-03 20:48:12 UTC
+++ wmclockmon-config/edit.h
@@ -5,7 +5,7 @@
 #ifndef EDIT_H
 #define EDIT_H
 
-char *newalarm;
+extern char *newalarm;
 
 void edit_dialog(const char *title,
         int on,
