--- src/pitivi-timelinewindow.c.orig	Mon Dec 20 13:18:47 2004
+++ src/pitivi-timelinewindow.c	Mon Dec 20 13:21:52 2004
@@ -470,9 +470,10 @@
 {
   gboolean activate;
   GList	*childlist;
+  GList *childwidget;
   
   activate = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget));
-  GList *childwidget = gtk_container_get_children (GTK_CONTAINER (cells));
+  childwidget = gtk_container_get_children (GTK_CONTAINER (cells));
   for (childlist = childwidget; childlist; childlist = childlist->next )
     {
       if (activate)
@@ -546,7 +547,7 @@
   GtkWidget *nfo;
   GtkWidget *vbox_right, *vbox_left;
   int count = 0;
-
+  GtkWidget * pHScrollbarRight;
   
   self->private->hpaned = gtk_hpaned_new();
   vbox_left = gtk_vbox_new (FALSE, 0); 
@@ -597,7 +598,7 @@
   // Left Scrollbar
   gtk_paned_pack1 (GTK_PANED(self->private->hpaned), vbox_left, FALSE, FALSE);
   // Right HScrollbar
-  GtkWidget * pHScrollbarRight = gtk_scrolled_window_new (NULL, NULL);
+  pHScrollbarRight = gtk_scrolled_window_new (NULL, NULL);
   gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (pHScrollbarRight),
   			  GTK_POLICY_ALWAYS, GTK_POLICY_NEVER);
   gtk_scrolled_window_add_with_viewport (GTK_SCROLLED_WINDOW (pHScrollbarRight),
@@ -1339,15 +1340,17 @@
 pitivi_timelinewindow_activate (PitiviTimelineWindow *self)
 { 
   GList *childlist; 
-
+  PitiviProject *proj;
+  gdouble videorate;
+  GList *childwidget;
   /* Loading Select Cursor */
   
   load_cursor (GDK_WINDOW (GTK_WIDGET (self)->window), self->toolbox->pitivi_cursor, PITIVI_CURSOR_SELECT);
   
   /* Activating ruler */
   
-  PitiviProject	*proj = PITIVI_WINDOWS(self)->mainapp->project;
-  gdouble videorate = pitivi_projectsettings_get_videorate(proj->settings);
+  proj = PITIVI_WINDOWS(self)->mainapp->project;
+  videorate = pitivi_projectsettings_get_videorate(proj->settings);
   g_object_set (self->hruler, "ruler-videorate", videorate, NULL);
   
   /* Activate Windows Menu */
@@ -1357,7 +1360,7 @@
 
   /* Activate childs */
 
-  GList *childwidget = gtk_container_get_children (GTK_CONTAINER (self->private->layout_container));
+  childwidget = gtk_container_get_children (GTK_CONTAINER (self->private->layout_container));
   for (childlist = childwidget; childlist; childlist = childlist->next )
     {
       if (GTK_IS_LAYOUT (childlist->data))
