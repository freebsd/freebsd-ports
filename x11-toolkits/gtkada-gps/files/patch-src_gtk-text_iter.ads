--- src/gtk-text_iter.ads.orig	Mon Jan  1 23:39:23 2007
+++ src/gtk-text_iter.ads	Mon Jan  1 23:40:12 2007
@@ -655,7 +655,7 @@
    --  by the give GValue. Modifying the iterator returned does not modify
    --  the iterator referenced by the GValue.
 
-   function Get_Text_Iter (Val : Glib.Values.GValue) return Gtk_Text_Iter;
+--   function Get_Text_Iter (Val : Glib.Values.GValue) return Gtk_Text_Iter;
    --  This is the function equivalent of procedure Get_Text_Iter above. It is
    --  sometimes more convenient that then procedure, but its use is limited by
    --  the fact that the result returned can not be stored in a variable, since
