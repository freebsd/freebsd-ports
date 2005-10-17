--- FreeType/Makefile.PL.orig	Mon Dec 14 02:13:26 1998
+++ FreeType/Makefile.PL	Mon Oct 17 11:47:15 2005
@@ -4,7 +4,8 @@
 WriteMakefile(
     'NAME'	=> 'FreeType',
     'VERSION_FROM' => 'FreeType.pm', # finds $VERSION
-    'LIBS'	=> ['-L/usr/local/X11R6.3/lib -lttf'],   # e.g., '-lm' 
+    'LIBS'	=> ['-L%%LOCALBASE%%/lib -lttf'],   # e.g., '-lm' 
+    'PREFIX'	=> '%%PREFIX%%',
     'DEFINE'	=> '',     # e.g., '-DHAVE_SOMETHING' 
-    'INC'	=> '-I/usr/local/X11R6.3/include',     # e.g., '-I/usr/include/other' 
+    'INC'	=> '-I%%LOCALBASE%%/include/freetype1/freetype',     # e.g., '-I/usr/include/other' 
 );
