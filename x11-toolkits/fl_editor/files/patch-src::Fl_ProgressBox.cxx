--- src/Fl_ProgressBox.cxx.orig	Wed Jun 19 17:51:02 2002
+++ src/Fl_ProgressBox.cxx	Wed Mar 10 07:58:26 2004
@@ -47,7 +47,7 @@
 		fl_draw(buffer, (w() - fl_width(buffer))/2, fl_height() + (((h() - 2*bdy) - fl_height())/2));
 #else
 		fl_font(this->labelfont(), this->labelsize());
-		fl_draw(buffer, x() + (w() - fl_width(buffer))/2, y() + fl_height() + (((h() - 2*bdy) - fl_height())/2));
+		fl_draw(buffer, int(x() + (w() - fl_width(buffer))/2), int(y() + fl_height() + (((h() - 2*bdy) - fl_height())/2)));
 #endif
 	}
 }
