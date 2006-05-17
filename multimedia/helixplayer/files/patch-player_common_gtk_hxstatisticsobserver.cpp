--- player/common/gtk/hxstatisticsobserver.cpp.orig	Thu Apr 29 22:08:12 2004
+++ player/common/gtk/hxstatisticsobserver.cpp	Fri May 21 21:22:19 2004
@@ -41,6 +41,10 @@
 #include "HXClientCFuncs.h"
 #include "HXClientConstants.h"
 
+#if GLIB_CHECK_VERSION (2, 4, 0)
+# define g_value_set_boxed_take_ownership	g_value_take_boxed
+# define g_value_set_string_take_ownership	g_value_take_string
+#endif
 
 enum {
     STATISTIC_ADDED_SIGNAL,
