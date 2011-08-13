--- Makefile.PL.bak	2004-09-10 09:43:29.000000000 +0900
+++ Makefile.PL	2011-08-13 21:01:55.896033332 +0900
@@ -5,8 +5,8 @@
     NAME            => 'Font::FreeType',
     AUTHOR          => 'Geoff Richards <qef@laxan.com>',
     VERSION_FROM    => 'lib/Font/FreeType.pm',
-    LIBS            => [ '-lfreetype' ],
-    INC             => '-I/usr/include/freetype2',
+    LIBS            => `pkg-config --libs freetype2`,
+    INC             => `pkg-config --cflags freetype2`,
     NO_META         => 1,
 );
 
