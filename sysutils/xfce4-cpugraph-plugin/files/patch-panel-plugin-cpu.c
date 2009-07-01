--- panel-plugin/cpu.c.orig	2005-10-09 05:06:46.000000000 -0400
+++ panel-plugin/cpu.c	2009-06-15 18:29:08.000000000 -0400
@@ -606,7 +606,7 @@
     op->m_Notebook = gtk_notebook_new ();
     gtk_container_set_border_width (GTK_CONTAINER (op->m_Notebook), 
                                     BORDER - 2);
-    label = gtk_label_new (_("Apperance"));
+    label = gtk_label_new (_("Appearance"));
     gtk_notebook_append_page (GTK_NOTEBOOK (op->m_Notebook),
                               GTK_WIDGET (vbox2), GTK_WIDGET (label));
     label = gtk_label_new (_("Advanced"));
@@ -952,7 +952,7 @@
 SetHistorySize (CPUGraph * base, int size)
 {
     base->m_History =
-        (long *) realloc (base->m_History, size * sizeof (long));
+        (int *) realloc (base->m_History, size * sizeof (int));
     int i;
 
     for (i = size - 1; i >= base->m_Values; i--)
