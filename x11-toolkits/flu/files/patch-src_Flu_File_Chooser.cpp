--- src/Flu_File_Chooser.cpp.orig	2010-01-15 11:52:23.000000000 +0100
+++ src/Flu_File_Chooser.cpp	2010-01-15 11:52:55.000000000 +0100
@@ -2773,7 +2773,7 @@
   const Fl_Menu_Item *selection = entryPopup.popup();
   if( selection )
     {
-      int handler = (int)selection->user_data();
+      long handler = (long)selection->user_data();
       switch( handler )
 	{
 	case ACTION_NEW_FOLDER:
