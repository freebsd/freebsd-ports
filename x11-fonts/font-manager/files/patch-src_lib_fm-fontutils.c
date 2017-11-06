--- src/lib/fm-fontutils.c.orig	2015-05-29 06:45:34 UTC
+++ src/lib/fm-fontutils.c
@@ -24,6 +24,7 @@
 #include <glib.h>
 #include <glib/gprintf.h>
 #include <glib/gstdio.h>
+#include <unistd.h>
 
 #include <pango/pangofc-fontmap.h>
 #include <fontconfig/fcfreetype.h>
