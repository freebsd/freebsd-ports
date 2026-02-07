--- figd.c.orig	Sat Aug  6 19:52:43 1988
+++ figd.c	Wed Apr  3 10:27:14 2002
@@ -6,13 +6,16 @@
  *
  * Modified by Micah Beck to produce Fig code
  * Modified by Micah Beck again to produce Fig 1.4 code
+ * Modified by Patrick Powell to produce Fig 3.2 code
  */
 
 #include <stdio.h>
 #include <ctype.h>
 #include "object.h"
 
-#define DEF_PEN_SIZE	8	/* Default pen diameter */
+/* #define DEF_PEN_SIZE	8	/ * Default pen diameter */
+#define DEF_PEN_SIZE	1	/* Default pen diameter */
+#define DEF_FONT_SIZE	12	/* Default pen diameter */
 #define	MAXPOINTS	300	/* Max number of points in a path */
 
 #define bool int
@@ -23,6 +26,8 @@
 #define	P_BLACK		15
 #define	TEXTURE		3
 #define ORTEXTURE	7
+#define FONT_HT 12
+#define FONT_WIDTH 8
 
 extern	double	sqrt(), cos(), sin();
 
@@ -31,11 +36,15 @@
 #define RES			1000.0
 #define Pix_To_In(x)		(((float) x) / RES)
 
-#define FIGRES			80
+/* #define FIGRES			80 */
+#define FIGRES			1200
 #define FIGCANV_W		(8*FIGRES)
 #define FIGCANV_H		(10*FIGRES)
+#define Points_To_Figpix(x)	((int)(FIGRES * (x)/72.0))
 #define Pix_To_Figpix(x)	((int)(FIGRES * Pix_To_In(x)))
-#define Pen_to_Figpix(x)	((x*FIGRES + 500) / 1000)
+/* #define Pen_to_Figpix(x)	((x*FIGRES + 500) / 1000) */
+/* pen thickness in 1/80 of inch */
+#define Pen_to_Figpix(x)	((Pix_To_In(x) + 79) / 80)
 
 
 extern	int dbg;		/* Non-zero when debugging info wanted */
@@ -44,8 +53,10 @@
 static	float xslope,yslope,xbase,ybase;/* Convert Window to Viewport */
 static	int arraylen;		/* Number of points in current path */
 static	bool pathsent;		/* True if path has been defined */
-static	int ipensize;		/* Desired current pen size */
+static	int ipensize = DEF_PEN_SIZE;		/* Desired current pen size */
+static	int ifontsize = DEF_FONT_SIZE;		/* Desired current font size */
 extern	FILE *TEXFILE;		/* Output file */
+int     font = -1;  /* font number */
 
 
 /*
@@ -62,7 +73,7 @@
 	yslope = RES * (hiypage-loypage) / (hiy-loy);
 	ybase  = RES * loypage - loy*yslope;
 	if (dbg)
-	    printf("Coefficients: %10.5f%10.5f%10.5f%10.5f\n",
+	    printf("Coefficients: %10.5f  %10.5f  %10.5f  %10.5f\n",
 		xslope,xbase,yslope,ybase);
 }
 
@@ -70,14 +81,18 @@
 /*
  * Set the size of the virtual pen used in drawing
  */
+static sendpath();
 pensize(x)
 int	x;
 {
 	if (x != ipensize) {
 	    ipensize = Pen_to_Figpix(x);
+        ifontsize = x;
+		if( ipensize == 0 ) ipensize = 1;
 	    if (!pathsent) sendpath();
 	    clearpath();
 	}
+	if( dbg) printf("pensize %d -> %d\n", x, ipensize );
 }
 
 
