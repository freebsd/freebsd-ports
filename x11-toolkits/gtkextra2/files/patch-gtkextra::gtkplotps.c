
$FreeBSD$

--- gtkextra/gtkplotps.c.orig	Fri Nov 30 17:13:40 2001
+++ gtkextra/gtkplotps.c	Wed Dec  5 10:58:27 2001
@@ -34,7 +34,9 @@
 #include <ctype.h>
 #include <time.h>
 #include <gtk/gtk.h>
+#if __FreeBSD_version >= 500019
 #include <wctype.h>
+#endif
 #include <locale.h>
 
 #include "gtkplot.h"
