--- Makefile.PL.orig	Thu May 25 13:35:31 2006
+++ Makefile.PL	Thu May 25 13:35:57 2006
@@ -26,6 +26,6 @@
     'OBJECT'	=> '$(O_FILES)',
     'DEFINE'	=> '-DHAVE_CONFIG_H',
     'C'		=> [ 'Unaccent.c', 'unac.c' ],
-    'LIBS'	=> [ '-liconv' ], 
-    'INC'	=> '-I.',
+    'LIBS'	=> [ '-L/usr/local/lib -liconv' ], 
+    'INC'	=> '-I. -I/usr/local/include',
 );
