--- src/flguppy.h.orig	Tue Oct 15 01:03:47 2002
+++ src/flguppy.h	Tue Oct 15 01:03:57 2002
@@ -31,6 +31,8 @@
 #include <FL/Fl_Button.H>
 #include <FL/Fl_Value_Output.H>
 
+using namespace std;
+
 class TableauUI {
 public:
   void *widg;
