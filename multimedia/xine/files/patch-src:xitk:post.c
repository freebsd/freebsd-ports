--- src/xitk/post.c.orig	Thu Dec 16 06:10:46 2004
+++ src/xitk/post.c	Thu Dec 30 04:31:21 2004
@@ -67,10 +67,11 @@
         xitk_enable_and_show_widget(widget);                                                    \
     } while(0)
  
-static char                  *br_fontname      = "-misc-fixed-medium-r-normal-*-10-*-*-*-*-*-*-*";
-static char                  *btnfontname      = "-*-helvetica-bold-r-*-*-12-*-*-*-*-*-*-*";
-static char                  *fontname         = "-*-helvetica-medium-r-*-*-10-*-*-*-*-*-*-*";
-static char                  *boldfontname     = "-*-helvetica-bold-r-*-*-12-*-*-*-*-*-*-*";
+
+static char                  *br_fontname      = "-*-*-medium-r-normal-*-10-*-*-*-*-*-*-*";
+static char                  *btnfontname      = "-*-*-bold-r-normal-*-12-*-*-*-*-*-*-*";
+static char                  *fontname         = "-*-*-medium-r-normal-*-10-*-*-*-*-*-*-*";
+static char                  *boldfontname     = "-*-*-bold-r-normal-*-12-*-*-*-*-*-*-*";
 
 typedef struct {
   xine_post_t                 *post;
