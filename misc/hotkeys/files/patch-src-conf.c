--- src/conf.c.orig	Wed Nov 27 14:30:08 2002
+++ src/conf.c	Sun May 11 16:01:17 2003
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
