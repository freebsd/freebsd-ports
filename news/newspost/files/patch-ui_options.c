--- ui/options.c.orig	2003-04-23 15:33:33 UTC
+++ ui/options.c
@@ -332,7 +332,7 @@ void parse_defaults(newspost_data *data)
 		file = fopen(filename->data, "r");
 		if (file != NULL) {
 			while (!feof(file)) {
-				line = getline(line, file);
+				line = get_line(line, file);
 				linenum++;
 				if(line == NULL) continue;
 
@@ -429,7 +429,7 @@ void parse_defaults(newspost_data *data)
 				linenum = 0;
 				while (linenum < 8) {
 					linenum++;
-					line = getline(line, file);
+					line = get_line(line, file);
 					if(line == NULL) continue;
 
 					switch (linenum) {
