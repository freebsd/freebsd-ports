--- Makefile.PL.orig	Wed Oct 31 02:03:02 2001
+++ Makefile.PL	Tue Nov 20 22:26:34 2001
@@ -4,11 +4,11 @@
 
 my %config;
 
-$config{INC} = '';
-$config{LIBS} = '-lpng';
+$config{INC} = $ENV{INC};
+$config{LIBS} = $ENV{LIBS}.' -lpng';
 
-chomp($config{INC} .= ' ' . `gtk-config --cflags`);
-chomp($config{LIBS} .= ' ' .`gtk-config --libs`);
+chomp($config{INC} .= ' ' . `gtk12-config --cflags`);
+chomp($config{LIBS} .= ' ' .`gtk12-config --libs`);
 
 chomp($config{INC} .= ' ' . `gdk-pixbuf-config --cflags`);
 chomp($config{LIBS} .= ' ' . `gdk-pixbuf-config --libs`);
