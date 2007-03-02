--- src/conf.c.orig	Thu Nov 28 03:30:08 2002
+++ src/conf.c	Fri Mar  2 19:26:23 2007
@@ -25,7 +25,7 @@
 #include "common.h"
 
 #include <stdio.h>
-#include <db.h>
+#include </usr/local/include/db3/db.h>
 #include <string.h>
 #include <sys/param.h>
 
@@ -68,6 +68,9 @@
     "Shopping",        "mozilla -remote 'openURL(http://thinkgeek.com)'",
     "Go",              "mozilla -remote 'openURL(http://linux.com)'",
     "Print",           "lpr",
+    "Messenger",       "gaim",
+    "Webcam",          "\0",
+    "Media",           "xmms",
 /*
     "Screendump",      "xwd -root",
 */
@@ -75,9 +78,14 @@
 //    "osd_font",        "-*-lucidatypewriter-bold-r-normal-*-*-250-*-*-*-*-*-*",
     "osd_font",        "lucidasanstypewriter-bold-24",
     "osd_color",       "LawnGreen",
+    "osd_shadow_color",	"Black",
+    "osd_shadow_offset",	"3",
     "osd_timeout",     "3",
     "osd_position",    "bottom",
-    "osd_offset",      "25",
+    "osd_align",	"center",
+    "osd_hoffset",      "25",
+    "osd_voffset",      "25",
+    "osd_bar_length",	"25",
     NULL,              NULL
 };
 