@@ -149,24 +164,85 @@
 float	x, y;
 int	position;	/* Indicates what part of text is at (x,y) */
 {
-    int	    ix, iy, offset;
-    char    *cp;
+    int	    ix, iy, offset, c;
+    unsigned char    *cp;
     map(x, y, &ix, &iy, 1);
 
-    for (cp = text; *cp && isspace(*text); cp++);
+    for (cp = (unsigned char *)text; isspace(*cp); cp++);
     if (!*cp) return;
 
 #ifdef TEXT_LEFT_ONLY
-    if (position != T_LEFT_JUSTIFIED) offset = strlen(cp)*8;
+    if (position != T_LEFT_JUSTIFIED) offset = strlen(cp)*Points_To_Figpix(ifontsize);
     if (position == T_CENTER_JUSTIFIED) offset = offset/2;
     position = T_LEFT_JUSTIFIED;
 #else
     offset = 0;
 #endif TEXT_LEFT_ONLY
 
+/* FORMAT 1.4 CODE
     fprintf(TEXFILE, "%d %d %d %d %d %d %6.3f %d %d %d %d %d %s%c\n",
-	O_TEXT, position, -1, -1, -1, -1, 0.0, -1, 16, strlen(cp)*8,
+                   4   justification (0,1,2)
+                            font (unused)
+                               fontsize (unused)
+                                  pen (unused)
+                                     color
+                                        depth
+                                          angle (not used)
+                                              height (pixels)
+                                                 length (pixels)
+                                                
+	4, position, -1, -1, -1, -1, 0.0, -1, 16, strlen(cp)*Points_To_Figpix(ifontsize),
 	Pix_To_Figpix(ix) - offset, Pix_To_Figpix(iy), cp, '\01');
+Example:
+4 1 -1 -1 -1 -1  0.000 -1 16 24 229 603 FEP^A
+
+FORMAT 3.2 CODE
+Example:
+4 1 -1 0 -1 -1 12 0.0000 4 135 330 3450 9060 FEP\001 
+1 2  3 4  5  6  7 8      9  10  11  12  13   14
+    (3.7) TEXT
+    type    name            (brief description)
+    ----    ----            -------------------
+    int object          (always 4)                  1
+    int sub_type        (0: Left justified          2
+                         1: Center justified
+                         2: Right justified)
+    int color           (enumeration type)          3
+    int depth           (enumeration type)          4
+    int pen_style       (enumeration , not used)    5
+    int font            (enumeration type)          6
+    float   font_size       (font size in points)   7
+    float   angle           (radians, the angle of the text) 8
+    int font_flags      (bit vector)                9
+    float   height          (Fig units)             10
+    float   length          (Fig units)             11
+    int x, y            (Fig units, coordinate of the origin  12,13
+                     of the string.  If sub_type = 0, it is
+                     the lower left corner of the string.
+                     If sub_type = 1, it is the lower
+                     center.  Otherwise it is the lower
+                     right corner of the string.)
+    char    string[]        (ASCII characters; starts after a blank  14
+                     character following the last number and
+                     ends before the sequence '\001'.  This
+                     sequence is not part of the string.
+
+
+*/
+    if(dbg) printf("string (%d,%d) '%s'\n", Pix_To_Figpix(ix-offset), Pix_To_Figpix(iy), cp );
+		
+    fprintf(TEXFILE, "%d %d %d %d %d %d %d %6.3f %d %d %d %d %d ",
+	O_TEXT, position,       -1, 0,-1,font,ifontsize,0.0,   4,Pix_To_Figpix(FONT_HT),Pix_To_Figpix(strlen(cp)*FONT_WIDTH),
+		Pix_To_Figpix(ix-offset), Pix_To_Figpix(iy));
+	while( (c = ((unsigned char *)(cp))[0]) ){
+		if( c == '\\' ){
+			fprintf(TEXFILE, "\\\\");
+		} else if( isprint(c) || isspace(c) ){
+			fprintf(TEXFILE, "%c", c);
+		}
+		++cp;
+	}
+	fprintf(TEXFILE, "\\001\n");
 }
 
 
