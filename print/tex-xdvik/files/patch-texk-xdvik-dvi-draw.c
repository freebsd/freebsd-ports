--- texk/xdvik/dvi-draw.c.orig	2013-09-01 05:55:44 UTC
+++ texk/xdvik/dvi-draw.c
@@ -56,6 +56,9 @@ in xdvi.c.
 #include "statusline.h"
 #include "hypertex.h"
 #include "special.h"
+#ifdef PTEX
+#include "ptexmap.h"
+#endif
 #include "my-snprintf.h"
 #include "kpathsea/tex-file.h"
 #include "mag.h"
@@ -531,8 +534,8 @@ print_char(ubyte ch, struct glyph *g)
 }
 
 static const char *dvi_table1[] = {
-    "SET1", "SET2", NULL, NULL, "SETRULE", "PUT1", "PUT2", NULL,
-    NULL, "PUTRULE", "NOP", "BOP", "EOP", "PUSH", "POP", "RIGHT1",
+    "SET1", "SET2", "SET3", "SET4", "SETRULE", "PUT1", "PUT2", "PUT3",
+    "PUT4", "PUTRULE", "NOP", "BOP", "EOP", "PUSH", "POP", "RIGHT1",
     "RIGHT2", "RIGHT3", "RIGHT4", "W0", "W1", "W2", "W3", "W4",
     "X0", "X1", "X2", "X3", "X4", "DOWN1", "DOWN2", "DOWN3",
     "DOWN4", "Y0", "Y1", "Y2", "Y3", "Y4", "Z0", "Z1",
@@ -542,7 +545,12 @@ static const char *dvi_table1[] = {
 static const char *dvi_table2[] = {
     "FNT1", "FNT2", "FNT3", "FNT4", "XXX1", "XXX2", "XXX3", "XXX4",
     "FNTDEF1", "FNTDEF2", "FNTDEF3", "FNTDEF4", "PRE", "POST", "POSTPOST",
-    "SREFL", "EREFL", NULL, NULL, NULL, NULL
+    "SREFL", "EREFL", NULL, NULL, NULL,
+#ifdef PTEX
+    "DIRECTION"
+#else /* !PTEX */
+    NULL
+#endif /* !PTEX */
 };
 
 static void
@@ -667,6 +675,146 @@ sample(bmUnitT *bits, int bytes_wide, in
     return n;
 }
 
+extern	double	bbox_matrix[2][2];
+extern	Boolean	bbox_scaled, bbox_rotated;
+
+static void moveH(int dir, long dx)
+{
+  int pint=TATE;
+  if (pint&2) { pint&=1; dx=-dx;}
+  if (pint) {
+    DVI_H -= dx * bbox_matrix[1][0];
+    DVI_V += dx * bbox_matrix[0][0];
+  } else {
+    DVI_H += dir * dx * bbox_matrix[0][0];
+    DVI_V += dir * dx * bbox_matrix[1][0];
+  }
+  PXL_V = pixel_conv(DVI_V);
+}
+
+static void moveV(int dir, long dy)
+{
+  int pint=TATE;
+  if (pint&2) { pint&=1; dy=-dy;}
+  if (pint) {
+    DVI_H -= dy * bbox_matrix[1][1];
+    DVI_V += dy * bbox_matrix[0][1];
+  } else {
+    DVI_H += dir * dy * bbox_matrix[0][1];
+    DVI_V += dir * dy * bbox_matrix[1][1];
+  }
+  PXL_V = pixel_conv(DVI_V);
+}
+
+#define PUSH_POSITION do { \
+	dvi_h_sav = DVI_H; \
+	dvi_v_sav = DVI_V; \
+	pxl_v_sav = PXL_V; } while (0)
+#define POP_POSITION do { \
+	DVI_H = dvi_h_sav; \
+	DVI_V = dvi_v_sav; \
+	PXL_V = pxl_v_sav; } while (0)
+#define DEFINE_POSITION_VAL \
+	long dvi_h_sav, dvi_v_sav, pxl_v_sav
+
+#ifndef   WORDS_BIGENDIAN
+#define EXTREME_LEFT_BIT   (1 << 0)
+#define EXTREME_RIGHT_BIT  ((bmUnitT)(1 << (BMBITS-1)))
+#define SHIFT_RIGHT(a)     ((a) <<= 1)
+#else  /* WORDS_BIGENDIAN */
+#define EXTREME_LEFT_BIT   ((bmUnitT)(1 << (BMBITS-1)))
+#define EXTREME_RIGHT_BIT  (1 << 0)
+#define SHIFT_RIGHT(a)     ((a) >>= 1)
+#endif /* WORDS_BIGENDIAN */
+
+static	void
+bbox_scale_bitmap(struct glyph *g)
+{
+    bmUnitT *new_ptr;
+    int xmax, ymax, xmin, ymin, x, y;
+    double d;
+ 
+    if (g->bitmap3.bits) {
+	if (g->matrix[0][0] == (float) bbox_matrix[0][0]
+	    && g->matrix[0][1] == (float) bbox_matrix[0][1]
+	    && g->matrix[1][0] == (float) bbox_matrix[1][0]
+	    && g->matrix[1][1] == (float) bbox_matrix[1][1])
+	    return;
+	else
+	    free(g->bitmap.bits);
+    } else {
+	g->bitmap3 = g->bitmap;
+	g->x3 = g->x;
+	g->y3 = g->y;
+    }
+
+    xmax = ymax = xmin = ymin = 0;
+    x = g->bitmap3.w * bbox_matrix[0][0];
+    y = g->bitmap3.w * bbox_matrix[1][0];
+    if (xmax < x) xmax = x;
+    else if (xmin > x) xmin = x;
+    if (ymax < y) ymax = y;
+    else if (ymin > y) ymin = y;
+    x = g->bitmap3.w * bbox_matrix[0][0] + g->bitmap3.h * bbox_matrix[0][1];
+    y = g->bitmap3.w * bbox_matrix[1][0] + g->bitmap3.h * bbox_matrix[1][1];
+    if (xmax < x) xmax = x;
+    else if (xmin > x) xmin = x;
+    if (ymax < y) ymax = y;
+    else if (ymin > y) ymin = y;
+    x = g->bitmap3.h * bbox_matrix[0][1];
+    y = g->bitmap3.h * bbox_matrix[1][1];
+    if (xmax < x) xmax = x;
+    else if (xmin > x) xmin = x;
+    if (ymax < y) ymax = y;
+    else if (ymin > y) ymin = y;
+    xmin--; ymin--; xmax++; ymax++;
+
+    d = bbox_matrix[0][0] * bbox_matrix[1][1]
+	- bbox_matrix[0][1] * bbox_matrix[1][0];
+
+    g->x = g->x3 * bbox_matrix[0][0] + g->y3 * bbox_matrix[0][1] - xmin;
+    g->y = g->x3 * bbox_matrix[1][0] + g->y3 * bbox_matrix[1][1] - ymin;
+    g->matrix[0][0] = (float) bbox_matrix[0][0];
+    g->matrix[0][1] = (float) bbox_matrix[0][1];
+    g->matrix[1][0] = (float) bbox_matrix[1][0];
+    g->matrix[1][1] = (float) bbox_matrix[1][1];
+
+    free_bitmap2(g);
+    g->bitmap.w = xmax - xmin + 1;
+    g->bitmap.h = ymax - ymin + 1;
+    alloc_bitmap(&g->bitmap);
+    clear_bitmap(&g->bitmap);
+
+    new_ptr = (bmUnitT *) g->bitmap.bits;
+    for (y = ymin; y <= ymax; y++) {
+	register bmUnitT m, *cp;
+
+	cp = new_ptr;
+	m = EXTREME_LEFT_BIT;
+	for (x = xmin; x <= xmax; x++) {
+	    int bx, by;
+	    bx = (x * bbox_matrix[1][1] - y * bbox_matrix[0][1]) / d;
+	    by = (y * bbox_matrix[0][0] - x * bbox_matrix[1][0]) / d;
+	    if (bx >= 0 && bx < g->bitmap3.w
+		&& by >= 0 && by < g->bitmap3.h
+		&& *((bmUnitT *)g->bitmap3.bits
+		     + by * (g->bitmap3.bytes_wide / BMBYTES) + bx / BMBITS)
+#ifndef	WORDS_BIGENDIAN
+		& (1 << (bx % BMBITS)))
+#else
+		& (1 << (BMBITS - 1 - bx % BMBITS)))
+#endif
+		    *cp |= m;
+	    if (m == EXTREME_RIGHT_BIT) {
+		m = EXTREME_LEFT_BIT;
+		++cp;
+	    }
+	    else SHIFT_RIGHT(m);
+	}
+	new_ptr = ADD(new_ptr, g->bitmap.bytes_wide);
+    }
+}
+
 static void
 shrink_glyph(struct glyph *g)
 {
@@ -757,6 +905,89 @@ shrink_glyph(struct glyph *g)
 	print_bitmap(&g->bitmap2);
 }
 
