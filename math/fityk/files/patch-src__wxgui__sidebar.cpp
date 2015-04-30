--- src/wxgui/sidebar.cpp.orig	2015-04-30 21:04:15 UTC
+++ src/wxgui/sidebar.cpp
@@ -897,7 +897,7 @@ void SideBar::update_func_inf()
     realt a;
     if (func->get_center(&a))
         inf->AppendText(wxT("Center: ")
-                   + s2wx(format1<realt, 30>("%.10"REALT_LENGTH_MOD"g", a)));
+                   + s2wx(format1<realt, 30>("%.10" REALT_LENGTH_MOD "g", a)));
     if (func->get_area(&a))
         inf->AppendText(wxT("\nArea: ") + s2wx(S(a)));
     if (func->get_height(&a))
