--- glyphedit.c~	2010-04-16 09:39:04.000000000 -0500
+++ glyphedit.c	2012-06-05 12:08:22.488759533 -0500
@@ -114,7 +114,7 @@ enum {
  **************************************************************************/
 
 static GtkWidgetClass *parent_class = 0;
-static guint glyphedit_signals[OPERATION_CHANGE + 1];
+static guint glyphedit_signals[COLOR_CHANGE + 1];
 
 /**************************************************************************
  *