+#ifdef PTEX
+void
+rotate_bitmap(struct bitmap *bm)
+{
+      struct bitmap new_bm;
+      bmUnitT *old_ptr, *new_ptr, *cp;
+      int    x, y;
+      bmUnitT m1, m2;
+ 
+      new_bm.h = bm->w;
+      new_bm.w = bm->h;
+      alloc_bitmap(&new_bm);
+      clear_bitmap(&new_bm);
+      old_ptr = ADD(bm->bits, bm->bytes_wide * bm->h);
+      new_ptr = (bmUnitT *)new_bm.bits;
+
+      m1 = EXTREME_LEFT_BIT;
+      for (y = 0; y < bm->h; y++) {
+	old_ptr = SUB(old_ptr, bm->bytes_wide);
+	cp = old_ptr;
+	m2 = EXTREME_LEFT_BIT;
+	for (x = 0; x < bm->w; x++) {
+	  if (*cp & m2)
+	    *ADD(new_ptr, x*new_bm.bytes_wide) |= m1;
+	  if (m2 == EXTREME_RIGHT_BIT) {
+	    m2 = EXTREME_LEFT_BIT;
+	    ++cp;
+	  }
+	  else SHIFT_RIGHT(m2);
+	}
+	if (m1 == EXTREME_RIGHT_BIT) {
+	  m1 = EXTREME_LEFT_BIT;
+	  ++new_ptr;
+	}
+	else SHIFT_RIGHT(m1);
+      }
+
+      free(bm->bits);
+      *bm = new_bm;
+}
+
+
+void
+reverse_rotate_bitmap(struct bitmap *bm)
+{
+      struct bitmap new_bm;
+      bmUnitT *old_ptr, *new_ptr, *cp;
+      int    x, y;
+      bmUnitT m1, m2;
+
+      new_bm.h = bm->w;
+      new_bm.w = bm->h;
+      alloc_bitmap(&new_bm);
+      clear_bitmap(&new_bm);
+      old_ptr = (bmUnitT *)bm->bits;
+      new_ptr = (bmUnitT *)new_bm.bits;
+
+      m1 = EXTREME_LEFT_BIT;
+      for (y = 0; y < bm->h; y++) {
+	cp = old_ptr;
+	old_ptr = ADD(old_ptr, bm->bytes_wide);
+	m2 = EXTREME_LEFT_BIT;
+	for (x = bm->w; x--;) {
+	  if (*cp & m2)
+	    *ADD(new_ptr, x * new_bm.bytes_wide) |= m1;
+	  if (m2 == EXTREME_RIGHT_BIT) {
+	    m2 = EXTREME_LEFT_BIT;
+	    ++cp;
+	  }
+	  else SHIFT_RIGHT(m2);
+	}
+	if (m1 == EXTREME_RIGHT_BIT) {
+	  m1 = EXTREME_LEFT_BIT;
+	  ++new_ptr;
+	}
+	else SHIFT_RIGHT(m1);
+      }
+
+      free(bm->bits);
+      *bm = new_bm;
+}
+#endif /* PTEX */
+
 #ifdef	GREY
 
 #ifdef RGB_ANTI_ALIASING
