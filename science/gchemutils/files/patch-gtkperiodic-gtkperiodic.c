--- gtkperiodic/gtkperiodic.c.orig	Sat Mar  1 20:49:14 2003
+++ gtkperiodic/gtkperiodic.c	Wed Mar 19 01:13:51 2003
@@ -157,6 +157,9 @@
 {
 	GladeXML* xml;
 	GtkStyle* style;
+	char name[8] = "elt";
+	GtkToggleButton* button;
+	int i;
 	xml =  glade_xml_new(DATADIR"/gchemutils/glade/gtkperiodic.glade", "vbox1", NULL);
 	if (xml)  glade_xml_signal_autoconnect (xml);
 	periodic->priv = g_new0(GtkPeriodicPrivate, 1);
@@ -164,9 +167,6 @@
 	periodic->priv->vbox = GTK_VBOX(glade_xml_get_widget(xml, "vbox1"));
 	periodic->priv->colorstyle = GTK_PERIODIC_COLOR_NONE;
 	memset(periodic->priv->buttons, 0, sizeof(GtkToggleButton*) * 119);
-	char name[8] = "elt";
-	GtkToggleButton* button;
-	int i;
 	for (i = 1; i <= 118; i++)
 	{
 		sprintf(name + 3, "%d", i);
@@ -217,10 +217,11 @@
 	static gboolean change = FALSE;
 	if (button != periodic->priv->buttons[0])
 	{
+		const gchar* name;
 		change = TRUE;
 		if (periodic->priv->buttons[0]) gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(periodic->priv->buttons[0]), FALSE);
 		periodic->priv->buttons[0] = button;
-		const gchar* name = gtk_widget_get_name(GTK_WIDGET(periodic->priv->buttons[0]));
+		name = gtk_widget_get_name(GTK_WIDGET(periodic->priv->buttons[0]));
 		periodic->priv->Z = atoi(name + 3);
 		g_signal_emit(periodic, gtk_periodic_signals[ELEMENT_CHANGED], 0, periodic->priv->Z);
 		change = FALSE;
