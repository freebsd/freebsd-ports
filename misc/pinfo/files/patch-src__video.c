--- src/video.c.orig	Thu Mar 16 06:54:56 2006
+++ src/video.c	Fri Mar 17 16:08:37 2006
@@ -88,9 +88,11 @@
 	attrset(normal);
 	for (i = pos;(i < lines) &&(i < pos + maxy - 2); i++)
 	{
+		int tmp;
+
 		if (!message[i]) continue;
 
-		int tmp = strlen(message[i]) - 1;
+		tmp = strlen(message[i]) - 1;
 		message[i][tmp] = 0;
 		if (tmp>column)
 			mvaddstr(i + 1 - pos, 0, message[i]+column);
@@ -263,12 +265,14 @@
 	{
 		regmatch_t pmatch[1];
 		long maxpos = pos +(maxy - 2);
+		int maxregexp;
+
 		if (maxpos > lines)
 		{
 			maxpos = lines;
 		}
 
-		int maxregexp = aftersearch ? h_regexp_num + 1 : h_regexp_num;
+		maxregexp = aftersearch ? h_regexp_num + 1 : h_regexp_num;
 		/*
 		 * if it is after search, then we have user defined regexps+
 		 * a searched regexp to highlight
@@ -285,19 +289,22 @@
 				/* check if this regexp is present on this line */
 				while (!regexec(&h_regexp[j], str, 1, pmatch, 0))
 				{
+					int n, x, y;
+					char tmp;
+
 					/* yes, found something, so highlight it */
-					int n = pmatch[0].rm_eo - pmatch[0].rm_so;
+					n = pmatch[0].rm_eo - pmatch[0].rm_so;
 
 					/* point str at start of match */
 					str += pmatch[0].rm_so;
 
 					/* calculate position on screen */
-					int x = calculate_len(message[i], str);
-					int y = i - pos + 1;
+					x = calculate_len(message[i], str);
+					y = i - pos + 1;
 
 					/* save the char after the end of the match, 
 					 * and replace it by \0 */
-					char tmp = str[n];
+					tmp = str[n];
 					str[n] = 0;
 					
 					/* write out the highlighted match to screen */
