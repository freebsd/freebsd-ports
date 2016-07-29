--- base/newspost.c.orig	2003-04-23 15:33:23 UTC
+++ base/newspost.c
@@ -342,7 +342,7 @@ static Buff *read_text_file(Buff *text_b
 	file = fopen(filename, "r");
 	if (file != NULL) {
 		while (!feof(file)) {
-			line = getline(line, file);
+			line = get_line(line, file);
 			if(line == NULL){
 				text_buffer = buff_add(text_buffer, "\r\n");
 				continue;
