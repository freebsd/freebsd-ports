$FreeBSD$

"correct name of the freetype library, so that it is easier to get AA fonts
working."

author:  Maxim Sobolev

--- modules/libpref/src/unix/unix.js	2002/03/14 15:04:20	1.1
+++ modules/libpref/src/unix/unix.js	2002/03/14 15:04:38
@@ -227,7 +227,7 @@
 
 // TrueType
 pref("font.FreeType2.enable", false);
-pref("font.freetype2.shared-library", "libfreetype.so.6");
+pref("font.freetype2.shared-library", "libfreetype.so.9");
 // if libfreetype was built without hinting compiled in
 // it is best to leave hinting off
 pref("font.FreeType2.autohinted", false);
