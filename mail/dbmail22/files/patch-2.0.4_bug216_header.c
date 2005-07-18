Index: header.c
===================================================================
--- header.c	(revision 1796)
+++ header.c	(revision 1813)
@@ -176,15 +176,17 @@
 		if (message_content[line_content_size] == '\n') {
 			tmp_line_size = line_content_size + 1;
 			tmp_line_rfcsize = tmp_line_size + 1;
-		} else {
-			if (message_content[line_content_size] == '\r' &&
-			    message_content[line_content_size + 1] == '\n') {
+		} else if (message_content[line_content_size] == '\r') {
+			if (message_content[line_content_size + 1] == '\n') {
+				/* This is the right behaviour */
 				tmp_line_size = line_content_size + 2;
 				tmp_line_rfcsize = tmp_line_size;
 			} else {
-				trace(TRACE_ERROR, "%s,%s: error reading header line",
-				      __FILE__, __func__);
-				return -1;
+				/* This is broken behaviour, but it's better
+				 * than not handling it at all.
+				 */
+				tmp_line_size = line_content_size + 1;
+				tmp_line_rfcsize = tmp_line_size + 1;
 			}
 		}
 	}
@@ -197,7 +199,6 @@
 		      __FILE__, __func__);
 		return 0;
 	}
-	else
-		return 1;
+	return 1;
 	
 }
