--- gtkextra/gtkitementry.c.orig	2009-09-26 16:38:37.000000000 +0200
+++ gtkextra/gtkitementry.c	2009-09-26 16:40:16.000000000 +0200
@@ -693,23 +693,23 @@ gtk_entry_real_insert_text (GtkEditable 
       new_text_length = g_utf8_offset_to_pointer (new_text, n_chars) - new_text;
     }
 
-  if (new_text_length + entry->n_bytes + 1 > entry->text_size)
+  if (new_text_length + entry->x_n_bytes + 1 > entry->x_text_size)
     {
-      while (new_text_length + entry->n_bytes + 1 > entry->text_size)
+      while (new_text_length + entry->x_n_bytes + 1 > entry->x_text_size)
 	{
-	  if (entry->text_size == 0)
-	    entry->text_size = MIN_SIZE;
+	  if (entry->x_text_size == 0)
+	    entry->x_text_size = MIN_SIZE;
 	  else
 	    {
-	      if (2 * (guint)entry->text_size < MAX_SIZE &&
-		  2 * (guint)entry->text_size > entry->text_size)
-		entry->text_size *= 2;
+	      if (2 * (guint)entry->x_text_size < MAX_SIZE &&
+		  2 * (guint)entry->x_text_size > entry->x_text_size)
+		entry->x_text_size *= 2;
 	      else
 		{
-		  entry->text_size = MAX_SIZE;
-		  if (new_text_length > (gint)entry->text_size - (gint)entry->n_bytes - 1)
+		  entry->x_text_size = MAX_SIZE;
+		  if (new_text_length > (gint)entry->x_text_size - (gint)entry->x_n_bytes - 1)
 		    {
-		      new_text_length = (gint)entry->text_size - (gint)entry->n_bytes - 1;
+		      new_text_length = (gint)entry->x_text_size - (gint)entry->x_n_bytes - 1;
 		      new_text_length = g_utf8_find_prev_char (new_text, new_text + new_text_length + 1) - new_text;
 		      n_chars = g_utf8_strlen (new_text, new_text_length);
 		    }
@@ -718,19 +718,19 @@ gtk_entry_real_insert_text (GtkEditable 
 	    }
 	}
 
-      entry->text = g_realloc (entry->text, entry->text_size);
+      entry->text = g_realloc (entry->text, entry->x_text_size);
     }
 
   index = g_utf8_offset_to_pointer (entry->text, *position) - entry->text;
 
-  g_memmove (entry->text + index + new_text_length, entry->text + index, entry->n_bytes - index);
+  g_memmove (entry->text + index + new_text_length, entry->text + index, entry->x_n_bytes - index);
   memcpy (entry->text + index, new_text, new_text_length);
 
-  entry->n_bytes += new_text_length;
+  entry->x_n_bytes += new_text_length;
   entry->text_length += n_chars;
 
   /* NUL terminate for safety and convenience */
-  entry->text[entry->n_bytes] = '\0';
+  entry->text[entry->x_n_bytes] = '\0';
   
   if (entry->current_pos > *position)
     entry->current_pos += n_chars;
@@ -763,9 +763,9 @@ gtk_entry_real_delete_text (GtkEditable 
       gint start_index = g_utf8_offset_to_pointer (entry->text, start_pos) - entry->text;
       gint end_index = g_utf8_offset_to_pointer (entry->text, end_pos) - entry->text;
 
-      g_memmove (entry->text + start_index, entry->text + end_index, entry->n_bytes + 1 - end_index);
+      g_memmove (entry->text + start_index, entry->text + end_index, entry->x_n_bytes + 1 - end_index);
       entry->text_length -= (end_pos - start_pos);
-      entry->n_bytes -= (end_index - start_index);
+      entry->x_n_bytes -= (end_index - start_index);
       
       if (entry->current_pos > start_pos)
 	entry->current_pos -= MIN (entry->current_pos, end_pos) - start_pos;
@@ -1028,7 +1028,7 @@ gtk_entry_retrieve_surrounding_cb (GtkIM
 {
   gtk_im_context_set_surrounding (context,
                                   entry->text,
-                                  entry->n_bytes,
+                                  entry->x_n_bytes,
                                   g_utf8_offset_to_pointer (entry->text, entry->current_pos) - entry->text);
 
   return TRUE;
@@ -1229,7 +1229,7 @@ gtk_entry_create_layout (GtkEntry *entry
       
       if (entry->visible)
         {
-          g_string_prepend_len (tmp_string, entry->text, entry->n_bytes);
+          g_string_prepend_len (tmp_string, entry->text, entry->x_n_bytes);
           g_string_insert (tmp_string, cursor_index, preedit_string);
         }
       else
@@ -1238,7 +1238,7 @@ gtk_entry_create_layout (GtkEntry *entry
           gint preedit_len_chars;
           gunichar invisible_char;
           
-          ch_len = g_utf8_strlen (entry->text, entry->n_bytes);
+          ch_len = g_utf8_strlen (entry->text, entry->x_n_bytes);
           preedit_len_chars = g_utf8_strlen (preedit_string, -1);
           ch_len += preedit_len_chars;
 
@@ -1272,7 +1272,7 @@ gtk_entry_create_layout (GtkEntry *entry
     {
       if (entry->visible)
         {
-          pango_layout_set_text (layout, entry->text, entry->n_bytes);
+          pango_layout_set_text (layout, entry->text, entry->x_n_bytes);
         }
       else
         {
