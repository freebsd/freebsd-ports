--- src/mailmsg2.c.orig	Wed Mar 20 08:04:47 2002
+++ src/mailmsg2.c	Fri May 10 10:21:54 2002
@@ -259,6 +259,7 @@
 
     } else if (copy_msg && ! retransmit) {  /* if retransmit we have it! */
 	struct string * From_buffer = NULL;
+	struct string * Date_buffer = NULL;
 	struct addr_item *p;
 	    
 	if (current_header->from) {
@@ -277,7 +278,23 @@
 		}
 	    }
 	}
-	    
+
+	if (current_header->time_sent) {
+	    char date_buf[SLEN];
+
+	    Date_buffer = new_string(display_charset);
+	    add_ascii_to_string(Date_buffer,
+				s2us(elm_date_str(date_buf,
+						  current_header->time_sent +
+						  current_header->tz_offset,
+						  sizeof date_buf)));
+	    if (current_header->time_zone[0]) {
+		add_ascii_to_string(Date_buffer, s2us(" "));
+		add_ascii_to_string(Date_buffer,
+				    s2us(current_header->time_zone));
+	    }
+	}
+
 	if (!cur_editcharset)
 	    cur_editcharset = display_charset;
 
@@ -296,12 +313,14 @@
 				 current_header->env_from);
 		
 	    } else if (attribution[0] && current_header) {
+		char * date = us2s(stream_from_string(Date_buffer,1,NULL));
 		if (From_buffer) {
 		    char * str = us2s(stream_from_string(From_buffer,1,NULL));
-		    fprintf(reply, attribution, str);
+		    fprintf(reply, attribution, str, date);
 		    free(str);
 		} else
-		    fprintf(reply, attribution, current_header->env_from);
+		    fprintf(reply, attribution, current_header->env_from, date);
+		free(date);
 		fputc('\n', reply);
 	    }
 	    if (edit_message && current_folder) {
@@ -389,6 +408,8 @@
 	}
 	if (From_buffer)
 	    free_string(&From_buffer);
+	if (Date_buffer)
+	    free_string(&Date_buffer);
     }
     
     if (!cur_editcharset)
