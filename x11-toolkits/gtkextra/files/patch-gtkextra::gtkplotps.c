
$FreeBSD$

--- gtkextra/gtkplotps.c	2001/07/05 08:52:19	1.1
+++ gtkextra/gtkplotps.c	2001/07/05 08:52:48
@@ -34,7 +34,9 @@
 #include <ctype.h>
 #include <time.h>
 #include <gtk/gtk.h>
+#if __FreeBSD_version >= 500019
 #include <wctype.h>
+#endif
 
 #include "gtkplot.h"
 #include "gtkpsfont.h"
