--- src/logwindow.c.bak	Tue Aug 17 14:40:13 2004
+++ src/logwindow.c	Tue Aug 17 14:40:26 2004
@@ -146,6 +146,7 @@
 		color = &logwindow->msg_color;
 		break;
 	default:
+		break;
 	}
 
 	if (head) gtk_text_insert(text, NULL, color, NULL, head, -1);
