--- src/xitk/tvset.c.orig	Fri Mar 30 08:51:34 2007
+++ src/xitk/tvset.c	Sun Jul 15 19:26:24 2007
@@ -45,9 +45,9 @@
 
 extern gGui_t          *gGui;
 
-static char            *tvsetfontname     = "-*-helvetica-medium-r-*-*-10-*-*-*-*-*-*-*";
-static char            *lfontname         = "-*-helvetica-bold-r-*-*-10-*-*-*-*-*-*-*";
-static char            *btnfontname       = "-*-helvetica-bold-r-*-*-12-*-*-*-*-*-*-*";
+static char            *tvsetfontname     = "-*-*-medium-r-*-*-10-*-*-*-*-*-*-*";
+static char            *lfontname         = "-*-*-bold-r-*-*-10-*-*-*-*-*-*-*";
+static char            *btnfontname       = "-*-*-bold-r-*-*-12-*-*-*-*-*-*-*";
 
 typedef struct {
   xitk_window_t        *xwin;
