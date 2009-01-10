--- common/gkr-daemon-util.h.orig	2008-08-04 13:36:06.000000000 -0400
+++ common/gkr-daemon-util.h	2008-08-04 13:36:18.000000000 -0400
@@ -26,6 +26,8 @@
 
 G_BEGIN_DECLS
 
+#include <sys/types.h>
+
 #include <glib.h>
 #include <glib-object.h>
 
