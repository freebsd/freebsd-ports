--- GTKMain.h.orig	2002-02-21 16:43:49.000000000 +0100
+++ GTKMain.h	2011-04-15 20:17:34.000000000 +0200
@@ -31,8 +31,8 @@
 - (void) mainQuit;
 - (gint) mainIteration;
 - (gint) mainIterationDo:(gboolean) blocking;
-- (gint) true;
-- (gint) false;
+- (gint) val_true;
+- (gint) val_false;
 - (void) grabAdd:(GTKWidget *) widget;
 - (GTKWidget*) grabGetCurrent;
 - (void) grabRemove:(GTKWidget *) widget;