@@ -208,16 +284,54 @@
 {
 	register int i;
 
-	if (dbg) printf("Sending path ...%d\n", arraylen);
+	if (dbg) printf("Sendpath [%d], ipensize %d\n", arraylen, ipensize);
 	if (arraylen > 1) {
 
+	/*
 	    fprintf(TEXFILE, "%d %d %d %d %d %d %d %d %d %d %d\n",
 		O_POLYLINE, T_POLYLINE, SOLID_LINE,
 		ipensize, -1, -1, -1, -1, -1, 0, 0);
-	    for (i=1; i<=arraylen; i++)
-		fprintf(TEXFILE, "%d %d ",
+
+Example:
+        2 1 0 1 -1 -1 -1 -1 -1 0 0
+        19 149  19 9  179 9  179 149  19 149  9999 9999
+
+New format:
+       2 1 0 1 -1 -1 0 -1 -1 -1.000 0 0 -1 0 0 5
+       code     pen_color
+         type      fill_color
+           line style 
+                     depth
+                       pen_style
+                             style_value
+                                   join_style
+                                      cap_style
+                                          radius
+                                             forward_arrow
+                                                count
+             thickness (1/80 inch)
+           -1 = Default
+            0 = Solid
+            1 = Dashed
+            2 = Dotted
+            3 = Dash-dotted
+            4 = Dash-double-dotted
+            5 = Dash-triple-dotted
+
+       300 2250 300 150 2700 150 2700 2250 300 2250
+
+
+	*/
+	    fprintf(TEXFILE, "%d %d %d %d -1 -1 0 -1 -1 -1.000 0 0 -1 0 0 %d\n  ",
+		2, T_POLYLINE, SOLID_LINE, ipensize, arraylen );
+	    for (i=1; i<=arraylen; i++){
+			if (dbg) printf(" (%d,%d)", Pix_To_Figpix(xx[i]), Pix_To_Figpix(yy[i]));
+			fprintf(TEXFILE, "%d %d ",
 			Pix_To_Figpix(xx[i]), Pix_To_Figpix(yy[i]));
-	    fprintf(TEXFILE, "9999 9999\n");
+		}
+		if (dbg) printf("\n", Pix_To_Figpix(xx[i]), Pix_To_Figpix(yy[i]));
+	    /* fprintf(TEXFILE, "9999 9999\n"); */
+	    fprintf(TEXFILE, "\n");
 	}
 
 	pathsent = TRUE;
@@ -234,17 +348,26 @@
 {
 	register int i;
 
-	if (dbg) printf("Sending path ...%d\n", arraylen);
+	if (dbg) printf("Send_dashed_path ...%d, inchesperdash %f, dotted %d\n",
+		arraylen, inchesperdash, dotted );
 	if (arraylen < 2) return;
 	else {
+/*
 	    fprintf(TEXFILE, "%d %d %d %d %d %d %d %d %d %d %d\n",
 		O_POLYLINE, T_POLYLINE,
 		(dotted ? DOTTED_LINE : DASH_LINE), ipensize,
 		-1, -1, -1, -1, -1, 0, 0);
-	    for (i=1; i<=arraylen; i++)
+ */
+	    fprintf(TEXFILE, "%d %d %d %d -1 -1 0 -1 -1 %f 0 0 -1 0 0 %d\n  ",
+		2, T_POLYLINE, (dotted? DOTTED_LINE: DASH_LINE), ipensize,
+			inchesperdash*80,
+			arraylen );
+	    for (i=1; i<=arraylen; i++){
 		fprintf(TEXFILE, "%d %d ",
 			Pix_To_Figpix(xx[i]), Pix_To_Figpix(yy[i]));
-	    fprintf(TEXFILE, "9999 9999\n");
+		}
+	    /* fprintf(TEXFILE, "9999 9999\n"); */
+	    fprintf(TEXFILE, "\n");
 	}
 
 	pathsent = TRUE;
@@ -294,7 +417,7 @@
 fig_arc(xcenter, ycenter, xradius, yradius, start, stop)
 float	xcenter, ycenter, xradius, yradius, start, stop;
 {
-    int X0, Y0, xrad, yrad, xend, yend;
+    int X0, Y0, xrad, yrad, xend, yend, xstart, ystart;
     extern double cos(), sin();
 
     map(xcenter, ycenter, &X0, &Y0, FALSE);
@@ -304,18 +427,85 @@
     if (is_onarc(PI/2, start, stop)) ckbounds(X0, Y0+yrad);
     if (is_onarc(PI, start, stop)) ckbounds(X0-xrad, Y0);
     if (is_onarc(1.5*PI, start, stop)) ckbounds(X0, Y0-yrad);
-    xend = X0 + xrad * cos(start) + 0.5;
-    yend = Y0 + yrad * sin(start) + 0.5;
-    ckbounds(xend, yend);
+    xstart = X0 + xrad * cos(start) + 0.5;
+    ystart = Y0 + yrad * sin(start) + 0.5;
+    ckbounds(xstart, ystart);
     xend = X0 + xrad * cos(stop);
     yend = Y0 + yrad * sin(stop);
     ckbounds(xend, yend);
+	if(dbg) printf("Ellipse: X0 %d, Y0 %d, xrad %d, yrad %d, xstart %d, ystart %d, xend %d, yend %d\n",
+		Pix_To_Figpix(X0), Pix_To_Figpix(Y0),
+		Pix_To_Figpix(xrad), Pix_To_Figpix(yrad),
+		Pix_To_Figpix(xstart), Pix_To_Figpix(ystart),
+		Pix_To_Figpix(xend), Pix_To_Figpix(yend));
+
+/*
+    int object_code     (always 1)
+    int sub_type        (1 : ellipse defined by radiuses
+                     2 : ellipse defined by diameters
+                     3 : circle defined by radius
+                     4 : circle defined by diameter)
+    int line_style      (See the end of this section)
+    int thickness       (pixels, not used)
+    int color           (not used)
+    int depth           (not used)
+    int pen         (not used)
+    int area_fill       (not used)
+    float   style_val       (pixels, not used)
+    int direction       (always 1)
+    float   angle           (radian, the angle of the x-axis)
+    int center_x, center_y  (pixels)
+    int radius_x, radius_y  (pixels)
+    int start_x, start_y    (pixels; the 1st point entered)
+    int end_x, end_y        (pixels; the last point entered)
+
+Example:
+  1 1 0 1 -1, -1 -1 -1 -1 1 0  0.000  0.000  0.000  0.000  0.000  0.000
 
     fprintf(TEXFILE, "%d %d %d %d %d, %d %d %d %d %d %d %6.3f %6.3f %6.3f %6.3f %6.3f %6.3f\n",
 		O_ELLIPSE, T_ELLIPSE_BY_RAD,
 	        SOLID_LINE, ipensize, -1, -1, -1, -1, -1, 1, 0.0,
 		Pix_To_Figpix(X0), Pix_To_Figpix(Y0),
 		Pix_To_Figpix(xrad), Pix_To_Figpix(yrad), 0.0, 0.0, 0.0, 0.0);
+
+
+    int object_code     (always 1)
+    int sub_type        (1: ellipse defined by radii
+                     2: ellipse defined by diameters
+                     3: circle defined by radius
+                     4: circle defined by diameter)
+    int line_style      (enumeration type)
+    int thickness       (1/80 inch)
+   --
+    int pen_color       (enumeration type, pen color)
+    int fill_color      (enumeration type, fill color)
+    int depth           (enumeration type)
+    int pen_style       (pen style, not used)
+    int area_fill       (enumeration type, -1 = no fill)
+    float   style_val       (1/80 inch)
+    int direction       (always 1)
+    float   angle           (radians, the angle of the x-axis)
+    int center_x, center_y  (Fig units)
+    int radius_x, radius_y  (Fig units)
+    int start_x, start_y    (Fig units; the 1st point entered)
+    int end_x, end_y        (Fig units; the last point entered)
+
+Example:
+   1 1 0 1 0 7 50 0 -1 0.000 1 0.0000 1125 975 675 375 1125 975 1800 1350
+           pen      areafill
+             fill      styleval
+               depth
+                  pen_style
+*/
+
+
+    fprintf(TEXFILE, "%d %d %d %d", O_ELLIPSE, T_ELLIPSE_BY_RAD, SOLID_LINE, ipensize );
+	fprintf(TEXFILE, " 0 7 50 0 -1 0.0 1 0.0" );
+	fprintf(TEXFILE, " %d %d %d %d %d %d %d %d\n",
+		Pix_To_Figpix(X0), Pix_To_Figpix(Y0),
+		Pix_To_Figpix(xrad), Pix_To_Figpix(yrad),
+		Pix_To_Figpix(xstart), Pix_To_Figpix(ystart),
+		Pix_To_Figpix(xend), Pix_To_Figpix(yend));
 }
 
 
@@ -347,14 +537,56 @@
  */
 fig_begin_drawing()
 {
-  	fprintf(TEXFILE, "#FIG 1.4\n%d %d\n", FIGRES, 2);
+
+/*
+(1) The very first line is a comment line containing the name and version:
+    #FIG 3.2
+(2) The first non-comment line consists of the following:
+
+    string  orientation     ("Landscape" or "Portrait")
+    string  justification       ("Center" or "Flush Left")
+    string  units           ("Metric" or "Inches")
+    string  papersize       ("Letter", "Legal", "Ledger", "Tabloid",
+                     "A", "B", "C", "D", "E",
+                     "A4",   "A3", "A2", "A1", "A0" and "B5")
+    float   magnification       (export and print magnification, %)
+    string  multiple-page       ("Single" or "Multiple" pages)
+    int transparent color   (color number for transparent color for GIF
+                     export. -3=background, -2=None, -1=Default,
+                     0-31 for standard colors or 32- for user colors)
+    # optional comment      (An optional set of comments may be here,
+                     which are associated with the whole figure)
+    int resolution coord_system (Fig units/inch and coordinate system:
+                       1: origin at lower left corner (NOT USED)
+                       2: upper left)
+Example:
+   #FIG 3.2
+   Landscape
+   Center
+   Inches
+   Letter
+   100.00
+   Single
+   -2
+   1200 2
+
+*/
+  	fprintf(TEXFILE, "#FIG 3.2\n");
+  	fprintf(TEXFILE, "Landscape\n");
+  	fprintf(TEXFILE, "Center\n");
+  	fprintf(TEXFILE, "Inches\n");
+  	fprintf(TEXFILE, "Letter\n");
+  	fprintf(TEXFILE, "100.00\n");
+  	fprintf(TEXFILE, "Single\n");
+  	fprintf(TEXFILE, "-2\n");
+  	fprintf(TEXFILE, "%d %d\n", FIGRES, 2 );
 
 	fig_window(0.0, 0.0, 10.0, 10.0, 0.0, 0.0, 3.0, 3.0);
 	xmin = 30000;	xmax = -30000;
 	ymin = 30000;	ymax = -30000;
 	arraylen = 0;
 	pathsent = FALSE;
-	ipensize = Pen_to_Figpix(DEF_PEN_SIZE);
+	pensize(DEF_PEN_SIZE);
 }
 
 
@@ -392,15 +624,67 @@
 	clearpath();
     }
 
+/*
     fprintf(TEXFILE, "%d %d %d %d %d %d %d %d %d %d %d\n",
 	O_SPLINE, T_OPEN_NORMAL,
 	SOLID_LINE, ipensize, -1, -1, -1, -1, -1, 0, 0);
+    fprintf(TEXFILE, "9999 9999\n");
+
+New format:
+    int object_code     (always 3)
+    int sub_type        (0: open approximated spline
+                         1: closed approximated spline
+                         2: open   interpolated spline
+                         3: closed interpolated spline
+                         4: open   x-spline
+                         5: closed x-spline)
+    int line_style      (See the end of this section)
+    int thickness       (1/80 inch)
+    int pen_color       (enumeration type, pen color)
+    int fill_color      (enumeration type, fill color)
+    int depth           (enumeration type)
+    int pen_style       (pen style, not used)
+    int area_fill       (enumeration type, -1 = no fill)
+    float   style_val       (1/80 inch)
+    int cap_style       (enumeration type, only used for open splines)
+    int forward_arrow       (0: off, 1: on)
+    int backward_arrow      (0: off, 1: on)
+    int npoints         (number of control points in spline)
+
+    Forward arrow line: same as ARC object
+
+    Backward arrow line: same as ARC object
+
+    Points line: same as POLYLINE object
+
+    Control points line :
+
+    There is one shape factor for each point. The value of this factor
+    must be between -1 (which means that the spline is interpolated at
+    this point) and 1 (which means that the spline is approximated at
+    this point). The spline is always smooth in the neighbourhood of a
+    control point, except when the value of the factor is 0 for which
+    there is a first-order discontinuity (i.e. angular point).
+
+Example:
+    3 2 0 1 0 7 50 0 -1 0.000 0 0 0 3
+     975 1950 1875 1500 2550 1950
+     0.000 -1.000 0.000
+
+*/
+    fprintf(TEXFILE, "%d %d %d %d", 3, 2, SOLID_LINE, ipensize );
+	fprintf(TEXFILE, " 0 7 50 0 -1 0.000 0 0 0 %d\n  ", N-1 );
     for (i=1; i<N; i++) {
-	ckbounds(xx[i], yy[i]);
-	fprintf(TEXFILE, "%d %d ",
-		Pix_To_Figpix(xx[i]), Pix_To_Figpix(yy[i]));
-      }
-    fprintf(TEXFILE, "9999 9999\n");	
+		ckbounds(xx[i], yy[i]);
+		fprintf(TEXFILE, " %d %d",
+			Pix_To_Figpix(xx[i]), Pix_To_Figpix(yy[i]));
+	}
+    fprintf(TEXFILE, "\n  ");
+    fprintf(TEXFILE, " 0.0");
+    for (i=2; i<N-1; i++) {
+		fprintf(TEXFILE, " -1.0");
+	}
+    fprintf(TEXFILE, " 0.0\n");
 }
 
 
