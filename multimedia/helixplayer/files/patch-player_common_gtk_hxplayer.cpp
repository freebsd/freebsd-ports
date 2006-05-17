--- player/common/gtk/hxplayer.cpp.orig	Mon May 17 19:28:16 2004
+++ player/common/gtk/hxplayer.cpp	Fri May 21 21:20:13 2004
@@ -47,7 +47,15 @@
 #include <X11/Xatom.h>
 #endif
 
+#ifdef GTK_DISABLE_DEPRECATED
+# undef GTK_DISABLE_DEPRECATED
+#endif
 #include <gtk/gtkmain.h>
+#if GLIB_CHECK_VERSION (2, 4, 0)
+# define g_value_set_boxed_take_ownership	g_value_take_boxed
+# define g_value_set_string_take_ownership	g_value_take_string
+#endif
+
 #include <memory.h>
 #include <stdlib.h>
 #include <stdio.h>
