--- Dclock.c.orig	2008-07-08 13:00:35.000000000 +0900
+++ Dclock.c	2012-10-08 00:49:08.000000000 +0900
@@ -8,10 +8,10 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>
-#include <values.h>
+#include <limits.h>
 #include <math.h>
 #include <time.h>
-#include <wait.h>
+#include <sys/wait.h>
 #include <errno.h>
 #include <X11/IntrinsicP.h>
 #include <X11/Xos.h>
@@ -66,7 +66,7 @@
 static int old_digs[4];
 static struct tm before;
 static char *saved_date;
-static cur_position;	/* outline current digit for setting alarm */
+static int cur_position;	/* outline current digit for setting alarm */
 static struct { int hrs, mins; } Alarm;
 static int TopOffset = 0;
 
@@ -165,7 +165,7 @@
 	XtOffset(DclockWidget,dclock.font), XtRString, "fixed"},
 #ifdef XFT_SUPPORT
     { XftNfontName, "fontName", XtRString, sizeof(String),
-	XtOffset(DclockWidget,dclock.xftfontname), XtRString, "charter"},
+	XtOffset(DclockWidget,dclock.xftfontname), XtRString, NULL},
 #endif
     { XtNangle, "Slope", XtRFloat, sizeof(float),
 	XtOffset(DclockWidget,dclock.angle), XtRFloat, (caddr_t)&sslope},
@@ -182,7 +182,7 @@
     { XtNbellFile, "bellFile", XtRString, sizeof(String),
 	XtOffset(DclockWidget,dclock.bellfile), XtRString, (String)NULL},
     { XtNaudioPlay, "audioPlay", XtRString, sizeof(String),
-	XtOffset(DclockWidget,dclock.audioplay), XtRString, "/usr/bin/play"},
+	XtOffset(DclockWidget,dclock.audioplay), XtRString, "%%LOCALBASE%%/bin/play"},
 };
 
 /* Define the Dclock widget */
@@ -235,7 +235,7 @@
  * These stipples give different densities for the
  * different stages of fading.
  */
-static unsigned char stpl_1_8th[] =
+static char stpl_1_8th[] =
 {
     0x80, 0x80, 0x08, 0x08, 0x80, 0x80, 0x08, 0x08,
     0x80, 0x80, 0x08, 0x08, 0x80, 0x80, 0x08, 0x08,
@@ -243,7 +243,7 @@
     0x80, 0x80, 0x08, 0x08, 0x80, 0x80, 0x08, 0x08
 };
 
-static unsigned char stpl_1_4th[] =
+static char stpl_1_4th[] =
 {
     0x88, 0x88, 0x22, 0x22, 0x88, 0x88, 0x22, 0x22,
     0x88, 0x88, 0x22, 0x22, 0x88, 0x88, 0x22, 0x22,
@@ -251,7 +251,7 @@
     0x88, 0x88, 0x22, 0x22, 0x88, 0x88, 0x22, 0x22
 };
 
-static unsigned char stpl_3_8ths[] =
+static char stpl_3_8ths[] =
 {
     0xA2, 0xA2, 0x15, 0x15, 0xA8, 0xA8, 0x45, 0x45,
     0x2A, 0x2A, 0x51, 0x51, 0x8A, 0x8A, 0x54, 0x54,
@@ -259,7 +259,7 @@
     0x2A, 0x2A, 0x51, 0x51, 0x8A, 0x8A, 0x54, 0x54
 };
 
