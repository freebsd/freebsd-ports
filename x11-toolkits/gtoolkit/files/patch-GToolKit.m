--- GToolKit.m.orig	2002-02-21 16:43:52.000000000 +0100
+++ GToolKit.m	2011-04-15 20:17:16.000000000 +0200
@@ -2550,6 +2550,17 @@
 #include <GToolKit/GTKWidget.h>
 #include <GToolKit/GTKAccelGroup.h>
 
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
+
+#include <stdio.h>
+#include <string.h>
+#include <Foundation/NSAutoreleasePool.h>
+#if defined (DEBUG) && defined (HAVE_OBJC_OBJC_API_H)
+#include <objc/objc-api.h>
+#endif
+
 @implementation GTKItemFactory
 + (GtkType) getType
 {
@@ -2651,16 +2662,6 @@
 {
     gtk_item_factory_set_translate_func(gtk, func , data , notify);
 }
-#ifdef HAVE_CONFIG_H
-#include "config.h"
-#endif
-
-#include <stdio.h>
-#include <string.h>
-#include <Foundation/NSAutoreleasePool.h>
-#if defined (DEBUG) && defined (HAVE_OBJC_OBJC_API_H)
-#include <objc/objc-api.h>
-#endif
 
 
 static void item_forward_signal (gpointer data, guint action, GtkWidget *widget)
@@ -3134,11 +3135,11 @@
 {
     return gtk_main_iteration_do( blocking);
 }
-- (gint) true
+- (gint) val_true
 {
     return gtk_true();
 }
-- (gint) false
+- (gint) val_false
 {
     return gtk_false();
 }
@@ -6376,6 +6377,10 @@
 #include <GToolKit/GTKWidget.h>
 #include <GToolKit/GTKAccelGroup.h>
 
+#include <gtk/gtksignal.h>
+#include <Foundation/NSAutoreleasePool.h>
+#include <Foundation/NSNotification.h>
+
 @implementation GTKWindow
 + (GtkType) getType
 {
@@ -6437,9 +6442,6 @@
 {
     gtk_window_set_modal(gtk, modal);
 }
-#include <gtk/gtksignal.h>
-#include <Foundation/NSAutoreleasePool.h>
-#include <Foundation/NSNotification.h>
 
 
 NSString *GTKWindowDidBecomeMainNotification = @"GTKWindowDidBecomeMain";
