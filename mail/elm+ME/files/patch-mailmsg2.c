--- src/mailmsg2.c.orig	Wed Aug  4 19:07:35 2004
+++ src/mailmsg2.c	Wed Aug 25 01:44:23 2004
@@ -486,6 +486,7 @@
 	} else if (
 		   (forwarding || mime_attach || copy_msg)) { 
 	    struct string * From_buffer = NULL;
+	    struct string * Date_buffer = NULL;
 	    struct addr_item *p;
 	    
 	    if (hdr->from) {
@@ -504,7 +505,22 @@
 		    }
 		}
 	    }
-	    
+
+	    if (hdr->time_sent) {
+		char date_buf[SLEN];
+
+		Date_buffer = new_string(display_charset);
+		add_ascii_to_string(Date_buffer,
+				    s2us(elm_date_str(date_buf,
+						      hdr->time_sent +
+						      hdr->tz_offset,
+						      sizeof date_buf)));
+		if (hdr->time_zone[0]) {
+		    add_ascii_to_string(Date_buffer, s2us(" "));
+		    add_ascii_to_string(Date_buffer, s2us(hdr->time_zone));
+		}
+	    }
+
 	    if (!cur_editcharset)
 		cur_editcharset = display_charset;
 
@@ -523,12 +539,15 @@
 				     hdr->env_from);
 		    
 		} else if (attribution[0] && hdr) {
+		    char * date = us2s(stream_from_string(Date_buffer,1,NULL));
+
 		    if (From_buffer) {
 			char * str = us2s(stream_from_string(From_buffer,1,NULL));
-			fprintf(reply, attribution, str);
+			fprintf(reply, attribution, str, date);
 			free(str);
 		    } else
-			fprintf(reply, attribution, hdr->env_from);
+			fprintf(reply, attribution, hdr->env_from, date);
+		    free(date);
 		    fputc('\n', reply);
 		}
 		if (edit_message && mailbox_file) {
@@ -621,6 +640,8 @@
 
 	    if (From_buffer)
 		free_string(&From_buffer);
+	    if (Date_buffer)
+		free_string(&Date_buffer);
 
 	} else  { 
 	    /* make referenced message as edited message */
