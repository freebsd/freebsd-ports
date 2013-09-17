--- src/parseMarkup.c.orig	2013-08-31 12:36:08.000000000 +0200
+++ src/parseMarkup.c	2013-09-17 10:09:40.000000000 +0200
@@ -29,6 +29,8 @@
 static GSList *tagList = NULL;
 
 
+static void applyTags ( GtkTextBuffer *buffer, GtkTextIter *iter );
+
 /* remove range of characters from string */
 char * strcremove ( char *str, char *dest, int first, int last )
 {
