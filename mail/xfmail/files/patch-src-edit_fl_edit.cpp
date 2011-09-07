--- src/editor/fl_edit.cpp.orig	2011-09-06 15:28:04.000000000 +0200
+++ src/editor/fl_edit.cpp	2011-09-06 15:29:22.000000000 +0200
@@ -63,6 +63,30 @@
 #include "textbuf.h"
 #include "fl_error.h"
 
+
+/*
+ * This belongs to xforms' implementation
+ */
+
+#define IS_FLATBOX( bt )     (    ( bt ) == FL_FRAME_BOX         \
+                               || ( bt ) == FL_EMBOSSED_BOX      \
+                               || ( bt ) == FL_BORDER_BOX        \
+                               || ( bt ) == FL_ROUNDED_BOX )
+
+int
+fli_get_default_scrollbarsize( FL_OBJECT * ob )
+{
+    int delta = ( FL_abs( ob->bw ) + 3 * ( ob->bw > 0 ) );
+    int flat = IS_FLATBOX( ob->boxtype ) ? 2 : 0;
+
+    if ( ob->w > 250 && ob->h > 250 )
+        return 15 + delta - flat;
+    else if ( ob->w < 150 || ob->h < 150 )
+        return 13 + delta - flat;
+    else
+        return 14 + delta - flat;
+}
+
 /***********************************************************************
  *
  * Some definitions
@@ -107,7 +131,6 @@
 #define TEXT_X_OFFSET       2
 #define TEXT_Y_OFFSET       0
 
-extern "C" int fl_get_default_scrollbarsize(FL_OBJECT *);
 extern "C" void fl_add_child(FL_OBJECT *, FL_OBJECT *);
 
 #define FL_ALL_MASK     (FL_ALT_MASK|FL_CONTROL_MASK|FL_SHIFT_MASK)
@@ -3200,7 +3223,7 @@
 
     /* scrollbar section */
     spec->v_on = spec->h_on = 0;
-    spec->vw = spec->hh = fl_get_default_scrollbarsize(ob);
+    spec->vw = spec->hh = fli_get_default_scrollbarsize(ob);
     spec->sb =
     fl_create_scrollbar(FL_VERT_THIN_SCROLLBAR, x + w - spec->vw, y,
                         spec->vw, h, "");
