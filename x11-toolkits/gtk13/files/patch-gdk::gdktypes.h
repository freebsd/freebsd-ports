
$FreeBSD$

--- gdk/gdktypes.h	2002/02/14 10:01:48	1.1
+++ gdk/gdktypes.h	2002/02/14 10:01:59
@@ -48,7 +48,7 @@
  * itself, but also occasionally when compiling programs that use GDK
  * (or GTK). One such setting is what windowing API backend is in use.
  */
-#include <gdkconfig.h>
+#include <gtk/gdkconfig.h>
 
 /* some common magic values */
 #define GDK_CURRENT_TIME     0L
