--- src/Thumbview.cc.orig	2010-07-31 08:36:07.000000000 +0200
+++ src/Thumbview.cc	2010-07-31 08:36:33.000000000 +0200
@@ -745,6 +745,8 @@
 	}
 }
 
+#endif
+
 void Thumbview::set_current_display_mode(DisplayMode newmode)
 {
     remove();
@@ -776,4 +778,3 @@
     signal_selected(path);
 }
 
-#endif
