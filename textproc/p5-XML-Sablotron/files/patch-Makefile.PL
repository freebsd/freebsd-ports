--- Makefile.PL.orig	Tue Jan 30 22:55:23 2001
+++ Makefile.PL	Fri Feb 23 10:50:59 2001
@@ -61,6 +61,7 @@
     $config{LIBS} .= ' -lexpat';
 }
 
+=item
 have_library('expat', 'main', '') || die <<DEATH;
 You do not appear to have libexpat in the library search path.
 Either install expat from http://expat.sourceforge.net/ or
@@ -76,7 +77,7 @@
   \$ $^X Makefile.PL LIBS='-L/path/to/sablot/lib -lexpat -lsablot'
 
 DEATH
-
+=cut
 
 WriteMakefile(
     NAME	=> 'XML::Sablotron',
