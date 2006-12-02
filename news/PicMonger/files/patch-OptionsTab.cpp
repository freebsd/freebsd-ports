--- OptionsTab.cpp.orig	Tue Apr 11 20:40:30 2000
+++ OptionsTab.cpp	Fri Dec  1 22:35:20 2006
@@ -8,6 +8,8 @@
 #include <iostream>
 
 using std::cerr;
+using std::string;
+using std::endl;
 
 OptionsTab::OptionsTab()
 	: Gtk::Table( 4, 1, true )
