--- src/display.cc.orig	2005-10-15 16:10:01 UTC
+++ src/display.cc
@@ -1191,7 +1191,7 @@ void display_histogram()
 
 		/* compose a row of hashes */
 		memset(line, ' ', hist_width);
-		line[hist_width] = (char)NULL;
+		line[hist_width] = '\0';
 		for(j = 0 ; j < hist_width ; ++j)
 		{
 			if (bar_height[j] > y_scale)
@@ -1203,7 +1203,7 @@ void display_histogram()
 	}
 
 	memset(horiz_line, '-', hist_width);
-	horiz_line[hist_width] = (char)NULL;
+	horiz_line[hist_width] = '\0';
 	mvprintw(HISTOGRAM_START + hist_height, 2, "0+%*s",
 	    hist_width, horiz_line);
 	
