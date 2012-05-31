--- src/lib/fm-fontutils.c~	2010-12-23 21:48:30.000000000 -0600
+++ src/lib/fm-fontutils.c	2012-05-30 17:04:54.303401685 -0500
@@ -24,6 +24,7 @@
 #include <glib.h>
 #include <glib/gprintf.h>
 #include <glib/gstdio.h>
+#include <unistd.h>
 
 #include <pango/pangofc-fontmap.h>
 #include <fontconfig/fcfreetype.h>
