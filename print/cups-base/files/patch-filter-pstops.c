--- filter/pstops.c	Tue May 28 15:04:50 2002
+++ /home/alane/sw/src/cups/filter/pstops.c	Thu Jun 27 12:31:45 2002
@@ -60,8 +60,8 @@
 #define LAYOUT_RLBT	2	/* Right to left, bottom to top */
 #define LAYOUT_RLTB	3	/* Right to left, top to bottom */
 #define LAYOUT_BTLR	4	/* Bottom to top, left to right */
-#define LAYOUT_TBLR	5	/* Bottom to top, right to left */
-#define LAYOUT_BTRL	6	/* Top to bottom, left to right */
+#define LAYOUT_TBLR	5	/* Top to bottom, right to left */
+#define LAYOUT_BTRL	6	/* Bottom to top, left to right */
 #define LAYOUT_TBRL	7	/* Top to bottom, right to left */
 
 #define LAYOUT_NEGATEY	1
@@ -418,23 +418,19 @@
 	fputs(line, stdout);
         level --;
       }
-      else if (strncmp(line, "%%Orientation", 13) == 0 && level == 0)
+      else if (strncmp(line, "%ESPRotation:", 13) == 0 && level == 0)
       {
        /*
         * Reset orientation of document?
 	*/
 
-        if (strstr(line, "Landscape") != NULL && !(Orientation & 1))
-	{
-	  Orientation ++;
-	  UpdatePageVars();
-	  Orientation = 1;
-	}
-        else if (strstr(line, "Portrait") != NULL && (Orientation & 1))
+        int orient = (atoi(line + 13) / 90) & 3;
+
+        if (orient != Orientation)
 	{
-	  Orientation = 4 - Orientation;
+	  Orientation = (4 - Orientation + orient) & 3;
 	  UpdatePageVars();
-	  Orientation = 0;
+	  Orientation = orient;
 	}
       }
       else if (strncmp(line, "%%BeginProlog", 13) == 0 && level == 0)
@@ -1646,5 +1642,5 @@
 
 
 /*
- * End of "$Id: pstops.c,v 1.83 2002/05/28 19:04:50 mike Exp $".
+ * End of "$Id: pstops.c,v 1.85 2002/06/27 16:31:45 mike Exp $".
  */
