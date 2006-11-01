--- html.c.orig	Sat Oct 23 22:57:02 2004
+++ html.c	Wed Nov  1 15:45:01 2006
@@ -50,6 +50,7 @@
 #define	MAX_PER_PAGE	(cols*rows)
 
 extern int	cols;
+extern int	exif_display;
 extern int	rows;
 extern char	generated[];
 extern char	*albumdesc;
@@ -115,37 +116,66 @@
 		    imglist[x].width,
 		    imglist[x].height,
 		    (int) (imglist[x].filesize/1024));
-		
-		fprintf(html, "<table width=\"100%%\" border=\"1\">\n");
-		
-		if (imglist[x].datetime != NULL) {
-			fprintf(html, "<tr>\n<td><small>Taken:</small></td>"
-			    "<td><small>%s</small></td>\n</tr>\n",
-			    imglist[x].datetime);
-		}
-		if (imglist[x].aperture != NULL) {
-			fprintf(html, "<tr>\n<td><small>Aperture:</small></td>"
-			    "<td><small>%s</small></td>\n</tr>\n",
-			    imglist[x].aperture);
-		}
-		if (imglist[x].exposuretime != NULL) {
-			fprintf(html, "<tr>\n<td><small>Exposure Time</small>:"
-			    "</td><td><small>%s</small></td>\n</tr>\n",
-			    imglist[x].exposuretime);
-		}
-		if (imglist[x].flash != NULL) {
-			fprintf(html, "<tr>\n<td><small>Flash:</small></td>"
-			    "<td><small>%s</small></td>\n</tr>\n",
-			    imglist[x].flash);
-		}
-		if (imglist[x].model != NULL) {
-			fprintf(html, "<tr>\n<td><small>Model:</small></td>"
-			    "<td><small>%s</small></td>\n</tr>\n",
-			    imglist[x].model);
+
+		/* Display by default */
+		if (exif_display == 1) {
+			fprintf(html, "<table width=\"100%%\" border=\"1\">\n");
+
+			if (imglist[x].datetime != NULL) {
+				fprintf(html, "<tr>\n<td><small>Taken:</small></td>"
+				    "<td><small>%s</small></td>\n</tr>\n",
+				    imglist[x].datetime);
+			}
+			if (imglist[x].aperture != NULL) {
+				fprintf(html, "<tr>\n<td><small>Aperture:</small></td>"
+				    "<td><small>%s</small></td>\n</tr>\n",
+				    imglist[x].aperture);
+			}
+			if (imglist[x].exposuretime != NULL) {
+				fprintf(html, "<tr>\n<td><small>Exposure Time:</small>"
+				    "</td><td><small>%s</small></td>\n</tr>\n",
+				    imglist[x].exposuretime);
+			}
+			if (imglist[x].flash != NULL) {
+				fprintf(html, "<tr>\n<td><small>Flash:</small></td>"
+				    "<td><small>%s</small></td>\n</tr>\n",
+				    imglist[x].flash);
+			}
+			if (imglist[x].model != NULL) {
+				fprintf(html, "<tr>\n<td><small>Model:</small></td>"
+				    "<td><small>%s</small></td>\n</tr>\n",
+				    imglist[x].model);
+			}
+
+			fprintf(html, "</table>\n<p>\n<small>\n");
+		/* Hide in comments if user requests */
+		} else if (exif_display == 2) {
+			fprintf(html, "<!-- Begin EXIF data\n");
+
+			if (imglist[x].datetime != NULL) {
+				fprintf(html, "Taken: %s\n",
+				    imglist[x].datetime);
+			}
+			if (imglist[x].aperture != NULL) {
+				fprintf(html, "Aperture: %s\n",
+				    imglist[x].aperture);
+			}
+			if (imglist[x].exposuretime != NULL) {
+				fprintf(html, "Exposure Time: %s\n",
+				    imglist[x].exposuretime);
+			}
+			if (imglist[x].flash != NULL) {
+				fprintf(html, "Flash: %s\n",
+				    imglist[x].flash);
+			}
+			if (imglist[x].model != NULL) {
+				fprintf(html, "Model: %s\n",
+				    imglist[x].model);
+			}
+
+			fprintf(html, "End EXIF data -->\n");
 		}
 		
-		fprintf(html, "</table>\n<p>\n<small>\n");
-		
 		if (offset == 1) {
 			fprintf(html, "<a href=\"index.html\">"
 			    "Back to thumbnails</a>\n");
@@ -197,7 +227,7 @@
  * Returns the number of thumbnail index pages created.
  */
 int 
-create_thumbindex(char *dir, struct imginfo *imglist, int imgcount)
+create_thumbindex(char *dir, struct imginfo *imglist, int imgcount, int show_descr)
 {
 	char *desc, final[MAXPATHLEN], tmp[MAXPATHLEN];
 	int pages, offset, x, y;
@@ -277,21 +307,33 @@
 		while (x < y) {
 			if (x % cols == 0)
 				fprintf(html, "<tr>\n");
-			
-			fprintf(html, "<td align=\"center\">\n"
-			    "<a href=\"%s.html\"><img src=\".thumbs/%s\" "
-			    "border=\"0\" alt=\"%s\" width=\"%d\" "
-			    "height=\"%d\"></a><br>\n<small>%d x %d, %d KB"
-			    "</small>\n<br><br>\n</td>\n", 
-			    imglist[x].filename, 
-			    imglist[x].filename, 
-			    imglist[x].filename, 
-			    imglist[x].thumbwidth, 
-			    imglist[x].thumbheight,
-			    imglist[x].width,
-			    imglist[x].height,
-			    (int)(imglist[x].filesize / 1024));
-			
+			if (show_descr) {
+				fprintf(html, "<td align=\"center\">\n"
+				    "<a href=\"%s.html\"><img src=\".thumbs/%s\" "
+				    "border=\"0\" alt=\"%s\" width=\"%d\" "
+				    "height=\"%d\"></a><br>\n<small>%s"
+				    "</small>\n<br><br>\n</td>\n", 
+				    imglist[x].filename, 
+				    imglist[x].filename, 
+				    imglist[x].filename, 
+				    imglist[x].thumbwidth, 
+				    imglist[x].thumbheight,
+				    imglist[x].description);
+			} else {
+				fprintf(html, "<td align=\"center\">\n"
+				    "<a href=\"%s.html\"><img src=\".thumbs/%s\" "
+				    "border=\"0\" alt=\"%s\" width=\"%d\" "
+				    "height=\"%d\"></a><br>\n<small>%d x %d, %d KB"
+				    "</small>\n<br><br>\n</td>\n", 
+				    imglist[x].filename, 
+				    imglist[x].filename, 
+				    imglist[x].filename, 
+				    imglist[x].thumbwidth, 
+				    imglist[x].thumbheight,
+				    imglist[x].width,
+				    imglist[x].height,
+				    (int)(imglist[x].filesize / 1024));
+			}	
 			if ((x % cols == cols - 1) || (x + 1 == imgcount))
 				fprintf(html, "</tr>\n");
 			
