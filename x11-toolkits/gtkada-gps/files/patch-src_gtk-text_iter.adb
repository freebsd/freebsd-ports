--- src/gtk-text_iter.adb.orig	Wed Oct 26 08:29:06 2005
+++ src/gtk-text_iter.adb	Tue Jan  2 00:55:36 2007
@@ -1195,11 +1195,12 @@
    -- Get_Text_Iter --
    -------------------
 
-   function Get_Text_Iter (Val : Glib.Values.GValue) return Gtk_Text_Iter is
-   begin
-      return Iter_Access_Address_Conversions.To_Pointer
-               (Glib.Values.Get_Address (Val)).all;
-   end Get_Text_Iter;
+--   function Get_Text_Iter (Val : Glib.Values.GValue) return Gtk_Text_Iter is
+--      Iter : Gtk_Text_Iter;
+--   begin
+--      Get_Text_Iter (Val => Val, Iter => Iter);
+--      return Iter;
+--   end Get_Text_Iter;
 
 begin
    if Gtk_Text_Iter'Size /= C_Gtk_Text_Iter_Size * 8 then
