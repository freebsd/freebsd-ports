--- plfig.c.orig	Tue Jul  5 09:21:25 1988
+++ plfig.c	Wed Apr  3 10:27:15 2002
@@ -121,7 +121,48 @@
 	htrue = vtrue = 0;
 }
 
-troff(s)	/* handle ".ps n" to set the pen size to "n" pixels */
+/* handle ".ps n" to set the pen size to "n" pixels */
+/* handle ".ft n" to set the output font to number n
+  (.ft value)
+	-1	Default font
+	 0	Times Roman           
+	 1	Times Italic          
+	 2	Times Bold            
+	 3	Times Bold Italic    
+	 4	AvantGarde Book      
+	 5	AvantGarde Book Oblique 
+	 6	AvantGarde Demi
+	 7	AvantGarde Demi Oblique
+	 8	Bookman Light
+	 9	Bookman Light Italic
+	10	Bookman Demi
+	11	Bookman Demi Italic
+	12	Courier
+	13	Courier Oblique
+	14	Courier Bold
+	15	Courier Bold Oblique
+	16	Helvetica
+	17	Helvetica Oblique
+	18	Helvetica Bold
+	19	Helvetica Bold Oblique
+	20	Helvetica Narrow
+	21	Helvetica Narrow Oblique
+	22	Helvetica Narrow Bold
+	23	Helvetica Narrow Bold Oblique
+	24	New Century Schoolbook Roman
+	25	New Century Schoolbook Italic
+	26	New Century Schoolbook Bold
+	27	New Century Schoolbook Bold Italic
+	28	Palatino Roman
+	29	Palatino Italic
+	30	Palatino Bold
+	31	Palatino Bold Italic
+	32	Symbol
+	33	Zapf Chancery Medium Italic
+	34	Zapf Dingbats
+*/
+
+troff(s)
 	char *s;
 {
     if (strncmp (s, ".ps", 3) == 0) {
@@ -131,6 +172,16 @@
 	    pensize (size);
 	else
 	    fprintf (stderr, "Malformed .ps command: %s\n", s);
+	return;
+    }
+    if (strncmp (s, ".ft", 3) == 0) {
+	int     size;
+        extern int font;
+
+	if (sscanf (s + 3, " %d ", &size) == 1)
+	    font = size;
+	else
+	    fprintf (stderr, "Malformed .ft command: %s\n", s);
 	return;
     }
 
