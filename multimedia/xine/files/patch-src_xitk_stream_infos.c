--- src/xitk/stream_infos.c.orig	Sun Jul 15 19:28:59 2007
+++ src/xitk/stream_infos.c	Sun Jul 15 19:29:13 2007
@@ -45,9 +45,9 @@
 
 extern gGui_t          *gGui;
 
-static char            *sinfosfontname     = "-*-helvetica-medium-r-*-*-10-*-*-*-*-*-*-*";
-static char            *lfontname          = "-*-helvetica-bold-r-*-*-10-*-*-*-*-*-*-*";
-static char            *btnfontname        = "-*-helvetica-bold-r-*-*-12-*-*-*-*-*-*-*";
+static char            *sinfosfontname     = "-*-*-medium-r-*-*-10-*-*-*-*-*-*-*";
+static char            *lfontname          = "-*-*-bold-r-*-*-10-*-*-*-*-*-*-*";
+static char            *btnfontname        = "-*-*-bold-r-*-*-12-*-*-*-*-*-*-*";
 
 typedef struct {
   xitk_window_t        *xwin;
