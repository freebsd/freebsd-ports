--- dc_qt.cc.orig	Sun Jul 28 02:42:28 2002
+++ dc_qt.cc	Sun Jul 28 02:45:12 2002
@@ -296,6 +296,8 @@
 	if (ok)
 		cur_hub->send_command(text);
 }
+#else
+void dc_main_window::send_command() {}
 #endif
 
 void dc_main_window::clear_user_list()
