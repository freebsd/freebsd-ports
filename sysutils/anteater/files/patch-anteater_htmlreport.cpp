
$FreeBSD$

--- anteater/htmlreport.cpp.orig	Thu May 24 19:14:00 2001
+++ anteater/htmlreport.cpp	Tue Nov  5 13:20:12 2002
@@ -244,7 +244,7 @@
 	nextField();	
 }
 
-void htmlReport::skipField( const bool realline = true )
+void htmlReport::skipField( const bool realline)
 {
   if( col_list.size() == 0 ) return; // Fehler.
   if( realline ) checkAutoField();
