--- src/connect.c.orig	Sat Jul 12 01:50:36 2003
+++ src/connect.c	Sat Jul 12 01:51:34 2003
@@ -1739,7 +1739,7 @@
       rdp_file_save (rdp, filename);
       g_free (rdp);
     }
-    g_free (filename);
+/*    g_free (filename);*/
   }
   gtk_widget_destroy (GTK_WIDGET (save_selector));
   return;
@@ -1784,7 +1784,7 @@
       }
       g_free (rdp);
     }
-    g_free (filename);
+/*    g_free (filename);*/
   }
   gtk_widget_destroy (GTK_WIDGET (open_selector));
   return;
