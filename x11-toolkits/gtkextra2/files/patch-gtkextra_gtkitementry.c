--- gtkextra/gtkitementry.c.orig	2010-03-13 05:49:00 UTC
+++ gtkextra/gtkitementry.c
@@ -131,7 +131,6 @@ static void         gtk_entry_draw_curso
 static PangoLayout *gtk_entry_ensure_layout            (GtkEntry       *entry,
                                                         gboolean        include_preedit);
 static void         gtk_entry_queue_draw               (GtkEntry       *entry);
-static void         gtk_entry_reset_im_context         (GtkEntry       *entry);
 static void         gtk_entry_recompute                (GtkEntry       *entry);
 static void         gtk_entry_get_cursor_locations     (GtkEntry       *entry,
 							CursorType      type,
@@ -1755,16 +1754,6 @@ gtk_entry_queue_draw (GtkEntry *entry)
 }
 
 static void
-gtk_entry_reset_im_context (GtkEntry *entry)
-{
-  if (entry->need_im_reset)
-    {
-      entry->need_im_reset = 0;
-      gtk_im_context_reset (entry->im_context);
-    }
-}
-
-static void
 gtk_entry_get_cursor_locations (GtkEntry   *entry,
 				CursorType  type,
 				gint       *strong_x,
