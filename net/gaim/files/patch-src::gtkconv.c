--- src/gtkconv.c.orig	Thu Aug 14 07:40:41 2003
+++ src/gtkconv.c	Mon Aug 25 16:34:55 2003
@@ -1138,11 +1138,27 @@
 	GaimConversation *conv;
 	GaimGtkConversation *gtkconv;
 	GaimGtkWindow *gtkwin;
+	gboolean im_context_retval = FALSE;
+	static guint32 last_event_time;
 
 	conv    = (GaimConversation *)data;
 	gtkconv = GAIM_GTK_CONVERSATION(conv);
 	win     = gaim_conversation_get_window(conv);
 	gtkwin  = GAIM_GTK_WINDOW(win);
+
+	/*
+	 * Check if the input method handles this keyevent or we can use it.
+	 * We need to check the event time, otherwise the gtk xim module gets into an event loop (bug?)
+	 * Maybe this is not the best solution, but it works.
+	 */
+
+	if (last_event_time != event->time) {
+		im_context_retval = gtk_im_context_filter_keypress(GTK_TEXT_VIEW(gtkconv->entry)->im_context, event);
+	}
+	last_event_time = event->time;
+	if (im_context_retval == TRUE) {
+		return TRUE;
+	}
 
 	if (event->keyval == GDK_Page_Up) {
 		g_signal_stop_emission_by_name(G_OBJECT(entry), "key_press_event");
