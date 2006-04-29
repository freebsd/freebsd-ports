--- src/vcalendar.c.orig	Mon Apr  3 21:48:28 2006
+++ src/vcalendar.c	Mon Apr  3 21:50:19 2006
@@ -26,6 +26,7 @@
 #include <ical.h>
 #include "gettext.h"
 #include <gtk/gtk.h>
+#include <pthread.h>
 
 #include "mimeview.h"
 #include "utils.h"
