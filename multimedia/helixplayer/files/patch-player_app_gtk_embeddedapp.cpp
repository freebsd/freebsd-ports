--- player/app/gtk/embeddedapp.cpp.orig	Mon May 17 23:04:00 2004
+++ player/app/gtk/embeddedapp.cpp	Sat May 22 22:44:45 2004
@@ -56,6 +56,9 @@
 #include <unistd.h>
 
 #include <glib.h>
+#if GLIB_CHECK_VERSION (2, 4, 0)
+# define g_value_set_string_take_ownership	g_value_take_string
+#endif
 
 /* This file contains functions with several different prefixes.
  * They include:
