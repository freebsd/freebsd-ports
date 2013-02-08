--- src/parseMarkup.c.orig	2013-02-01 12:41:08.000000000 +0100
+++ src/parseMarkup.c	2013-02-01 12:41:30.000000000 +0100
@@ -27,6 +27,8 @@
 #include <stdio.h>
 #include <string.h>
 
+static void applyTags ( GtkTextBuffer *buffer, GtkTextMark *tagStart, GtkTextMark *tagEnd );
+
 /* list to hold names of applied tags */
 static GSList *tagList = NULL;
 
