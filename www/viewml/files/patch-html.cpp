
$FreeBSD$

--- html.cpp	2001/04/13 15:30:05	1.1
+++ html.cpp	2001/04/13 15:31:44
@@ -246,8 +246,8 @@
 
     setBackgroundColor( lightGray );
 
-    QString f = kapp->kde_datadir().copy();
-    f += "/khtmlw/pics/khtmlw_dnd.xpm";
+    QString f = PREFIX;
+    f += "/share/viewml/khtmlw_dnd.xpm";
     dndDefaultPixmap.load( f.data() );
     
     registerFormats();
