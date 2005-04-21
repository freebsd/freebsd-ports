--- FreeType/Makefile.PL.orig	Wed Jan 10 14:50:46 2001
+++ FreeType/Makefile.PL	Wed Jan 10 14:51:19 2001
@@ -6,5 +6,5 @@
     'VERSION_FROM' => 'FreeType.pm', # finds $VERSION
     'LIBS'	=> ['-L/usr/local/lib -lttf'],   # e.g., '-lm' 
     'DEFINE'	=> '',     # e.g., '-DHAVE_SOMETHING' 
-    'INC'	=> '-I/usr/local/include',     # e.g., '-I/usr/include/other' 
+    'INC'	=> '-I/usr/local/include/freetype1/freetype',     # e.g., '-I/usr/include/other' 
 );

