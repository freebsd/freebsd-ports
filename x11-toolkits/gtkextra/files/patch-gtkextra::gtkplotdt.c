
$FreeBSD$

--- gtkextra/gtkplotdt.c	2001/12/05 09:01:36	1.1
+++ gtkextra/gtkplotdt.c	2001/12/05 09:02:12
@@ -20,7 +20,9 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <math.h>
+#ifndef __FreeBSD__
 #include <malloc.h>
+#endif
 #include <string.h>
 #include <gtk/gtk.h>
 #include "gtkplotdt.h"
