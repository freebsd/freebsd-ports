
--- src/motifutils.c.orig	2010-03-15 20:05:12.742336241 -0700
+++ src/motifutils.c	2010-03-15 20:12:53.885346709 -0700
@@ -118,7 +118,6 @@
 
 extern unsigned long xvlibcolors[];
 
-
 static OptionItem *color_option_items = NULL;
 static int ncolor_option_items = 0;
 static OptionStructure **color_selectors = NULL;
@@ -1621,6 +1620,12 @@
     graph_popup_menu = xmalloc(sizeof(GraphPopupMenu));
 
     popup = XmCreatePopupMenu(listp->list, "graphPopupMenu", NULL, 0);
+#if XmVersion >= 2000
+    XtVaSetValues(popup, XmNpopupEnabled, XmPOPUP_DISABLED, NULL);
+    XtUngrabButton(listp->list, AnyButton, AnyModifier);
+#else
+    XtVaSetValues(popup, XmNpopupEnabled, False, NULL);
+#endif
     graph_popup_menu->popup = popup;
     
     graph_popup_menu->label_item = CreateMenuLabel(popup, "Selection:");
@@ -2243,6 +2248,12 @@
     
     set_popup_menu = xmalloc(sizeof(SetPopupMenu));
     popup = XmCreatePopupMenu(listp->list, "setPopupMenu", NULL, 0);
+#if XmVersion >= 2000
+    XtVaSetValues(popup, XmNpopupEnabled, XmPOPUP_DISABLED, NULL);
+    XtUngrabButton(listp->list, AnyButton, AnyModifier);
+#else
+    XtVaSetValues(popup, XmNpopupEnabled, False, NULL);
+#endif
     set_popup_menu->popup = popup;
     
     set_popup_menu->label_item = CreateMenuLabel(popup, "Selection:");