@@ -970,6 +1201,7 @@ shrink_glyph_grey(struct glyph *g)
 				 BMBITS, 0);
 	size = g->image2->bytes_per_line * g->bitmap2.h;
 	g->pixmap2 = g->image2->data = xmalloc(size != 0 ? size : 1);
+	ASSERT(g->pixmap2_gc2 == NULL, "pixmap2_gc2 is not NULL.");
     }
     /* ... and the pixmap used for globals.gc.fore2: */
     if (globals.gc.fore2 != NULL && g->pixmap2_gc2 == NULL) {
@@ -1283,8 +1515,13 @@ static ubyte scantable[256] = {
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     1, 2,	/* SET1,SET2 (128,129) */
-    /* -,-,SETRULE,PUT1,PUT2,-,-,PUTRULE,NOP,BOP (130-139) */
+#ifdef PTEX
+    /* SET3,SET4,SETRULE,PUT1,PUT2,PUT3,PUT4,PUTRULE,NOP,BOP (130-139) */
+    3, 4, 8, 1, 2, 3, 4, 8, 0, 44,
+#else
+    /* -,-,SETRULE,PUT1,PUT2,-,-,PUTRULE,NOP,BOP (132-139) */
     M4, M4, 8, 1, 2, M4, M4, 8, 0, 44,
+#endif
     M1, 0, 0, 1, 2, 3, 4, 0, 1, 2,	/* EOP,PUSH,POP,RIGHT1-4,W0M2 (140-149) */
     3, 4, 0, 1, 2, 3, 4, 1, 2, 3,	/* W3-4,X0-4,DOWN1-3 (150-159) */
     4, 0, 1, 2, 3, 4, 0, 1, 2, 3,	/* DOWN4,Y0-4,Z0-3 (160-169) */
@@ -1337,9 +1574,11 @@ spcl_scan(Boolean (*spcl_proc)(char *str
 		ch = xone(fp);
 		xskip(fp, (long)ch + (long)xone(fp));
 		break;
+#ifndef PTEX
 	    case M4:	/* unrecognizable */
 		XDVI_FATAL((stderr, "unknown op-code %d", ch));
 		break;
+#endif /* !PTEX */
 	    case M5:	/* doesn't belong */
 		dvi_fmt_error("spcl_scan: shouldn't happen: %s encountered",
 			      dvi_table2[ch - (FNTNUM0 + 64)]);
@@ -1453,6 +1692,46 @@ prescan(FILE *fp)
  *	Routines to print characters.
  */
 
+#ifdef PTEX
+static void
+set_char_rotate_glyph(struct glyph *g)
+{
+  int tmp, rot = TATE - g->tdir;
+  if (rot<0) rot+=4;
+  switch(rot) {
+  case 2:
+    rotate_bitmap(&g->bitmap);
+    tmp = g->x;
+    g->x = g->bitmap.w - g->y;
+    g->y = tmp;
+    g->tdir = TATE;
+    free_bitmap2(g);
+  case 1:
+    rotate_bitmap(&g->bitmap);
+    tmp = g->x;
+    g->x = g->bitmap.w - g->y;
+    g->y = tmp;
+    g->tdir = TATE;
+    free_bitmap2(g);
+    break;
+  case 3:
+    reverse_rotate_bitmap(&g->bitmap);
+    tmp = g->x;
+    g->x = g->y;
+    g->y = g->bitmap.h - tmp;
+    g->tdir = TATE;
+    free_bitmap2(g);
+  }
+}
+#endif /* PTEX */
+
+static setcharRetvalT
+common_set_char(
+#ifdef TEXXET
+		wide_ubyte,
+#endif
+		struct glyph *);
+
 setcharRetvalT
 set_char(
 #ifdef TEXXET
@@ -1461,9 +1740,6 @@ set_char(
 	 wide_ubyte ch)
 {
     struct glyph *g;
-#ifdef TEXXET
-    long dvi_h_sav;
-#endif
 
     if (ch > maxchar)
 	realloc_font(currinf.fontp, (wide_ubyte)ch);
@@ -1497,14 +1773,41 @@ set_char(
 	    print_char((ubyte) ch, g);
 	currinf.fontp->timestamp = ++current_timestamp;
     }
+#ifdef PTEX
+    set_char_rotate_glyph(g);
+#endif /* PTEX */
+#ifdef TEXXET
+    common_set_char(cmd, g);
+#else
+    return common_set_char(g);
+#endif
+}
 
+static setcharRetvalT
+common_set_char(
 #ifdef TEXXET
-    dvi_h_sav = DVI_H;
-    if (currinf.dir < 0)
-	DVI_H -= g->dvi_adv;
+		wide_ubyte cmd,
+#endif
+		struct glyph *g)
+{
+#ifdef	TEXXET
+    DEFINE_POSITION_VAL;
+    PUSH_POSITION;
+    if (! TATE && currinf.dir < 0)
+	moveH(1, -g->dvi_adv);
 
     if (scan_frame == NULL) {
 #endif
+	if (bbox_scaled)
+	    bbox_scale_bitmap(g);
+	else if (g->bitmap3.bits) {
+	    free(g->bitmap.bits);
+	    g->bitmap = g->bitmap3;
+	    g->bitmap3.bits = NULL;
+	    g->x = g->x3;
+	    g->y = g->y3;
+	    free_bitmap2(g);
+	}
 	
 #ifdef RGB_ANTI_ALIASING
 	if (currwin.shrinkfactor == -1) {
@@ -1546,9 +1849,9 @@ set_char(
 #ifdef TEXXET
     }
     if (cmd == PUT1 || (resource.omega && cmd == PUT2))
-	DVI_H = dvi_h_sav;
-    else if (currinf.dir > 0)
-	DVI_H += g->dvi_adv;
+	POP_POSITION;
+    else if (TATE || currinf.dir > 0)
+	moveH(1, g->dvi_adv);
     return;
 #else
     return g->dvi_adv;
@@ -1603,6 +1906,33 @@ set_empty_char(
 #endif
 }
 
+#ifdef PTEX
+setcharRetvalT
+set_char2(
+#ifdef TEXXET
+	 wide_ubyte cmd,
+#endif
+	 wide_ubyte ch)
+{
+    struct glyph *g;
+
+    if (ch > currinf.fontp->maxchar ||
+	(g = currinf.fontp->kglyph[ch]) == NULL || g->bitmap.bits == NULL) {
+	(*currinf.fontp->read_char)(currinf.fontp, ch);
+	g = currinf.fontp->kglyph[ch];
+	free_bitmap2(g);
+	g->tdir = currinf.fontp->dir;
+	if (globals.debug & DBG_BITMAP) print_char((ubyte) ch, g);
+    }
+    set_char_rotate_glyph(g);
+#ifdef TEXXET
+    common_set_char(cmd, g);
+#else
+    return common_set_char(g);
+#endif
+}
+#endif /* PTEX */
+
 setcharRetvalT
 load_n_set_char(
 #ifdef TEXXET
@@ -1650,7 +1980,7 @@ set_vf_char(
     wide_ubyte oldmaxchar;
     static ubyte c;
 #ifdef TEXXET
-    long dvi_h_sav;
+    DEFINE_POSITION_VAL;
 #endif
 
     if (ch > maxchar)
@@ -1666,9 +1996,9 @@ set_vf_char(
 #endif
     }
 #ifdef TEXXET
-    dvi_h_sav = DVI_H;
-    if (currinf.dir < 0)
-	DVI_H -= m->dvi_adv;
+    PUSH_POSITION;
+    if (! TATE && currinf.dir < 0)
+	moveH(1, -m->dvi_adv);
     if (scan_frame == NULL) {
 #endif
 	oldinfo = currinf;
@@ -1693,9 +2023,9 @@ set_vf_char(
 #ifdef TEXXET
     }
     if (cmd == PUT1 || (resource.omega && cmd == PUT2))
-	DVI_H = dvi_h_sav;
-    else if (currinf.dir > 0)
-	DVI_H += m->dvi_adv;
+	POP_POSITION;
+    else if (TATE || currinf.dir > 0)
+	moveH(1, m->dvi_adv);
     return;
 #else
     return m->dvi_adv;
@@ -1813,9 +2143,64 @@ set_no_char(
  *	Set rule.  Arguments are coordinates of lower left corner.
  */
 
+static	void
+set_rotated_rule(long h, long w)
+{
+    XPoint points[4];
+    int pint = TATE;
+    if (pint&2) { pint&=1;
+      w=-w; h=-h;
+    }
+    points[0].x = PXL_H - currwin.base_x;
+    points[0].y = PXL_V - currwin.base_y;
+#ifdef PTEX
+    if (pint) {
+	points[1].x = -w * bbox_matrix[1][0];
+	points[1].y = w * bbox_matrix[0][0];
+	points[2].x = h * bbox_matrix[1][1];
+	points[2].y = -h * bbox_matrix[0][1];
+    } else
+#endif /* PTEX */
+    {
+	points[1].x = DIR * w * bbox_matrix[0][0];
+	points[1].y = DIR * w * bbox_matrix[1][0];
+	points[2].x = -h * bbox_matrix[0][1];
+	points[2].y = -h * bbox_matrix[1][1];
+    }
+    points[3].x = -points[1].x;
+    points[3].y = -points[1].y;
+
+    if (--globals.ev.ctr == 0) {
+	if (read_events(EV_NOWAIT) & EV_GE_MAG_GONE) {
+	    /* fprintf(stderr, "longjmp1!\n"); */
+	    longjmp(globals.ev.canit, 1);
+	}
+    }
+#if COLOR
+    if (fg_active != fg_current)
+	do_color_change();
+#endif
+    XFillPolygon(DISP, currwin.win,
+		 htex_inside_href ? globals.gc.high: globals.gc.rule,
+		 points, 4, Convex, CoordModePrevious);
+}
+
 static void
 set_rule(int h, int w)
 {
+    if (bbox_rotated) {
+	set_rotated_rule(h, w);
+	return;
+    }
+    h = h * bbox_matrix[1][1];
+    w = w * bbox_matrix[0][0];
+#ifdef PTEX
+    if (TATE==1)
+	put_rule(PXL_H, PXL_V, (unsigned int)h, (unsigned int)w);
+    else if (TATE==3) /* dtou */
+	put_rule(PXL_H - h + 1, PXL_V - w + 1, (unsigned int)h, (unsigned int)w);
+    else
+#endif /* PTEX */
 #ifdef TEXXET
     put_rule(PXL_H - (currinf.dir < 0 ? w - 1 : 0), PXL_V - h + 1,
 	     (unsigned int)w, (unsigned int)h);
@@ -1860,7 +2245,7 @@ draw_part(FILE *fp, struct frame *minfra
 #ifdef TEXXET
 	    (*currinf.set_char_p) (ch, ch);
 #else
-	    DVI_H += (*currinf.set_char_p) (ch);
+	    moveH(1, (*currinf.set_char_p) (ch));
 #endif
 	}
 	else if (FNTNUM0 <= ch && ch <= (ubyte) (FNTNUM0 + 63)) {
@@ -1877,7 +2262,7 @@ draw_part(FILE *fp, struct frame *minfra
 #else
 		a = (*currinf.set_char_p) (xone(fp));
 		if (ch != PUT1)
-		    DVI_H += a;
+		    moveH(1, a);
 #endif
 		break;
 
@@ -1892,7 +2277,39 @@ draw_part(FILE *fp, struct frame *minfra
 #else
 		    a = (*currinf.set_char_p) (xnum(fp, 2));
 		    if (ch != PUT2)
-			DVI_H += a;
+			moveH(1, a);
+#endif
+		}
+		break;
+
+	    case SET3:
+	    case PUT3:
+		if (!resource.omega)
+		    dvi_fmt_error("%s:%d: draw_part: op-code %d only works with the \"-omega\" option",
+				  __FILE__, __LINE__, ch);
+		else {
+#ifdef TEXXET
+		    (*currinf.set_char_p) (ch, xnum(fp, 3));
+#else
+		    a = (*currinf.set_char_p) (xnum(fp, 3));
+		    if (ch != PUT3)
+			moveH(1, a);
+#endif
+		}
+		break;
+
+	    case SET4:
+	    case PUT4:
+		if (!resource.omega)
+		    dvi_fmt_error("%s:%d: draw_part: op-code %d only works with the \"-omega\" option",
+				  __FILE__, __LINE__, ch);
+		else {
+#ifdef TEXXET
+		    (*currinf.set_char_p) (ch, xnum(fp, 4));
+#else
+		    a = (*currinf.set_char_p) (xnum(fp, 4));
+		    if (ch != PUT4)
+			moveH(1, a);
 #endif
 		}
 		break;
@@ -1910,7 +2327,7 @@ draw_part(FILE *fp, struct frame *minfra
 		    ) {
 		    set_rule(pixel_round(xspell_conv(a)), pixel_round(b));
 		}
-		DVI_H += DIR * b;
+		moveH(DIR, b);
 		break;
 
 	    case PUTRULE:
@@ -1934,6 +2351,9 @@ draw_part(FILE *fp, struct frame *minfra
 		DVI_V = OFFSET_Y;
 		PXL_V = pixel_conv(DVI_V);
 		WW = XX = YY = ZZ = 0;
+		bbox_matrix[0][0] = bbox_matrix[1][1] = 1.0;
+		bbox_matrix[0][1] = bbox_matrix[1][0] = 0.0;
+		bbox_scaled = bbox_rotated = False;
 		break;
 
 	    case EOP:
@@ -2028,7 +2448,7 @@ draw_part(FILE *fp, struct frame *minfra
 	    case RIGHT2:
 	    case RIGHT3:
 	    case RIGHT4:
-		DVI_H += DIR * xspell_conv(xsnum(fp, ch - RIGHT1 + 1));
+		moveH(DIR, xspell_conv(xsnum(fp, ch - RIGHT1 + 1)));
 		break;
 
 	    case W1:
@@ -2037,7 +2457,7 @@ draw_part(FILE *fp, struct frame *minfra
 	    case W4:
 		WW = xspell_conv(xsnum(fp, ch - W0));
 	    case W0:
-		DVI_H += DIR * WW;
+		moveH(DIR, WW);
 		break;
 
 	    case X1:
@@ -2046,15 +2466,14 @@ draw_part(FILE *fp, struct frame *minfra
 	    case X4:
 		XX = xspell_conv(xsnum(fp, ch - X0));
 	    case X0:
-		DVI_H += DIR * XX;
+		moveH(DIR, XX);
 		break;
 
 	    case DOWN1:
 	    case DOWN2:
 	    case DOWN3:
 	    case DOWN4:
-		DVI_V += xspell_conv(xsnum(fp, ch - DOWN1 + 1));
-		PXL_V = pixel_conv(DVI_V);
+		moveV(1, xspell_conv(xsnum(fp, ch - DOWN1 + 1)));
 		break;
 
 	    case Y1:
@@ -2063,8 +2482,7 @@ draw_part(FILE *fp, struct frame *minfra
 	    case Y4:
 		YY = xspell_conv(xsnum(fp, ch - Y0));
 	    case Y0:
-		DVI_V += YY;
-		PXL_V = pixel_conv(DVI_V);
+		moveV(1, YY);
 		break;
 
 	    case Z1:
@@ -2073,8 +2491,7 @@ draw_part(FILE *fp, struct frame *minfra
 	    case Z4:
 		ZZ = xspell_conv(xsnum(fp, ch - Z0));
 	    case Z0:
-		DVI_V += ZZ;
-		PXL_V = pixel_conv(DVI_V);
+		moveV(1, ZZ);
 		break;
 
 	    case FNT1:
@@ -2121,6 +2538,11 @@ draw_part(FILE *fp, struct frame *minfra
 		dvi_fmt_error("%s:%d: draw_part: shouldn't happen: %s encountered",
 			      __FILE__, __LINE__, dvi_table2[ch - (FNTNUM0 + 64)]);
 		break;
+#ifdef PTEX
+	    case TDIR:
+		TATE = xone(fp);
+		break;
+#endif /* PTEX */
 
 	    default:
 		dvi_fmt_error("%s:%d: draw_part: unknown op-code %d", __FILE__, __LINE__, ch);
@@ -2311,7 +2733,7 @@ draw_page(void)
     psp.endpage();
 #endif
     if (currwin.win == mane.win && resource.postscript != 1) {
-	display_bboxes();
+       display_bboxes();
     }
     if (search_have_match(current_page)) {
 	/* highlight search match */
@@ -2921,7 +3343,15 @@ do_char(wide_ubyte ch,
     last_dvi_h1 = DVI_H;
     last_u_glyph = u_glyph;
     last_pxl_v = pxl_v1;
+#ifdef PTEX
+    if (currinf.fontp->flags & FONT_KANJI) {
+    last_dvi_h2 = DVI_H + currinf.fontp->kglyph[ch]->dvi_adv;
+    } else {
+#endif /* PTEX */
     last_dvi_h2 = DVI_H + currinf.fontp->glyph[ch].dvi_adv;
+#ifdef PTEX
+    }
+#endif /* PTEX */
     last_x = x2;
 }
 
@@ -2935,6 +3365,10 @@ text_do_char(FILE *fp, struct scan_info 
 	    return 0;	/* error; we'll catch it later */
 	maxchar = currinf.fontp->maxchar;
 	currinf.set_char_p = currinf.fontp->set_char_p;
+#if FREETYPE
+        if (currinf.set_char_p == set_ft_char)
+	    do_load_freetype_font();
+#endif
     }
 
     if (currinf.set_char_p == set_empty_char)
@@ -2962,10 +3396,6 @@ text_do_char(FILE *fp, struct scan_info 
 	}
 	maxchar = currinf.fontp->maxchar;
 	currinf.set_char_p = currinf.fontp->set_char_p;
-#if FREETYPE
-	if (currinf.set_char_p == set_ft_char)
-	    do_load_freetype_font();
-#endif
     }
 
     if (currinf.set_char_p == set_char) {
@@ -2993,25 +3423,56 @@ text_do_char(FILE *fp, struct scan_info 
 	}
 #ifdef TEXXET
 	if (geom_scan_frame == NULL) {
-	    long dvi_h_sav = DVI_H;
-	    if (currinf.dir < 0)
-		DVI_H -= g->dvi_adv;
+	    DEFINE_POSITION_VAL;
+	    PUSH_POSITION;
+	    if (! TATE && currinf.dir < 0)
+		moveH(1, -g->dvi_adv);
 #endif
 	    x = G_PXL_H - g->x;
 	    y = PXL_V - g->y;
 	    do_char(ch, currinf, info, PXL_V, y, x, x + g->bitmap.w - 1, g);
 #ifdef TEXXET
-	    DVI_H = dvi_h_sav;
+	    POP_POSITION;
+	}
+#endif
+	return DIR * g->dvi_adv;
+    }
+#ifdef PTEX
+    else if (currinf.set_char_p == set_char2) {
+	struct glyph *g;
+	long x, y;
+
+	g = currinf.fontp->kglyph[ch];
+	if (g == NULL || g->bitmap.bits == NULL) {
+	    (*currinf.fontp->read_char)(currinf.fontp, ch);
+	    g = currinf.fontp->kglyph[ch];
+	    free_bitmap2(g);
+	    g->tdir = currinf.fontp->dir;
+	}
+
+#ifdef TEXXET
+	if (geom_scan_frame == NULL) {
+	    DEFINE_POSITION_VAL;
+	    PUSH_POSITION;
+	    if (! TATE && currinf.dir < 0)
+		moveH(1, -g->dvi_adv);
+#endif
+	    x = G_PXL_H - g->x;
+	    y = PXL_V - g->y;
+	    do_char(ch, currinf, info, PXL_V, y, x, x + g->bitmap.w - 1, g);
+#ifdef TEXXET
+	    POP_POSITION;
 	}
 #endif
 	return DIR * g->dvi_adv;
     }
+#endif /* PTEX */
     else if (currinf.set_char_p == set_vf_char) {
 	struct macro *m;
 	struct drawinf oldinfo;
 	wide_ubyte oldmaxchar;
 #ifdef TEXXET
-	long dvi_h_sav;
+	DEFINE_POSITION_VAL;
 #endif
 
 	if (ch > maxchar)
@@ -3019,9 +3480,9 @@ text_do_char(FILE *fp, struct scan_info 
 	if ((m = &currinf.fontp->macro[ch])->pos == NULL)
 	    return 0;	/* catch the error later */
 #ifdef TEXXET
-	dvi_h_sav = DVI_H;
-	if (currinf.dir < 0)
-	    DVI_H -= m->dvi_adv;
+	PUSH_POSITION;
+	if (! TATE && currinf.dir < 0)
+	    moveH(1, -m->dvi_adv);
 	if (geom_scan_frame == NULL) {
 #endif
 	    oldinfo = currinf;
@@ -3037,7 +3498,7 @@ text_do_char(FILE *fp, struct scan_info 
 	    currinf = oldinfo;
 	    maxchar = oldmaxchar;
 #ifdef TEXXET
-	    DVI_H = dvi_h_sav;
+	    POP_POSITION;
 	}
 #endif
 	return DIR * m->dvi_adv;
@@ -3049,6 +3510,11 @@ text_do_char(FILE *fp, struct scan_info 
     return 0;
 }
 
+#define xmoveH(dir,dx)   \
+	do { moveH(dir,dx); PXL_V = xpixel_conv(DVI_V); } while(0)
+#define xmoveV(dir,dy)   \
+	do { moveV(dir,dy); PXL_V = xpixel_conv(DVI_V); } while(0)
+
 /*
  *	Handle a character in geometric scanning routine.
  */
@@ -3064,6 +3530,10 @@ geom_do_char(FILE *fp, struct scan_info 
 	    return 0;	/* error; we'll catch it later */
 	maxchar = currinf.fontp->maxchar;
 	currinf.set_char_p = currinf.fontp->set_char_p;
+#if FREETYPE
+        if (currinf.set_char_p == set_ft_char)
+	    do_load_freetype_font();
+#endif
     }
 
     if (currinf.set_char_p == set_empty_char)
@@ -3091,10 +3561,6 @@ geom_do_char(FILE *fp, struct scan_info 
 	}
 	maxchar = currinf.fontp->maxchar;
 	currinf.set_char_p = currinf.fontp->set_char_p;
-#if FREETYPE
-	if (currinf.set_char_p == set_ft_char)
-	    do_load_freetype_font();
-#endif
     }
 
     if (currinf.set_char_p == set_char) {
@@ -3122,27 +3588,58 @@ geom_do_char(FILE *fp, struct scan_info 
 	}
 #ifdef TEXXET
 	if (geom_scan_frame == NULL) {
-	    long dvi_h_sav = DVI_H;
-	    if (currinf.dir < 0)
-		DVI_H -= g->dvi_adv;
+	    DEFINE_POSITION_VAL;
+	    PUSH_POSITION;
+	    if (! TATE && currinf.dir < 0)
+		moveH(1, -g->dvi_adv);
 #endif
 	    x = G_PXL_H - g->x;
 	    y = PXL_V - g->y;
 	    g_info->geom_box(info, x, y,
 			     x + g->bitmap.w - 1, y + g->bitmap.h - 1);
+#ifdef TEXXET
+	    POP_POSITION;
+	}
+#endif
+	return DIR * g->dvi_adv;
+    }
+#ifdef PTEX
+    else if (currinf.set_char_p == set_char2) {
+	struct glyph *g;
+	long x, y;
+
+	g = currinf.fontp->kglyph[ch];
+	if (g == NULL || g->bitmap.bits == NULL) {
+	    (*currinf.fontp->read_char)(currinf.fontp, ch);
+	    g = currinf.fontp->kglyph[ch];
+	    free_bitmap2(g);
+	    g->tdir = currinf.fontp->dir;
+	}
 
 #ifdef TEXXET
-	    DVI_H = dvi_h_sav;
+	if (geom_scan_frame == NULL) {
+	    DEFINE_POSITION_VAL;
+	    PUSH_POSITION;
+	    if (! TATE && currinf.dir < 0)
+		moveH(1, -g->dvi_adv);
+#endif
+	    x = G_PXL_H - g->x;
+	    y = PXL_V - g->y;
+	    g_info->geom_box(info, x, y,
+			     x + g->bitmap.w - 1, y + g->bitmap.h - 1);
+#ifdef TEXXET
+	    POP_POSITION;
 	}
 #endif
 	return DIR * g->dvi_adv;
     }
+#endif /* PTEX */
     else if (currinf.set_char_p == set_vf_char) {
 	struct macro *m;
 	struct drawinf oldinfo;
 	wide_ubyte oldmaxchar;
 #ifdef TEXXET
-	long dvi_h_sav;
+	DEFINE_POSITION_VAL;
 #endif
 
 	if (ch > maxchar)
@@ -3150,9 +3647,9 @@ geom_do_char(FILE *fp, struct scan_info 
 	if ((m = &currinf.fontp->macro[ch])->pos == NULL)
 	    return 0;	/* catch the error later */
 #ifdef TEXXET
-	dvi_h_sav = DVI_H;
-	if (currinf.dir < 0)
-	    DVI_H -= m->dvi_adv;
+	PUSH_POSITION;
+	if (! TATE && currinf.dir < 0)
+	    moveH(1, -m->dvi_adv);
 	if (geom_scan_frame == NULL) {
 #endif
 	    oldinfo = currinf;
@@ -3168,7 +3665,7 @@ geom_do_char(FILE *fp, struct scan_info 
 	    currinf = oldinfo;
 	    maxchar = oldmaxchar;
 #ifdef TEXXET
-	    DVI_H = dvi_h_sav;
+	    POP_POSITION;
 	}
 #endif
 	return DIR * m->dvi_adv;
@@ -3188,21 +3685,35 @@ static void
 geom_do_rule(struct scan_info *info, long h, long w)
 {
     long x, y;
+    struct geom_info *g_info = info->data;
 #ifdef TEXXET
-    long dvi_h_save = DVI_H;
+    DEFINE_POSITION_VAL;
+    PUSH_POSITION;
 #endif
-    struct geom_info *g_info = info->data;
-    
+
+    if (bbox_rotated) {
+	fprintf(stderr, "geom_do_rotated_rule(h, w) is not implemented!\n");
+	return;
+    }
+    h = h * bbox_matrix[1][1];
+    w = w * bbox_matrix[0][0];
+
 #ifdef TEXXET
-    if (currinf.dir < 0)
-	DVI_H -= w - 1;
+    if (! TATE && currinf.dir < 0)
+	moveH(1, - w + 1);
 #endif
     x = G_PXL_H;
     y = PXL_V;
+#ifdef PTEX
+    if (TATE)
+	g_info->geom_box(info, x, y, x + xpixel_round(h) - 1,
+			 y + xpixel_round(w) - 1);
+    else
+#endif /* PTEX */
     g_info->geom_box(info, x, y - xpixel_round(h) + 1,
 		     x + xpixel_round(w) - 1, y);
 #ifdef TEXXET
-    DVI_H = dvi_h_save;
+    POP_POSITION;
 #endif
 }
 
@@ -3232,7 +3743,7 @@ geom_scan_part(long(*char_proc)(FILE *, 
     for (;;) {
 	ch = xone(fp);
 	if (ch <= (ubyte)(SETCHAR0 + 127))
-	    DVI_H += char_proc(fp, info, ch);
+	    xmoveH(1, char_proc(fp, info, ch));
 	else if (FNTNUM0 <= ch && ch <= (ubyte) (FNTNUM0 + 63)) {
 	    change_font((unsigned long)(ch - FNTNUM0));
 	}
@@ -3244,7 +3755,7 @@ geom_scan_part(long(*char_proc)(FILE *, 
 	    case PUT1:
 		a = char_proc(fp, info, xone(fp));
 		if (ch != PUT1)
-		    DVI_H += a;
+		    xmoveH(1, a);
 		break;
 
 	    case SET2:
@@ -3258,7 +3769,39 @@ geom_scan_part(long(*char_proc)(FILE *, 
 #else
 		    a = char_proc(fp, info, xnum(fp, 2));
 		    if (ch != PUT2)
-			DVI_H += a;
+			xmoveH(1, a);
+#endif
+		}
+		break;
+
+	    case SET3:
+	    case PUT3:
+		if (!resource.omega)
+		    dvi_fmt_error("%s:%d: draw_part: op-code %d only works with the \"-omega\" option",
+				  __FILE__, __LINE__, ch);
+		else {
+#ifdef TEXXET
+		    char_proc(fp, info, xnum(fp, 3));
+#else
+		    a = char_proc(fp, info, xnum(fp, 3));
+		    if (ch != PUT3)
+			xmoveH(1, a);
+#endif
+		}
+		break;
+
+	    case SET4:
+	    case PUT4:
+		if (!resource.omega)
+		    dvi_fmt_error("%s:%d: draw_part: op-code %d only works with the \"-omega\" option",
+				  __FILE__, __LINE__, ch);
+		else {
+#ifdef TEXXET
+		    char_proc(fp, info, xnum(fp, 4));
+#else
+		    a = char_proc(fp, info, xnum(fp, 4));
+		    if (ch != PUT4)
+			xmoveH(1, a);
 #endif
 		}
 		break;
@@ -3278,7 +3821,7 @@ geom_scan_part(long(*char_proc)(FILE *, 
 		    if (info->geom_special != NULL)
 			geom_do_rule(info, xspell_conv(a), b);
 		}
-		DVI_H += DIR * b;
+		moveH(DIR, b);
 		break;
 
 	    case PUTRULE:
@@ -3399,7 +3942,7 @@ geom_scan_part(long(*char_proc)(FILE *, 
 	    case RIGHT2:
 	    case RIGHT3:
 	    case RIGHT4:
-		DVI_H += DIR * xspell_conv(xsnum(fp, ch - RIGHT1 + 1));
+		xmoveH(DIR, xspell_conv(xsnum(fp, ch - RIGHT1 + 1)));
 		break;
 
 	    case W1:
@@ -3408,7 +3951,7 @@ geom_scan_part(long(*char_proc)(FILE *, 
 	    case W4:
 		WW = xspell_conv(xsnum(fp, ch - W0));
 	    case W0:
-		DVI_H += DIR * WW;
+		xmoveH(DIR, WW);
 		break;
 
 	    case X1:
@@ -3417,15 +3960,14 @@ geom_scan_part(long(*char_proc)(FILE *, 
 	    case X4:
 		XX = xspell_conv(xsnum(fp, ch - X0));
 	    case X0:
-		DVI_H += DIR * XX;
+		xmoveH(DIR, XX);
 		break;
 
 	    case DOWN1:
 	    case DOWN2:
 	    case DOWN3:
 	    case DOWN4:
-		DVI_V += xspell_conv(xsnum(fp, ch - DOWN1 + 1));
-		PXL_V = xpixel_conv(DVI_V);
+		xmoveV(1, xspell_conv(xsnum(fp, ch - DOWN1 + 1)));
 		break;
 
 	    case Y1:
@@ -3434,8 +3976,7 @@ geom_scan_part(long(*char_proc)(FILE *, 
 	    case Y4:
 		YY = xspell_conv(xsnum(fp, ch - Y0));
 	    case Y0:
-		DVI_V += YY;
-		PXL_V = xpixel_conv(DVI_V);
+		xmoveV(1, YY);
 		break;
 
 	    case Z1:
@@ -3444,8 +3985,7 @@ geom_scan_part(long(*char_proc)(FILE *, 
 	    case Z4:
 		ZZ = xspell_conv(xsnum(fp, ch - Z0));
 	    case Z0:
-		DVI_V += ZZ;
-		PXL_V = xpixel_conv(DVI_V);
+		xmoveV(1, ZZ);
 		break;
 
 	    case FNT1:
@@ -3482,6 +4022,12 @@ geom_scan_part(long(*char_proc)(FILE *, 
 		xskip(fp, a + (long)xone(fp));
 		break;
 
+#ifdef PTEX
+	    case TDIR:
+		TATE = xone(fp);
+		break;
+#endif /* PTEX */
+
 #ifndef TEXXET
 	    case SREFL:
 	    case EREFL:
