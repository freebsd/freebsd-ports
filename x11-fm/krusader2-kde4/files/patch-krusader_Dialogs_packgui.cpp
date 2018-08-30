--- krusader/Dialogs/packgui.cpp.orig	2018-08-30 09:48:14 UTC
+++ krusader/Dialogs/packgui.cpp
@@ -40,7 +40,7 @@
 #include <QtGui/QComboBox>
 #include <khistorycombobox.h>
 
-#define PS(x) lst.contains(x)>0
+#define PS(x) bool(lst.contains(x))
 
 // clear the statics first
 QString PackGUI::filename = 0;
