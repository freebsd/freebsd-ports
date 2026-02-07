--- geo/drgeo_dialog.cc.orig	2003-10-27 13:17:25.000000000 +0300
+++ geo/drgeo_dialog.cc	2013-09-27 21:58:19.018800682 +0400
@@ -38,7 +38,7 @@
 // Used in the style dialod callback, I know it's ugly, but so easy
 static drgeoFigure *selected_figure;
 
-struct
+struct drgeoDialogDataStruct
 {
   drgeoPoint mouse;
   drgeoFigure *figure;
