--- headers.c	Wed Oct 17 00:16:54 2001
+++ headers.c.new	Fri Oct 19 08:58:56 2001
@@ -688,7 +688,7 @@
 	      if ((print = action->print) == NULL)
 		print = print_string;
 	      cat_reset (&message->hdr_buffer, 0);
-	      (*print) (message, message->current_header);
+	      (*print) (message, info->hdr);
 	      header = cat_buffer (&message->hdr_buffer, len);
             }
         }
