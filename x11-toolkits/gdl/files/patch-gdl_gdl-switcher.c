--- gdl/gdl-switcher.c.orig	Tue Jul 10 00:35:38 2007
+++ gdl/gdl-switcher.c	Tue Jul 10 00:34:14 2007
@@ -285,6 +285,7 @@ layout_buttons (GdlSwitcher *switcher)
     }
 
     rows_count = num_btns / btns_per_row;
+    rows_count += (num_btns % btns_per_row == 0) ? 0 : 1;
     
     /* Assign buttons to rows */
     rows = g_new0 (GSList *, rows_count);
