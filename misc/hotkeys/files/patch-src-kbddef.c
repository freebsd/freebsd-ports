--- src/kbddef.c.orig	Wed Nov 27 14:51:11 2002
+++ src/kbddef.c	Sun May 11 16:01:17 2003
@@ -37,8 +37,8 @@
  */
 #include "XF86keysym.h"
 
-#include <xmlmemory.h>
-#include <parser.h>
+#include <libxml2/libxml/xmlmemory.h>
+#include <libxml2/libxml/parser.h>
 
 #include "hotkeys.h"
 #include "kbddef.h"
@@ -71,6 +71,9 @@
     { "MyComputer",             myComputerKey,      XF86XK_MyComputer },
     { "Favorites",              favoritesKey,       XF86XK_Favorites },
     { "Calculator",             calculatorKey,      XF86XK_Calculator },
+    { "Messenger",              messengerKey,       0 },
+    { "Webcam",                 webcamKey,          0 },
+    { "Media",                  mediaKey,           0 },
     { "NewsReader",             newsReaderKey,      0 },
     { "iNews",                  iNewsKey,           0 },
     { "Rewind",                 rewindKey,          0 },
