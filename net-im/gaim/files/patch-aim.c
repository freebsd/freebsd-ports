--- src/aim.c.orig	Fri Aug 31 20:15:17 2001
+++ src/aim.c	Fri Aug 31 20:15:39 2001
@@ -54,9 +54,7 @@
 #include "locale.h"
 #include "gtkticker.h"
 #include "gtkspell.h"
-#ifndef USE_APPLET
 #include <getopt.h>
-#endif
 
 static gchar *ispell_cmd[] = { "ispell", "-a", NULL };
 
