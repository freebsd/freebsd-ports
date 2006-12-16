Index: src/gkrellm_private_proto.h
diff -u src/gkrellm_private_proto.h.orig src/gkrellm_private_proto.h
--- src/gkrellm_private_proto.h.orig	Thu May 23 06:53:12 2002
+++ src/gkrellm_private_proto.h	Sun Dec 17 00:14:56 2006
@@ -30,8 +30,6 @@
 extern gint			window_decorations;
 extern gint			n_system_plugins;
 
-extern GdkImlibBorder zero_border;
-
 void load_plugin_monitors(void);
 
 void	create_plugin_config(GtkWidget *);
