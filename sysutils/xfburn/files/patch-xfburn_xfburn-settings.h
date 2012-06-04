patch attached.

--- patch-xfburn_xfburn-settings.h begins here ---
--- xfburn/xfburn-settings.h.orig	2009-10-24 17:18:10.000000000 -0400
+++ xfburn/xfburn-settings.h	2012-06-02 18:19:00.866609000 -0400
@@ -23,7 +23,7 @@
 #include <config.h>
 #endif /* !HAVE_CONFIG_H */
 
-#include <glib.h>
+#include <glib-object.h>
 
 G_BEGIN_DECLS
 
--- patch-xfburn_xfburn-settings.h ends here ---


