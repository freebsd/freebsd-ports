--- src/connect.c.orig	Thu Jul  3 16:43:25 2003
+++ src/connect.c	Fri Jul  4 19:08:41 2003
@@ -1793,8 +1793,9 @@
       rdp_file_get_screen (rdp, main_window);
       rdp_file_save (rdp, filename);
       g_free (rdp);
+      g_free (filename);
     }
-    g_free (filename);
+    /*g_free (filename);*/
   }
   gtk_widget_destroy (GTK_WIDGET (save_selector));
   return;
@@ -1838,8 +1839,9 @@
         rdp_file_set_screen (rdp, main_window);
       }
       g_free (rdp);
+      g_free (filename);
     }
-    g_free (filename);
+    /*g_free (filename);*/
   }
   gtk_widget_destroy (GTK_WIDGET (open_selector));
   return;
