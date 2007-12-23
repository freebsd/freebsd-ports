--- ui.c	10 Apr 2006 08:15:46 -0000	1.57
+++ ui.c	6 Sep 2006 02:24:33 -0000	1.58
@@ -569,9 +569,13 @@
 	} else {
 		char *s;
 		s = ui_readline("/", findstr, MAX_FIELD_LEN - 1, 0);
-		strncpy(findstr, s, MAX_FIELD_LEN);
-		free(s);
 		refresh_screen();
+		if(s == NULL) {
+			return; /* user cancelled (ctrl-G) */
+		} else {
+			strncpy(findstr, s, MAX_FIELD_LEN);
+			free(s);
+		}
 	}
 
 	if( (item = find_item(findstr, curitem + !!next, search_fields)) < 0 &&
