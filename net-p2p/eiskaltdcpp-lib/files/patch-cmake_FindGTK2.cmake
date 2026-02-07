--- cmake/FindGTK2.cmake.orig	2015-04-19 21:57:16 UTC
+++ cmake/FindGTK2.cmake
@@ -167,6 +167,7 @@ function(_GTK2_FIND_INCLUDE_DIR _var _hdr)
         gtkmm-2.4
         libglade-2.0
         libglademm-2.4
+        harfbuzz
         pango-1.0
         pangomm-1.4
         sigc++-2.0
@@ -455,6 +456,9 @@ foreach(_GTK2_component ${GTK2_FIND_COMPONENTS})
         _GTK2_FIND_LIBRARY    (GTK2_CAIRO_LIBRARY cairo false false)
 
         _GTK2_FIND_INCLUDE_DIR(GTK2_FONTCONFIG_INCLUDE_DIR fontconfig/fontconfig.h)
+
+        _GTK2_FIND_INCLUDE_DIR(GTK2_HARFBUZZ_INCLUDE_DIR hb.h)
+        _GTK2_FIND_LIBRARY    (GTK2_HARFBUZZ_LIBRARY harfbuzz false false)
 
         _GTK2_FIND_INCLUDE_DIR(GTK2_PANGO_INCLUDE_DIR pango/pango.h)
         _GTK2_FIND_LIBRARY    (GTK2_PANGO_LIBRARY pango false true)
