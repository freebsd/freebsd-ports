--- Makefile.PL.orig	Sun Dec 23 23:08:17 2001
+++ Makefile.PL	Sun Dec 23 23:09:10 2001
@@ -7,9 +7,9 @@
     'NAME'	=> 'Net::Z3950',
     'VERSION_FROM' => 'Z3950.pm', # finds $VERSION
 #   'LIBS'	=> ['-L/usr/local/src/yaz/lib/.libs -lyaz'],   # e.g., '-lm' 
-    'LIBS'	=> ['-lyaz'],   # e.g., '-lm' 
+    'LIBS'	=> ["-L$ENV{LOCALBASE}/lib -lyaz"],   # e.g., '-lm' 
     'DEFINE'	=> '',     # e.g., '-DHAVE_SOMETHING' 
-#   'INC'	=> '-I/usr/local/src/yaz/include',
+    'INC'	=> "-I$ENV{LOCALBASE}/include",
     'PREREQ_PM' => { Event => 0.77 },
     'MYEXTLIB'	=> 'yazwrap/libyazwrap$(LIB_EXT)',
 );
