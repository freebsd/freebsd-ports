
$FreeBSD$

--- anteater/asciireport.cpp.orig	Thu May 24 19:35:02 2001
+++ anteater/asciireport.cpp	Tue Nov  5 13:20:12 2002
@@ -297,7 +297,7 @@
 	if( !nextField() ) printSpace();	
 }
 
-void asciiReport::skipField( const bool realline = true )
+void asciiReport::skipField( const bool realline)
 {
   if( col_list.size() == 0 ) return; // Fehler.
   if( realline ) checkAutoField();
@@ -366,14 +366,14 @@
 }
 
 /** Gibt width anzahl spaces aus. */
-void asciiReport::printSpace( const int width = 1 )
+void asciiReport::printSpace( const int width)
 {
   int i;
   for( i = 0; i < width; i++ ) (*os).put( ' ' );
 }
 
 /** Zeichnet eine Linie über die gesammte Breite mit zeichen ch. */
-void asciiReport::printLine( const char ch = '-', const int size = -1 )
+void asciiReport::printLine( const char ch, const int size)
 {
   int i;
   for( i = 0; i < ( size == -1 ? ScreenWidth : size ) ; i++ ) (*os).put( ch );
