--- src/gtkada-canvas_view.ads.orig	2014-05-23 15:49:01 UTC
+++ src/gtkada-canvas_view.ads
@@ -372,7 +372,7 @@ package Gtkada.Canvas_View is
 
    function Is_Link
      (Self : not null access Abstract_Item_Record)
-      return Boolean is (False);
+      return Boolean is abstract;
    --  Whether this item should be considered as a link between two other
    --  items.
    --  Such links have a few specific behavior: for instance, they cannot be
@@ -448,7 +448,7 @@ package Gtkada.Canvas_View is
    function Edit_Widget
      (Self  : not null access Abstract_Item_Record;
       View  : not null access Canvas_View_Record'Class)
-      return Gtk.Widget.Gtk_Widget is (null);
+      return Gtk.Widget.Gtk_Widget is abstract;
    --  Return the widget to use for in-place editing of the item.
    --  null should be returned when the item is not editable in place.
    --  It is the responsibility of the returned widget to monitor events and
@@ -463,7 +463,7 @@ package Gtkada.Canvas_View is
 
    function Parent
      (Self : not null access Abstract_Item_Record)
-      return Abstract_Item is (null);
+      return Abstract_Item is abstract;
    --  Return the item inside which Self is contained.
    --  null is returned for toplevel items, in which case the coordinates of
    --  the bounding box are model coordinats. Otherwise, the coordinates are
@@ -478,7 +478,7 @@ package Gtkada.Canvas_View is
      (Self     : not null access Abstract_Item_Record;
       At_Point : Model_Point;
       Context  : Draw_Context)
-      return Abstract_Item is (Self);
+      return Abstract_Item is abstract;
    --  Return the inner-most item at the specific coordinates in Self (or
    --  Self itself).
 
@@ -509,7 +509,7 @@ package Gtkada.Canvas_View is
 
    function Is_Invisible
      (Self : not null access Abstract_Item_Record)
-     return Boolean is (False);
+     return Boolean is abstract;
    --  True if Self has no filling or stroke information (and therefore is
    --  invisible even when displayed, although some of its children might be
    --  visible).
@@ -526,6 +526,19 @@ package Gtkada.Canvas_View is
    --  It is easier to derive from this type when you want to create your own
    --  items, unless you want complete control of the data storage.
 
+   overriding function Is_Link
+     (Self : not null access Canvas_Item_Record) return Boolean is (False);
+   overriding function Parent
+     (Self : not null access Canvas_Item_Record)
+      return Abstract_Item is (null);
+   overriding function Is_Invisible
+     (Self : not null access Canvas_Item_Record)
+     return Boolean is (False);
+   function Inner_Most_Item
+     (Self     : not null access Canvas_Item_Record;
+      At_Point : Model_Point;
+      Context  : Draw_Context)
+      return Abstract_Item is (Self);
    overriding function Position
      (Self : not null access Canvas_Item_Record) return Gtkada.Style.Point;
    overriding function Contains
@@ -1583,6 +1596,21 @@ package Gtkada.Canvas_View is
    --  Return the computed points for the link.
    --  Do not free or store the result
 
+   overriding function Is_Invisible
+     (Self : not null access Canvas_Link_Record)
+     return Boolean is (False);
+   overriding function Inner_Most_Item
+     (Self     : not null access Canvas_Link_Record;
+      At_Point : Model_Point;
+      Context  : Draw_Context)
+      return Abstract_Item is (null);
+   overriding function Parent
+     (Self : not null access Canvas_Link_Record)
+      return Abstract_Item is (null);
+   overriding function Edit_Widget
+     (Self  : not null access Canvas_Link_Record;
+      View  : not null access Canvas_View_Record'Class)
+      return Gtk.Widget.Gtk_Widget is (null);
    overriding procedure Destroy
      (Self     : not null access Canvas_Link_Record;
       In_Model : not null access Canvas_Model_Record'Class);
