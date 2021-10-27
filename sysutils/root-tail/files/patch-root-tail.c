Sources:
https://src.fedoraproject.org/rpms/root-tail/blob/rawhide/f/root-tail-1.3-Generate-Expose-events-when-clearing-a-window.patch
https://src.fedoraproject.org/rpms/root-tail/blob/rawhide/f/root-tail-1.3-Respect-width-and-height-unsigness-in-arithmetics.patch

--- root-tail.c.orig	2019-06-16 00:46:04 UTC
+++ root-tail.c
@@ -38,6 +38,7 @@
 #include <locale.h>
 #include <ctype.h>
 #include <stdarg.h>
+#include <limits.h>
 #include <X11/Xlib.h>
 #include <X11/Xatom.h>
 #include <X11/Xutil.h>
@@ -118,7 +119,7 @@ static int continuation_length;
 /* HACK - ideally listlen will start at however many '~'s will fit on
  * the screen */
 static unsigned int width = STD_WIDTH, height = STD_HEIGHT;
-static int listlen = 50;
+static unsigned int listlen = 50;
 static int win_x = LOC_X, win_y = LOC_Y;
 static int effect_x_space, effect_y_space; /* how much space does shading / outlining take up */
 static int effect_x_offset, effect_y_offset; /* and how does it offset the usable space */
@@ -206,7 +207,7 @@ force_refresh (int dummy)
 static void
 blank_window (int dummy)
 {
-  XClearArea (disp, root, win_x, win_y, width + MARGIN_OF_ERROR, height, False);
+  XClearArea (disp, root, win_x, win_y, width + MARGIN_OF_ERROR, height, True);
   XFlush (disp);
   exit (0);
 }
@@ -369,7 +370,7 @@ InitWindow (void)
 	{
 	  fprintf(stderr, "\n  the display isn't tall enough to display a single line in font '%s'\n",
 		  e->fontname);
-	  fprintf(stderr, "\n  the geometry in use is %d pixels tall\n", height);
+	  fprintf(stderr, "\n  the geometry in use is %u pixels tall\n", height);
 	  fprintf(stderr, "\n  font '%s' is %d pixels tall\n", e->fontname, e->font_height);
 	  if (effect_y_space)
 	    fprintf(stderr, "\n  the shade or outline options need an extra %d pixel%s of vertical space\n",
@@ -445,8 +446,8 @@ draw_text (Display *disp, Window root, GC WinGC, int x
 static void
 refresh (int miny, int maxy, int clear, int refresh_all)
 {
-  int lin = 0;
-  int space = height;
+  unsigned int lin = 0;
+  int space = (int)height;
   int offset;
   unsigned long black_color = GetColor ("black");
   struct line_node *line;
@@ -462,7 +463,7 @@ refresh (int miny, int maxy, int clear, int refresh_al
   maxy -= win_y;
 
   if (clear && !opt_noflicker)
-    XClearArea (disp, root, win_x, win_y, width + MARGIN_OF_ERROR, height, False);
+    XClearArea (disp, root, win_x, win_y, width + MARGIN_OF_ERROR, height, True);
 
   for (line = linelist; line; line = line->next, lin++)
     {
@@ -470,7 +471,7 @@ refresh (int miny, int maxy, int clear, int refresh_al
 
       if (opt_noflicker && lin >= listlen)
         {
-          int i = listlen;
+          unsigned int i = listlen;
           listlen *= 1.5;
           display = xrealloc(display, listlen * sizeof(struct displaymatrix));
           for (; i < listlen; i++)
@@ -535,7 +536,7 @@ refresh (int miny, int maxy, int clear, int refresh_al
                                       width, step_per_line);
 #else /* DEBUG */
                       XClearArea (disp, root, win_x, win_y + offset - line->logfile->font_ascent,
-                                  width + MARGIN_OF_ERROR, step_per_line, False);
+                                  width + MARGIN_OF_ERROR, step_per_line, True);
 #endif /* DEBUG */
                     }
                 }
@@ -584,7 +585,7 @@ refresh (int miny, int maxy, int clear, int refresh_al
                       width, space);
 #else /* DEBUG */
       XClearArea (disp, root, win_x, win_y + offset - (opt_reverse ? 0 : space),
-                  width + MARGIN_OF_ERROR, space, False);
+                  width + MARGIN_OF_ERROR, space, True);
 #endif
     }
 
@@ -1112,7 +1113,7 @@ append_to_existing_line (char *str, struct logfile_ent
 static void
 main_loop (void)
 {
-  int lin;
+  unsigned int lin;
   time_t lastreload;
   Region region = XCreateRegion ();
   XEvent xev;
@@ -1325,8 +1326,26 @@ main (int argc, char *argv[])
           else if (!strcmp (arg, "-V"))
             display_version ();
           else if (!strcmp (arg, "-g") || !strcmp (arg, "-geometry"))
-            geom_mask =
-              XParseGeometry (argv[++i], &win_x, &win_y, &width, &height);
+            {
+              geom_mask =
+                XParseGeometry (argv[++i], &win_x, &win_y, &width, &height);
+              /* Width and height are used in various expressions assigned to
+               * signed or unsigned integers. The assignments could overflow. */
+              if (width < 1 || width > INT_MAX - MARGIN_OF_ERROR || width > UINT_MAX)
+                {
+                  fprintf (stderr,
+                      "The geometry width is too small or too large: '%u'.\n",
+                      width);
+                  exit (1);
+                }
+              if (height < 1 || height > UINT_MAX)
+                {
+                  fprintf (stderr,
+                      "The geometry height is too small or too large: '%u'.\n",
+                      height);
+                  exit (1);
+                }
+            }
           else if (!strcmp (arg, "-display"))
             dispname = argv[++i];
           else if (!strcmp (arg, "-cont"))
