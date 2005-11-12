--- src/mkisofs.c.orig	Sat May 28 02:37:14 2005
+++ src/mkisofs.c	Sat Nov 12 18:19:14 2005
@@ -64,6 +64,7 @@
   const gchar *Ldataabst = gtk_entry_get_text(GTK_ENTRY(sc_grave_get_widgetv(Ag, "%sabst", Aop)));
   gchar *Lreturn, *Linputcharset = NULL;
   gchar *Lextra = NULL;
+  gchar *Ldevchar = NULL;
   GtkTextIter Lstart, Lend;
   GtkTextBuffer *Lbufappi = gtk_text_view_get_buffer (GTK_TEXT_VIEW (sc_grave_get_widgetv(Ag, "%sappi", Aop)));
   char *Ldataappi, *Ltmpappi;
@@ -71,7 +72,6 @@
   Ltmpappi = gtk_text_iter_get_text (&Lstart, &Lend);
   Ldataappi = g_strescape(Ltmpappi, "");
   g_free(Ltmpappi);
-  gchar *Ldevchar = NULL;
 
   if (!strcmp(Aop, "data")) { /* data cd */
     gboolean Lrockridge = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(sc_grave_get_widget(Ag, "datarockridge")));
