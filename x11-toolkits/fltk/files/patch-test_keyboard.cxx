--- test/keyboard.cxx.orig	Sat Sep 22 10:00:16 2007
+++ test/keyboard.cxx	Sat Sep 22 12:05:41 2007
@@ -105,11 +105,11 @@
     for (int i = 0; i < window->children(); i++) {
       Fl_Widget* b = window->child(i);
       if (b->callback() == (Fl_Callback*)key_cb) {
-	int i = int(b->user_data());
+	long i = long(b->user_data());
 	if (!i) i = b->label()[0];
 	((Fl_Button*)b)->value(Fl::event_key(i));
       } else if (b->callback() == (Fl_Callback*)shift_cb) {
-	int i = int(b->user_data());
+	long i = long(b->user_data());
 	((Fl_Button*)b)->value(Fl::event_state(i));
       }
     }
