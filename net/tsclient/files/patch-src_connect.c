--- src/connect.c.orig	Thu Jul  3 22:43:25 2003
+++ src/connect.c	Fri Jul  4 21:06:08 2003
@@ -1793,9 +1793,9 @@
       rdp_file_get_screen (rdp, main_window);
       rdp_file_save (rdp, filename);
       g_free (rdp);
-    }
-    g_free (filename);
-  }
+    }
+/*    g_free (filename);*/
+  }
   gtk_widget_destroy (GTK_WIDGET (save_selector));
   return;
 }
@@ -1838,9 +1838,9 @@
         rdp_file_set_screen (rdp, main_window);
       }
       g_free (rdp);
-    }
-    g_free (filename);
-  }
+    }
+/*      g_free (filename);*/
+  }
   gtk_widget_destroy (GTK_WIDGET (open_selector));
   return;
 }
