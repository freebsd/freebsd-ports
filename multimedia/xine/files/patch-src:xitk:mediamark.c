--- src/xitk/mediamark.c.orig	Thu Dec 16 16:14:26 2004
+++ src/xitk/mediamark.c	Thu Dec 30 04:30:47 2004
@@ -44,8 +44,8 @@
 #define WINDOW_WIDTH            505
 #define WINDOW_HEIGHT           250
 
-static char                    *btnfontname  = "-*-helvetica-bold-r-*-*-12-*-*-*-*-*-*-*";
-static char                    *fontname     = "-*-helvetica-medium-r-*-*-10-*-*-*-*-*-*-*";
+static char                    *btnfontname  = "-*-*-bold-r-normal-*-12-*-*-*-*-*-*-*";
+static char                    *fontname     = "-*-*-medium-r-normal-*-10-*-*-*-*-*-*-*";
 
 typedef struct {
   apply_callback_t              callback;
