--- src/xitk/tvset.c.orig	Thu Dec 16 06:10:46 2004
+++ src/xitk/tvset.c	Thu Dec 30 04:36:57 2004
@@ -45,9 +45,9 @@
 
 extern gGui_t          *gGui;
 
-static char            *tvsetfontname     = "-*-helvetica-medium-r-*-*-10-*-*-*-*-*-*-*";
-static char            *lfontname         = "-*-helvetica-bold-r-*-*-11-*-*-*-*-*-*-*";
-static char            *btnfontname       = "-*-helvetica-bold-r-*-*-12-*-*-*-*-*-*-*";
+static char            *tvsetfontname     = "-*-*-medium-r-normal-*-10-*-*-*-*-*-*-*";
+static char            *lfontname         = "-*-*-bold-r-normal-*-11-*-*-*-*-*-*-*";
+static char            *btnfontname       = "-*-*-bold-r-normal-*-12-*-*-*-*-*-*-*";
 
 typedef struct {
   xitk_window_t        *xwin;
