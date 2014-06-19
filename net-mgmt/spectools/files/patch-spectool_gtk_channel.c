--- spectool_gtk_channel.c.orig	2014-06-10 21:11:26.000000000 +0200
+++ spectool_gtk_channel.c	2014-06-10 21:30:00.000000000 +0200
@@ -39,12 +39,12 @@ static gboolean spectool_channel_mouse_m
 
 G_DEFINE_TYPE(SpectoolChannel, spectool_channel, SPECTOOL_TYPE_WIDGET);
 
-inline int spectool_channel_find_chan_pt(SpectoolChannel *cwidget, int x, int y) {
+static inline int spectool_channel_find_chan_pt(SpectoolChannel *cwidget, int x, int y) {
 	int dbm, maxy, nchannels;
 	SpectoolWidget *wwidget;
 
-	g_return_if_fail(cwidget != NULL);
-	g_return_if_fail(IS_SPECTOOL_WIDGET(cwidget));
+	g_return_val_if_fail(cwidget != NULL, 0);
+	g_return_val_if_fail(IS_SPECTOOL_WIDGET(cwidget), 0);
 	wwidget = SPECTOOL_WIDGET(cwidget);
 
 	/* Only compute if we know a chanset and if we're inside the bounding
@@ -224,17 +224,17 @@ static gint spectool_channel_button_pres
 	int ch;
 	GList *upd_iter;
 
-	g_return_if_fail(aux != NULL);
-	g_return_if_fail(IS_SPECTOOL_CHANNEL(aux));
-	g_return_if_fail(IS_SPECTOOL_WIDGET(aux));
+	g_return_val_if_fail(aux != NULL, 0);
+	g_return_val_if_fail(IS_SPECTOOL_CHANNEL(aux), 0);
+	g_return_val_if_fail(IS_SPECTOOL_WIDGET(aux), 0);
 
 	channel = SPECTOOL_CHANNEL(aux);
 	wwidget = SPECTOOL_WIDGET(aux);
 
-	g_return_if_fail(wwidget->chanopts != NULL);
-	g_return_if_fail(wwidget->chanopts->chanset != NULL);
-	g_return_if_fail(wwidget->sweepcache != NULL);
-	g_return_if_fail(wwidget->sweepcache->latest != NULL);
+	g_return_val_if_fail(wwidget->chanopts != NULL, 0);
+	g_return_val_if_fail(wwidget->chanopts->chanset != NULL, 0);
+	g_return_val_if_fail(wwidget->sweepcache != NULL, 0);
+	g_return_val_if_fail(wwidget->sweepcache->latest != NULL, 0);
 
 	if (event->button != 1)
 		return TRUE;
@@ -278,15 +278,15 @@ static gboolean spectool_channel_mouse_m
 	SpectoolWidget *wwidget;
 	GList *upd_iter;
 
-	g_return_if_fail(aux != NULL);
-	g_return_if_fail(IS_SPECTOOL_CHANNEL(aux));
-	g_return_if_fail(IS_SPECTOOL_WIDGET(aux));
+	g_return_val_if_fail(aux != NULL, FALSE);
+	g_return_val_if_fail(IS_SPECTOOL_CHANNEL(aux), FALSE);
+	g_return_val_if_fail(IS_SPECTOOL_WIDGET(aux), FALSE);
 
 	channel = SPECTOOL_CHANNEL(aux);
 	wwidget = SPECTOOL_WIDGET(aux);
 
-	g_return_if_fail(wwidget->sweepcache != NULL);
-	g_return_if_fail(wwidget->sweepcache->latest != NULL);
+	g_return_val_if_fail(wwidget->sweepcache != NULL, FALSE);
+	g_return_val_if_fail(wwidget->sweepcache->latest != NULL, FALSE);
 
 	if (event->is_hint) {
 		gdk_window_get_pointer(event->window, &x, &y, &state);
@@ -298,8 +298,8 @@ static gboolean spectool_channel_mouse_m
 
 	/* Search for the channel positions, update the graph if we've changed
 	 * the highlighted channel */
-	g_return_if_fail(wwidget->chanopts != NULL);
-	g_return_if_fail(wwidget->chanopts->chanset != NULL);
+	g_return_val_if_fail(wwidget->chanopts != NULL, FALSE);
+	g_return_val_if_fail(wwidget->chanopts->chanset != NULL, FALSE);
 
 	if ((ch = spectool_channel_find_chan_pt(channel, x, y)) >= -1) {
 		if (ch != wwidget->chanopts->hi_chan) {
