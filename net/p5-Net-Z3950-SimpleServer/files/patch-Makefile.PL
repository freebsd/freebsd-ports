--- Makefile.PL.orig	Mon Mar 11 00:22:20 2002
+++ Makefile.PL	Mon Mar 11 00:22:34 2002
@@ -9,5 +9,5 @@
     'VERSION_FROM' => 'SimpleServer.pm', # finds $VERSION
     'LIBS'	=> [$libs],   # e.g., '-lm' 
     'DEFINE'	=> '',     # e.g., '-DHAVE_SOMETHING' 
-    'INC'	=> '',     # e.g., '-I/usr/include/other' 
+    'INC'	=> '-I${LOCALBASE}/include',     # e.g., '-I/usr/include/other' 
 );
