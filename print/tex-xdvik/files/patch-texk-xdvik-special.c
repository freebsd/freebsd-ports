--- texk/xdvik/special.c.orig	2008-02-16 21:43:15 UTC
+++ texk/xdvik/special.c
@@ -691,6 +691,12 @@ static size_t g_bbox_info_max_size = 0;
   contains these coordinates.
 */
 
+double	bbox_matrix[2][2] = {{1.0, 0.0}, {0.0, 1.0}};
+Boolean	bbox_scaled = False, bbox_rotated = False;
+
+#define	bbox_xscale	bbox_matrix[0][0]
+#define	bbox_yscale	bbox_matrix[1][1]
+
 static void
 append_bbox_info(int x, int y, int w, int h, int angle)
 {
@@ -735,25 +741,25 @@ draw_bbox0(int xcorner, int ycorner)
 	    do_color_change();
 #endif
 
-	if (bbox_angle == 0) {
-	    ycorner -= bbox_voffset;
-	    XDrawRectangle(DISP, currwin.win, globals.gc.high, xcorner, ycorner, bbox_width, bbox_height);
+	if (! bbox_rotated) {
+	    ycorner -= bbox_voffset * bbox_yscale;
+	    XDrawRectangle(DISP, currwin.win, globals.gc.high, xcorner, ycorner,
+			   bbox_width * bbox_xscale, bbox_height * bbox_yscale);
 	    if (resource.postscript == 0) {
 		if (htex_inside_href) {
-		    htex_set_anchorsize(xcorner, ycorner, xcorner + bbox_width, ycorner + bbox_height);
+		    htex_set_anchorsize(xcorner, ycorner, xcorner + bbox_width * bbox_xscale,
+					ycorner + bbox_height * bbox_yscale);
 		    htex_set_objecttype(HTEX_IMG);
 		}
 	    }
 	}
 	else {
-	    float sin_a = sin(bbox_angle * (TWOPI / 360));
-	    float cos_a = cos(bbox_angle * (TWOPI / 360));
 	    float a, b, c, d;
 
-	    a = cos_a * bbox_width;
-	    b = -sin_a * bbox_width;
-	    c = -sin_a * bbox_height;
-	    d = -cos_a * bbox_height;
+	    a = bbox_matrix[0][0] * bbox_width;
+	    b = bbox_matrix[1][0] * bbox_width;
+	    c = -bbox_matrix[0][1] * bbox_height;
+	    d = -bbox_matrix[1][1] * bbox_height;
 
 	    XDrawLine(DISP, currwin.win, globals.gc.high,
 		      xcorner, ycorner,
@@ -782,27 +788,27 @@ display_bboxes(void)
     size_t i;
     
     for (i = 0; i < g_bbox_info_size; i++) {
-	if (globals.debug & DBG_PS) {
-	    fprintf(stderr, "drawing bbox %lu at %d %d, %d x %d, angle %d\n",
-		    (unsigned long)i,
-		    g_bbox_info[i].x,
-		    g_bbox_info[i].y,
-		    g_bbox_info[i].w,
-		    g_bbox_info[i].h,
-		    g_bbox_info[i].angle);
-	}
+       if (globals.debug & DBG_PS) {
+           fprintf(stderr, "drawing bbox %lu at %d %d, %d x %d, angle %d\n",
+                   (unsigned long)i,
+                   g_bbox_info[i].x,
+                   g_bbox_info[i].y,
+                   g_bbox_info[i].w,
+                   g_bbox_info[i].h,
+                   g_bbox_info[i].angle);
+       }
 #if 0
-	XDrawRectangle(DISP, currwin.win, globals.gc.high,
-		       g_bbox_info[i].x,
-		       g_bbox_info[i].y,
-		       g_bbox_info[i].w,
-		       g_bbox_info[i].h);
+       XDrawRectangle(DISP, currwin.win, globals.gc.high,
+                      g_bbox_info[i].x,
+                      g_bbox_info[i].y,
+                      g_bbox_info[i].w,
+                      g_bbox_info[i].h);
 #else
-	bbox_valid = True;
-	bbox_width = g_bbox_info[i].w;
-	bbox_height = bbox_voffset = g_bbox_info[i].h;
-	bbox_angle = g_bbox_info[i].angle;
-	draw_bbox0(g_bbox_info[i].x, g_bbox_info[i].y + bbox_height);
+       bbox_valid = True;
+       bbox_width = g_bbox_info[i].w;
+       bbox_height = bbox_voffset = g_bbox_info[i].h;
+       bbox_angle = g_bbox_info[i].angle;
+       draw_bbox0(g_bbox_info[i].x, g_bbox_info[i].y + bbox_height);
 #endif
     }
     bbox_angle = 0;
@@ -829,6 +835,9 @@ save_bbox(void)
 	
 	ycorner -= bbox_voffset;
 	append_bbox_info(xcorner, ycorner, bbox_width, bbox_height, bbox_angle);
+	if (currwin.win == mane.win && resource.postscript != 1) {
+	    draw_bbox();
+	}
 
 	/* register boundaries of this box as anchor boundaries */
 	if (htex_inside_href) {
@@ -907,6 +916,11 @@ ps_startup2(void)
 }
 
 
+typedef struct {
+  double matrix[2][2];
+  double x, y;
+} ROTATE_STACK;
+
 /*
  * dumb parsing of PostScript - search for rotation H. Zeller 1/97
  * Returns true if we find a potentially non-supported command that
@@ -916,6 +930,52 @@ static Boolean
 ps_parseraw(const char *PostScript_cmd)
 {
     const char *p;
+    double xscale, yscale, angle, sin_a, cos_a, a, b, c, d;
+    int n;
+    static int rotate_stack_len = 0;
+    static int rotate_stack_ptr = 0;
+    static ROTATE_STACK *rotate_stack = NULL;
+
+    p = strstr(PostScript_cmd, "currentpoint grestore moveto");
+    if (p != NULL) {
+	if (rotate_stack_ptr > 0) {
+	    double r;
+	    rotate_stack_ptr--;
+	    r = sqrt(((DVI_H - rotate_stack[rotate_stack_ptr].x)
+		      * (DVI_H - rotate_stack[rotate_stack_ptr].x)
+		      + (DVI_V - rotate_stack[rotate_stack_ptr].y)
+		      * (DVI_V - rotate_stack[rotate_stack_ptr].y))
+		     / (bbox_matrix[0][0] * bbox_matrix[0][0]
+			+ bbox_matrix[1][0] * bbox_matrix[1][0]))
+		* (rotate_stack[rotate_stack_ptr].matrix[0][0]
+		   * bbox_matrix[1][0]
+		   - rotate_stack[rotate_stack_ptr].matrix[1][0]
+		   * bbox_matrix[0][0])
+		/ (rotate_stack[rotate_stack_ptr].matrix[0][0]
+		   * rotate_stack[rotate_stack_ptr].matrix[0][0]
+		   + rotate_stack[rotate_stack_ptr].matrix[1][0]
+		   * rotate_stack[rotate_stack_ptr].matrix[1][0]);
+	    DVI_H += r * rotate_stack[rotate_stack_ptr].matrix[1][0];
+	    DVI_V += r * rotate_stack[rotate_stack_ptr].matrix[0][0];
+	    PXL_V = pixel_conv(DVI_V);
+	    bcopy(rotate_stack[rotate_stack_ptr].matrix, bbox_matrix,
+		  sizeof(bbox_matrix));
+	    bbox_rotated
+		= (bbox_matrix[0][1] != 0.0 || bbox_matrix[1][0] != 0.0)
+		? True : False;
+	    bbox_scaled
+		= (bbox_rotated
+		   || bbox_matrix[0][0] != 1.0 || bbox_matrix[1][1] != 1.0)
+		? True : False;
+	}
+	if (globals.debug & DBG_PS)
+	    fprintf(stderr, "current angle %f: %s\n",
+		    bbox_matrix[0][0] != 0
+		    ? -atan(bbox_matrix[1][0] / bbox_matrix[0][0])
+		    * (360 / TWOPI)
+		    : bbox_matrix[1][0] >= 0 ? (double)90 : (double)-90,
+		    PostScript_cmd);
+    }
 
     bbox_angle = 0;
     p = strstr(PostScript_cmd, "rotate");
@@ -924,9 +984,137 @@ ps_parseraw(const char *PostScript_cmd)
 	    --p;
 	while (*p != '\0' && isdigit((int)*p))
 	    --p;
+	if (*p == '.') --p;
+	while (*p != '\0' && isdigit(*p)) --p;
 	if (*p != '+' && *p != '-')
 	    ++p;
-	sscanf(p, "%d neg rotate", &bbox_angle);
+	n = sscanf(p, "%lf neg rotate", &angle);
+	if (n != 1) {
+	    fprintf(stderr, "%s:  cannot get angle.\n", globals.program_name);
+	    angle = 0.0;
+	}
+	bbox_angle = angle;
+	if (rotate_stack_ptr >= rotate_stack_len) {
+	    rotate_stack_len += 0x10;
+	    rotate_stack = (ROTATE_STACK *)
+		xrealloc(rotate_stack,
+			 sizeof(ROTATE_STACK) * rotate_stack_len);
+	}
+	bcopy(bbox_matrix, rotate_stack[rotate_stack_ptr].matrix,
+	      sizeof(bbox_matrix));
+	rotate_stack[rotate_stack_ptr].x = DVI_H;
+	rotate_stack[rotate_stack_ptr].y = DVI_V;
+	rotate_stack_ptr++;
+
+	sin_a = sin(-angle * (TWOPI / 360));
+	cos_a = cos(-angle * (TWOPI / 360));
+	a =   bbox_matrix[0][0] * cos_a + bbox_matrix[0][1] * sin_a;
+	b = - bbox_matrix[0][0] * sin_a + bbox_matrix[0][1] * cos_a;
+	c =   bbox_matrix[1][0] * cos_a + bbox_matrix[1][1] * sin_a;
+	d = - bbox_matrix[1][0] * sin_a + bbox_matrix[1][1] * cos_a;
+	bbox_matrix[0][0] = a;
+	bbox_matrix[0][1] = b;
+	bbox_matrix[1][0] = c;
+	bbox_matrix[1][1] = d;
+	bbox_rotated = (b != 0.0 || c != 0.0) ? True : False;
+	bbox_scaled
+	    = (bbox_rotated
+	       || bbox_matrix[0][0] != 1.0 || bbox_matrix[1][1] != 1.0)
+	    ? True : False;
+	if (globals.debug & DBG_PS)
+	    fprintf(stderr, "current angle %f: %s\n",
+		    bbox_matrix[0][0] != 0
+		    ? -atan(bbox_matrix[1][0] / bbox_matrix[0][0])
+		    * (360 / TWOPI)
+		    : bbox_matrix[1][0] >= 0 ? (double)90 : (double)-90,
+		    PostScript_cmd);
+    }
+
+    p = strstr(PostScript_cmd, "scale");
+    if (p != NULL) {
+	if (strncmp(p - 4, "div", 3) == 0) {
+	    while (*p != '\0' && !isdigit(*p)) --p;
+	    while (*p != '\0' && isdigit(*p)) --p;
+	    if (*p == '.') --p;
+	    while (*p != '\0' && isdigit(*p)) --p;
+	    while (*p != '\0' && !isdigit(*p)) --p;
+	    while (*p != '\0' && isdigit(*p)) --p;
+	    while (*p != '\0' && !isdigit(*p)) --p;
+	    while (*p != '\0' && isdigit(*p)) --p;
+	    if (*p == '.') --p;
+	    while (*p != '\0' && isdigit(*p)) --p;
+	    while (*p != '\0' && !isdigit(*p)) --p;
+	    while (*p != '\0' && isdigit(*p)) --p;
+	    ++p;
+	    n = sscanf(p, "1 %lf div 1 %lf div scale", &xscale, &yscale);
+	    if (n == 2) {
+#ifdef PTEX
+		if(TATE) {
+		    double temp;
+		    temp = xscale;
+		    xscale = 1.0/yscale;
+		    yscale = 1.0/temp;
+		}
+		else {
+		    xscale = 1.0/xscale;
+		    yscale = 1.0/yscale;
+		}
+#else
+		xscale = 1.0/xscale;
+		yscale = 1.0/yscale;
+#endif
+	    } else {
+		fprintf(stderr,
+			"%s:  cannot get scaling factors.\n",
+			globals.program_name);
+		xscale = yscale = 1.0;
+	    }
+	} else {
+	    while (*p != '\0' && !isdigit(*p)) --p;
+	    while (*p != '\0' && isdigit(*p)) --p;
+	    if (*p == '.') --p;
+	    while (*p != '\0' && isdigit(*p)) --p;
+	    while (*p != '\0' && !isdigit(*p)) --p;
+	    while (*p != '\0' && isdigit(*p)) --p;
+	    if (*p == '.') --p;
+	    while (*p != '\0' && isdigit(*p)) --p;
+	    if (*p != '+' && *p != '-') ++p;
+	    n = sscanf(p, "%lf %lf scale", &xscale, &yscale);
+#ifdef PTEX
+	    if(TATE) {
+		double temp;
+		temp = xscale;
+		xscale = yscale;
+		yscale = temp;
+	    }
+#endif
+	    if (n != 2) {
+		fprintf(stderr,
+			"%s:  cannot get scaling factors.\n",
+			globals.program_name);
+		xscale = yscale = 1.0;
+	    }
+	}
+	bbox_matrix[0][0] *= xscale;
+	bbox_matrix[0][1] *= yscale;
+	bbox_matrix[1][0] *= xscale;
+	bbox_matrix[1][1] *= yscale;
+	bbox_scaled
+	    = (bbox_rotated
+	       || bbox_matrix[0][0] != 1.0 || bbox_matrix[1][1] != 1.0)
+	    ? True : False;
+	if (globals.debug & DBG_PS)
+	    fprintf(stderr, "current scale %f,%f: %s\n",
+		    bbox_xscale, bbox_yscale, PostScript_cmd);
+	angle = 0.0;
+	if (strstr(PostScript_cmd, "neg rotate")) {
+	    n = sscanf(p, "%lf neg rotate", &angle);
+	    if (n != 1) {
+		fprintf(stderr, "%s:  cannot get angle. (%s)\n", globals.program_name,p);
+		angle = 0.0;
+	    }
+	}
+	bbox_angle = angle;
 	return True;
     }
     if (strstr(PostScript_cmd, " scale ") != NULL)
@@ -1477,10 +1665,10 @@ psfig_special(char *cp)
 #endif	    
 	/* also raw PostScript, but no extra colon to skip */
 #if PS
-	if (INSIDE_MANE_WIN) {
-	    if (ps_parseraw(cp))
+	if (ps_parseraw(cp) && INSIDE_MANE_WIN)
 		have_raw_postscript = True;
 	    
+	if (INSIDE_MANE_WIN) {
 	    if (psfig_begun)
 		psp.drawraw(cp);
 	    else {
@@ -2325,6 +2513,100 @@ scan_papersize(const char *cp0)
 }
 
 /*
+** Modified 22/3/95.
+*/
+
+typedef struct psh_node {
+    char *this_file;
+    struct psh_node *next;
+} t_pshnode;
+
+static t_pshnode *psh_head = (t_pshnode *) NULL, *psh_tail = (t_pshnode *) NULL;
+
+/*
+** Include one header file.
+*/
+
+static void psh_includehfile(cp, beginning)
+char *cp;
+int beginning;
+
+{
+    static char rawstring[] = " stop\n%%xdvimark\nH userdict begin\0";
+
+    if (!beginning)
+        psp.drawbegin(PXL_H - currwin.base_x, PXL_V - currwin.base_y, "");
+    psp.drawraw(rawstring);
+    send_ps_file(cp, kpse_pict_format);
+    psp.drawend(" end\n");
+}
+
+/*
+** Include all header files.
+*/
+
+void psh_includeall()
+
+{
+    t_pshnode *this_node;
+
+    this_node = psh_head;
+    while (this_node != (t_pshnode *) NULL) {
+	psh_includehfile(this_node->this_file, 1);
+	this_node = this_node->next;
+    }
+}
+
+/*
+** Deal with the "header=<file>" special.
+*/
+
+static void psh_header(cp)
+char *cp;
+
+{
+    t_pshnode *this_node;
+    char *psheader;
+
+    /*
+    ** Find the file.
+    */
+
+    psheader = kpse_find_file ( cp+7, kpse_tex_ps_header_format, true );
+
+    if (psheader) {
+
+        /*
+	** Include the file directly in /userdict.
+	*/
+
+	/* psh_includehfile(psheader, 0); */
+	/* deleted by Kazuaki NAKAYAMA (nakayama@ripms.shinshu-u.ac.jp) */
+
+	/*
+	** Add a new node to the list of header files.
+	*/
+
+	this_node = (t_pshnode *) xmalloc(sizeof(t_pshnode));
+	this_node->this_file = strcpy(xmalloc((strlen(psheader) + 1) * sizeof(char)), psheader);
+	this_node->next = (t_pshnode *) NULL;
+	if (psh_head == (t_pshnode *) NULL)
+	    psh_head = psh_tail = this_node;
+	else {
+	    psh_tail->next = this_node;
+	    psh_tail = this_node;
+	}
+
+    } else
+	XDVI_WARNING((stderr, "Included PostScript header file %s not found", cp + 7));
+}
+
+/*
+** End Modifications
+*/
+
+
+/*
  *	The following copyright message applies to the rest of this file.  --PV
  */
 
@@ -2555,6 +2837,8 @@ applicationDoSpecial(char *cp, size_t le
 	case CMD('b', 'k'):
 	    blacken_last();
 	    return;
+	case CMD('h', 'e'):
+	    psh_header(cp); return;
 	case CMD('i', 'p'):	/* throw away the path -- jansteen */
 	    path_len = 0;
 	    return;
