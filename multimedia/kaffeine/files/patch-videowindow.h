--- kaffeine/videowindow.h.orig	Sat Mar 27 23:06:31 2004
+++ kaffeine/videowindow.h	Sat Mar 27 23:07:34 2004
@@ -26,7 +26,7 @@
 #include <config.h>
 #endif
 
-
+#include <pthread.h>
 #include <qwidget.h>
 #include <qfile.h>
 #include <qstringlist.h>
