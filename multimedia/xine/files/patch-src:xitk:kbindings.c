--- src/xitk/kbindings.c.orig	Fri Dec 17 01:14:08 2004
+++ src/xitk/kbindings.c	Thu Dec 30 04:29:27 2004
@@ -81,8 +81,8 @@
 } _kbedit_t;
 
 static _kbedit_t    *kbedit = NULL;
-static char         *fontname = "-*-helvetica-bold-r-*-*-12-*-*-*-*-*-*-*";
-static char         *br_fontname = "-misc-fixed-medium-r-normal-*-10-*-*-*-*-*-*-*";
+static char         *fontname = "-*-*-bold-r-normal-*-12-*-*-*-*-*-*-*";
+static char         *br_fontname = "-*-*-medium-r-normal-*-10-*-*-*-*-*-*-*";
 #define FONT_HEIGHT_MODEL "azertyuiopqsdfghjklmwxcvbnAZERTYUIOPQSDFGHJKLMWXCVBN&й(-и_за)=№~#{[|`\\^@]}%"
 
 #define WINDOW_WIDTH        520
