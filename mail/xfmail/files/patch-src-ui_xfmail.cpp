--- src/ui/xfmail.cpp.orig	2011-09-06 15:08:01.000000000 +0200
+++ src/ui/xfmail.cpp	2011-09-06 15:28:40.000000000 +0200
@@ -42,6 +42,70 @@
 #include "addrbook_util.h"
 #include "tip.h"
 
+
+/*
+ * This belongs to xforms' implementation
+ */
+enum {
+    FLI_FIND_INPUT,
+    FLI_FIND_AUTOMATIC,
+    FLI_FIND_MOUSE,
+    FLI_FIND_CANVAS,
+    FLI_FIND_KEYSPECIAL,
+    FLI_FIND_RETURN
+};
+
+FL_OBJECT *
+fli_find_object( FL_OBJECT * obj,
+                 int         find,
+                 FL_Coord    mx,
+                 FL_Coord    my )
+{
+    while ( obj )
+    {
+        if (    obj->objclass != FL_BEGIN_GROUP
+             && obj->objclass != FL_END_GROUP
+             && obj->visible
+             && (     obj->active
+                  || ( obj->posthandle && ! obj->active )
+                  || ( obj->tooltip && *obj->tooltip && ! obj->active ) ) )
+        {
+            if ( find == FLI_FIND_INPUT && obj->input && obj->active )
+                return obj;
+
+            if ( find == FLI_FIND_AUTOMATIC && obj->automatic )
+                return obj;
+
+            if ( find == FLI_FIND_RETURN && obj->type == FL_RETURN_BUTTON )
+                return obj;
+
+            if (    find == FLI_FIND_MOUSE
+                 && mx >= obj->x
+                 && mx <= obj->x + obj->w
+                 && my >= obj->y
+                 && my <= obj->y + obj->h )
+                return obj;
+
+            if ( find == FLI_FIND_KEYSPECIAL && obj->wantkey & FL_KEY_SPECIAL )
+                return obj;
+        }
+
+        obj = obj->next;
+    }
+
+    return NULL;
+}
+
+
+FL_OBJECT *
+fli_find_first( FL_FORM  * form,
+                int        find,
+                FL_Coord   mx,
+                FL_Coord   my )
+{
+    return fli_find_object( form->first, find, mx, my );
+}
+
 static void usage(char *s, int die) {
 	char **q = helps;
 
@@ -486,7 +550,7 @@
 			break;
 
 		case FL_MOUSE:
-			obj = fl_find_first(main_form, FL_FIND_MOUSE, mx, my);
+			obj = fli_find_first(main_form, FLI_FIND_MOUSE, mx, my);
 
 			switch(dragndrop) {
 				case -1:
