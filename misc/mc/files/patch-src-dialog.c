--- src/dialog.c.orig	2010-10-20 20:19:09.000000000 +0700
+++ src/dialog.c	2010-10-20 20:23:32.000000000 +0700
@@ -110,6 +110,9 @@
 {
     int space;
 
+    if (h->state != DLG_ACTIVE)
+        return;
+
     space = (h->flags & DLG_COMPACT) ? 0 : 1;
 
     tty_setcolor (DLG_NORMALC (h));
@@ -317,7 +320,7 @@
 void
 dlg_erase (Dlg_head * h)
 {
-    if (h != NULL)
+    if (h != NULL && h->state == DLG_ACTIVE)
         tty_fill_region (h->y, h->x, h->lines, h->cols, ' ');
 }
 
@@ -458,7 +461,7 @@
 {
     /* cannot focus disabled widget ... */
 
-    if (h->current != NULL)
+    if (h->current != NULL && h->state == DLG_ACTIVE)
     {
         Widget *current = (Widget *) h->current->data;
 
@@ -478,7 +481,7 @@
 {
     /* ... but can unfocus disabled widget */
 
-    if (h->current != NULL)
+    if (h->current != NULL && h->state == DLG_ACTIVE)
     {
         Widget *current = (Widget *) h->current->data;
 
@@ -649,7 +652,7 @@
 {
     GList *p = h->current;
 
-    if (p != NULL)
+    if (p != NULL && h->state == DLG_ACTIVE)
     {
         Widget *w;
 
@@ -683,6 +686,9 @@
 void
 dlg_redraw (Dlg_head * h)
 {
+    if (h->state != DLG_ACTIVE)
+        return;
+
     if (h->winch_pending)
     {
         h->winch_pending = FALSE;
