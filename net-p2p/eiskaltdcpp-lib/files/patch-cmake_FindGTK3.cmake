--- cmake/FindGTK3.cmake.orig	2015-04-19 21:57:16 UTC
+++ cmake/FindGTK3.cmake
@@ -128,6 +128,7 @@ function(_GTK3_FIND_INCLUDE_DIR _var _hdr)
         gtkmm-2.4
         libglade-2.0
         libglademm-2.4
+        harfbuzz
         pango-1.0
         pangomm-1.4
         sigc++-2.2
@@ -421,6 +422,9 @@ foreach(_GTK3_component ${GTK3_FIND_COMPONENTS})
         _GTK3_FIND_LIBRARY    (GTK3_CAIRO_LIBRARY cairo false false)
 
         _GTK3_FIND_INCLUDE_DIR(GTK3_FONTCONFIG_INCLUDE_DIR fontconfig/fontconfig.h)
+
+        _GTK3_FIND_INCLUDE_DIR(GTK3_HARFBUZZ_INCLUDE_DIR hb.h)
+        _GTK3_FIND_LIBRARY    (GTK3_HARFBUZZ_LIBRARY harfbuzz false false)
 
         _GTK3_FIND_INCLUDE_DIR(GTK3_PANGO_INCLUDE_DIR pango/pango.h)
         _GTK3_FIND_LIBRARY    (GTK3_PANGO_LIBRARY pango false true)