-static unsigned char stpl_one_half[] =
+static char stpl_one_half[] =
 {
     0x55, 0x55, 0xAA, 0xAA, 0x55, 0x55, 0xAA, 0xAA,
     0x55, 0x55, 0xAA, 0xAA, 0x55, 0x55, 0xAA, 0xAA,
@@ -344,6 +344,12 @@
 segment_pts tiny_segment_pts;
 segment_pts norm_segment_pts;
 
+#ifdef XFT_SUPPORT
+#define XFT_COND(dclock) ((dclock).xftfontname)
+#else
+#define XFT_COND(dclock) (0)
+#endif
+
 /* ARGSUSED */
 static void
 Initialize (request, new)
@@ -386,11 +392,13 @@
     if (new->dclock.sec_gap < 0.0) new->dclock.sec_gap = 0.0;
 
 #ifdef XFT_SUPPORT
-    new->dclock.xftfont = XftFontOpen(dpy, DefaultScreen(dpy),
+    if (XFT_COND(new->dclock)) {
+       new->dclock.xftfont = XftFontOpen(dpy, DefaultScreen(dpy),
 		XFT_FAMILY, XftTypeString, new->dclock.xftfontname,
 		XFT_SIZE, XftTypeDouble, ((float)new->core.height / 6.0) - 4.0,
 		NULL);
-    new->dclock.xftdraw = NULL;
+       new->dclock.xftdraw = NULL;
+    }
 #endif
 
     GetGC(new);
@@ -447,11 +455,11 @@
     if (new->dclock.date_fmt && !*new->dclock.date_fmt)
 	new->dclock.date_fmt = NULL;
     if (new->dclock.dateup && new->dclock.date_fmt)
-#ifdef XFT_SUPPORT
+    if (XFT_COND(new->dclock)) {
 	TopOffset = new->core.height / 6;
-#else
+    } else {
 	TopOffset = new->dclock.font->ascent + new->dclock.font->descent;
-#endif
+    }
 
     else
 	TopOffset = 0;
@@ -493,7 +501,7 @@
 
 static void
 invert_bitmap(bm, h, w)
-unsigned char *bm;
+char *bm;
 int h, w;
 {
     int i, *wp;
@@ -519,7 +527,7 @@
     XtCreateWindow(w, InputOutput, (Visual *)CopyFromParent, *valueMask, attrs);
 
 #ifdef XFT_SUPPORT
-    if (dw->dclock.xftdraw == NULL) {
+    if (XFT_COND(dw->dclock) && dw->dclock.xftdraw == NULL) {
 	XColor color;
 	Colormap cm = DefaultColormap(dp, sc);
 
@@ -574,7 +582,8 @@
     XDestroyRegion(clip_colon);
 
 #ifdef XFT_SUPPORT
-    XftFontClose(XtDisplay(w), w->dclock.xftfont);
+    if (XFT_COND(w->dclock))
+	XftFontClose(XtDisplay(w), w->dclock.xftfont);
 #endif
 }
 
@@ -596,11 +605,13 @@
     winheight = w->core.height;
 
 #ifdef XFT_SUPPORT
-    XftFontClose(dpy, w->dclock.xftfont);
-    w->dclock.xftfont = XftFontOpen(dpy, DefaultScreen(dpy),
+    if(XFT_COND(w->dclock)) {
+	XftFontClose(dpy, w->dclock.xftfont);
+	w->dclock.xftfont = XftFontOpen(dpy, DefaultScreen(dpy),
 		XFT_FAMILY, XftTypeString, w->dclock.xftfontname,
 		XFT_SIZE, XftTypeDouble, ((float)winheight / 6.0) - 4.0,
 		NULL);
+    }
 #endif
 
     y_ratio = (float)winheight / CLOCK_HEIGHT;
@@ -608,11 +619,13 @@
     if (w->dclock.date_fmt || !w->dclock.display_time || w->dclock.alarm ||
 	w->dclock.bell)
 	/* make win temporarily shorter so digits will fit on top of date */
-#ifdef XFT_SUPPORT
-	winheight -= w->core.height / 6;
-#else
-	winheight -= w->dclock.font->ascent + w->dclock.font->descent;
-#endif
+    {
+	if(XFT_COND(w->dclock)) {
+	    winheight -= w->core.height / 6;
+	} else {
+	    winheight -= w->dclock.font->ascent + w->dclock.font->descent;
+	}
+    }
 
     /*
      * if the width of all segments are equal, then the width in x is the
@@ -1351,7 +1364,7 @@
     XtAppContext app;
     Boolean save_scroll = w->dclock.scroll;
     Boolean save_fade = w->dclock.fade;
-    long t;
+    time_t t;
 
     if (!XtIsRealized((Widget)w))
 	return;
@@ -1421,7 +1434,7 @@
 {
     char buf[11];
     Boolean alarm_went_off = False;
-    long t = time(0);
+    time_t t = time(0);
     register struct tm *l_time = localtime(&t);
     float digit_w = w->dclock.digit_w;
     float digit_h = w->dclock.digit_h;
@@ -1522,7 +1535,7 @@
     Pixmap new_pix[4];
     int new_digs[4], digitxpos, digitypos;
     int cur_sec = 0;
-    long t;
+    time_t t;
     register struct tm *now;
 
 /* definitions for the window x and y positions of each of the large digits. */
@@ -1585,7 +1598,7 @@
 	unsigned long fade_rate = w->dclock.fade_rate * 1000;
 
 	for (i = 0; i < 4; i++)    /* if pixmaps don't match, fade it */
-	    if (chgd[i] = (new_pix[i] != old_pix[i]))
+	    if ((chgd[i] = (new_pix[i] != old_pix[i])))
 	    {
 		tmp_pix[i] = XCreatePixmap(dpy, win, (int)(digit_w + slope_add),
 			(int)digit_h, DefaultDepthOfScreen(XtScreen(w)));
@@ -1669,51 +1682,60 @@
     char datestr[128];
     register char *p;
     int x, datep;
+    int tsize;
 #ifdef XFT_SUPPORT
-    int tsize = w->core.height / 6;
     XGlyphInfo xftextents;
-#else
-    int tsize = w->dclock.font->ascent + w->dclock.font->descent;
 #endif
 
+    if (XFT_COND(w->dclock)) {
+	tsize = w->core.height / 6;
+    } else {
+	tsize = w->dclock.font->ascent + w->dclock.font->descent;
+    }
+
     if (!w->dclock.display_time)
 	datep = strlen(strcpy(datestr, "Push HERE to Set/Unset Alarm"));
     else
         datep = strftime(datestr, 128, w->dclock.date_fmt, now);
 
+    if (XFT_COND(w->dclock)) {
 #ifdef XFT_SUPPORT
-    XftTextExtents8(dpy, w->dclock.xftfont, datestr, datep, &xftextents);
-    x = (w->core.width - xftextents.width) / 2;
-#else
-    x = (w->core.width - XTextWidth(w->dclock.font, datestr, datep)) / 2;
+	XftTextExtents8(dpy, w->dclock.xftfont, (FcChar8*)datestr, datep, &xftextents);
+	x = (w->core.width - xftextents.width) / 2;
 #endif
+    } else {
+	x = (w->core.width - XTextWidth(w->dclock.font, datestr, datep)) / 2;
+    }
+
     if (x < 2)
 	x = 2;
     if (TopOffset) {
-
+	if (XFT_COND(w->dclock)) {
 #ifdef XFT_SUPPORT
-	XftDrawRect(w->dclock.xftdraw, &w->dclock.xftbg, 0, 0, winwidth, tsize);
-	XftDrawString8(w->dclock.xftdraw, &w->dclock.xftfg, w->dclock.xftfont, x,
-		(BORDER/2) + tsize - 2, datestr, datep);
-#else
-	XFillRectangle(dpy, win, w->dclock.backGC,
-	    0, 0, winwidth, tsize);
-	XDrawString(dpy, win, w->dclock.foreGC,
-		x, ((BORDER/2)+w->dclock.xftfont->height), datestr, datep);
+	    XftDrawRect(w->dclock.xftdraw, &w->dclock.xftbg, 0, 0, winwidth, tsize);
+	    XftDrawString8(w->dclock.xftdraw, &w->dclock.xftfg, w->dclock.xftfont, x,
+		(BORDER/2) + tsize - 2, (FcChar8*)datestr, datep);
 #endif
+	} else {
+	    XFillRectangle(dpy, win, w->dclock.backGC,
+		0, 0, winwidth, tsize);
+	    XDrawString(dpy, win, w->dclock.foreGC,
+		x, ((BORDER/2)+tsize), datestr, datep);
+	}
     } else {
-
+	if (XFT_COND(w->dclock)) {
 #ifdef XFT_SUPPORT
-	XftDrawRect(w->dclock.xftdraw, &w->dclock.xftbg, 0, winheight - tsize,
+	    XftDrawRect(w->dclock.xftdraw, &w->dclock.xftbg, 0, winheight - tsize,
 		winwidth, tsize);
-	XftDrawString8(w->dclock.xftdraw, &w->dclock.xftfg, w->dclock.xftfont, x,
-		winheight - BORDER - 2, datestr, datep);
-#else
-	XFillRectangle(dpy, win, w->dclock.backGC,
-	    0, winheight - tsize, winwidth, tsize);
-	XDrawString(dpy, win, w->dclock.foreGC,
-		x, winheight - BORDER, datestr, datep);
+	    XftDrawString8(w->dclock.xftdraw, &w->dclock.xftfg, w->dclock.xftfont, x,
+		winheight - BORDER - 2, (FcChar8*)datestr, datep);
 #endif
+	} else {
+	    XFillRectangle(dpy, win, w->dclock.backGC,
+		0, winheight - tsize, winwidth, tsize);
+	    XDrawString(dpy, win, w->dclock.foreGC,
+		x, winheight - BORDER, datestr, datep);
+	}
     }
 }
 
@@ -1992,13 +2014,13 @@
     w->dclock.date_fmt = saved_date;
     saved_date = tmp;
 
-    if (w->dclock.dateup && w->dclock.date_fmt)
-#ifdef XFT_SUPPORT
-	TopOffset = w->core.height / 6;
-#else
-	TopOffset = w->dclock.font->ascent + w->dclock.font->descent;
-#endif
-    else
+    if (w->dclock.dateup && w->dclock.date_fmt) {
+	if (XFT_COND(w->dclock)) {
+	    TopOffset = w->core.height / 6;
+	} else {
+	    TopOffset = w->dclock.font->ascent + w->dclock.font->descent;
+	}
+    } else
 	TopOffset = 0;
 
     before.tm_wday = -1;
@@ -2021,13 +2043,13 @@
     XtSetArg(arg, XtNdateUp, !w->dclock.dateup);
     XtSetValues((Widget)w, &arg, 1);
 
-    if (w->dclock.dateup && w->dclock.date_fmt)
-#ifdef XFT_SUPPORT
-	TopOffset = w->core.height / 6;
-#else
-	TopOffset = w->dclock.font->ascent + w->dclock.font->descent;
-#endif
-    else
+    if (w->dclock.dateup && w->dclock.date_fmt) {
+	if (XFT_COND(w->dclock)) {
+	    TopOffset = w->core.height / 6;
+	} else {
+	    TopOffset = w->dclock.font->ascent + w->dclock.font->descent;
+	}
+    } else
 	TopOffset = 0;
 
     ResizeNow(w);
@@ -2038,7 +2060,7 @@
 toggle_bell(w)
 DclockWidget w;
 {
-    if (w->dclock.bell = !w->dclock.bell) {
+    if ((w->dclock.bell = !w->dclock.bell)) {
 	playbell(w, 1);
     }
     ResizeNow(w);
@@ -2159,7 +2181,7 @@
 DclockWidget w;
 XButtonEvent *event;
 {
-    static saved_secs, saved_miltime, saved_fade, saved_blink;
+    static int saved_secs, saved_miltime, saved_fade, saved_blink;
 
     if (event->button == 3) {
 	if (!(w->dclock.display_time = !w->dclock.display_time)) {
@@ -2184,20 +2206,20 @@
 	 */
 	int i, x, y = (int)((BORDER/2)*y_ratio) + TopOffset;
 	/* first check to see if user toggles the alarm */
-#ifdef XFT_SUPPORT
-	if (TopOffset)
+	if (XFT_COND(w->dclock)) {
+	    if (TopOffset)
 		i = (BORDER + (w->core.height / 6))
 			- event->y;
-	else
+	    else
 		i = event->y - (winheight - (w->core.height / 6));
-#else
-	if (TopOffset)
+	} else {
+	    if (TopOffset)
 		i = (BORDER + (w->dclock.font->ascent + w->dclock.font->descent))
 			- event->y;
-	else
+	    else
 		i = event->y - (winheight - (w->dclock.font->ascent
 			+ w->dclock.font->descent));
-#endif
+	}
 	if (i >= 0)
 	    toggle_alarm(w);
 	else for (i = 0; i < 4; i++) {
