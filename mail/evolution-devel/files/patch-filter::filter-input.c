
$FreeBSD$

--- filter/filter-input.c	2001/09/04 16:51:06	1.1
+++ filter/filter-input.c	2001/09/04 16:51:29
@@ -23,6 +23,7 @@
 #endif
 
 #include <string.h>
+#include <sys/types.h>
 #include <regex.h>
 #include <gtk/gtkobject.h>
 #include <gtk/gtkwidget.h>
