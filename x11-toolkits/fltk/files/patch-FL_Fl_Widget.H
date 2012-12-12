--- FL/Fl_Widget.H.orig	2012-12-12 15:44:54.000000000 +0100
+++ FL/Fl_Widget.H	2012-12-12 15:52:48.000000000 +0100
@@ -99,6 +99,7 @@
  */
 class FL_EXPORT Fl_Widget {
   friend class Fl_Group;
+  friend class Fl_X;
 
   Fl_Group* parent_;
   Fl_Callback* callback_;
