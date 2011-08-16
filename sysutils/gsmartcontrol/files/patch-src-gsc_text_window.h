--- src/gsc_text_window.h.orig	2011-08-15 16:20:00.000000000 +0200
+++ src/gsc_text_window.h	2011-08-15 16:21:05.000000000 +0200
@@ -126,7 +126,7 @@
 		// by default, delete_event calls hide().
 		bool on_delete_event_before(GdkEventAny* e)
 		{
-			destroy(this);  // deletes this object and nullifies instance
+			this->destroy(this);  // deletes this object and nullifies instance
 			return true;  // event handled, don't call default virtual handler
 		}
 
@@ -184,7 +184,7 @@
 
 		void on_close_window_button_clicked()
 		{
-			destroy(this);
+			this->destroy(this);
 		}
 
 
