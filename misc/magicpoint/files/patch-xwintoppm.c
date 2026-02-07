--- contrib/xwintoppm/xwintoppm.c.orig	1998-08-26 05:30:16 UTC
+++ contrib/xwintoppm/xwintoppm.c
@@ -139,6 +139,15 @@ long add_pixel_value = 0;
 extern int (*_XErrorFunction)();
 extern int _XDefaultError();
 
+extern void outl();
+
+/* forwards */
+void usage(void);
+void Error(char *string);
+void Window_Dump(Window window, FILE *out);
+int Image_Size(XImage *image);
+int Get_XColors(XWindowAttributes *win_info, XColor **colors);
+
 static long parse_long (s)
     char *s;
 {
@@ -155,11 +164,12 @@ static long parse_long (s)
     return (thesign * retval);
 }
 
+int
 main(argc, argv)
     int argc;
     char **argv;
 {
-    register i;
+    register int i;
     Window target_win;
     FILE *out_file = stdout;
     Bool frame_only = False;
@@ -281,6 +291,7 @@ XColor **colors ;
  *              writting.
  */
 
+void
 Window_Dump(window, out)
      Window window;
      FILE *out;
@@ -609,6 +620,7 @@ Window_Dump(window, out)
 /*
  * Report the syntax for calling xwd.
  */
+void
 usage()
 {
     fprintf (stderr,
@@ -623,6 +635,7 @@ usage()
  * Error - Fatal xwd error.
  */
 
+void
 Error(string)
 	char *string;	/* Error description string. */
 {
@@ -716,6 +729,7 @@ int Get_XColors(win_info, colors)
     return ncolors ;
 }
 
+void
 _swapshort (bp, n)
     register char *bp;
     register unsigned n;
@@ -731,6 +745,7 @@ _swapshort (bp, n)
     }
 }
 
+void
 _swaplong (bp, n)
     register char *bp;
     register unsigned n;
