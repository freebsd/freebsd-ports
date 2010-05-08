--- style/qt_settings.c.o	2010-05-06 14:56:53.000000000 +0000
+++ style/qt_settings.c	2010-05-06 15:00:46.000000000 +0000
@@ -22,6 +22,8 @@
 #include "common.h"
 #define CONFIG_READ
 #include "config_file.c"
+#include "getline.h"
+#include "getline.c"
 #include <gtk/gtk.h>
 #include <time.h>
 #include <gdk/gdkcolor.h>
