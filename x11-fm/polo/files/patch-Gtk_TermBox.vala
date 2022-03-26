--- Gtk/TermBox.vala.orig	2018-08-12 04:41:58 UTC
+++ Gtk/TermBox.vala
@@ -255,7 +255,7 @@ public class TermBox : Gtk.Box {
 
 		#else 
  
-		term.feed_child(cmd, -1);  
+		term.feed_child((uint8[])cmd);
 		
 		#endif
 	}
