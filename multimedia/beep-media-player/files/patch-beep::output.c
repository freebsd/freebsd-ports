--- beep/output.c.orig	Fri Nov 14 05:21:23 2003
+++ beep/output.c	Fri Nov 14 05:21:52 2003
@@ -31,14 +31,15 @@
 {
 	gint time;
 	gint pos;
-
+	gboolean playing;
+	
 	GList *node = g_list_nth(op_data->output_list, i);
 	if (node)
 		op_data->current_output_plugin = node->data;
 	else
 		op_data->current_output_plugin = NULL;
 
-	gboolean playing = get_input_playing();
+	playing = get_input_playing();
 	if (playing) {
 
 		/* FIXME: we do all on our own here */
