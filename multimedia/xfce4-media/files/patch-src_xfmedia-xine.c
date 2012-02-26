--- src/xfmedia-xine.c.orig
+++ src/xfmedia-xine.c
@@ -38,15 +38,15 @@
 #ifdef HAVE_MATH_H
 #include <math.h>
 #endif
+#ifdef HAVE_SYS_TYPES_H
+#include <sys/types.h>
+#endif
 #ifdef HAVE_SYS_SELECT_H
 #include <sys/select.h>
 #endif
 #ifdef HAVE_SYS_TIME_H
 #include <sys/time.h>
 #endif
-#ifdef HAVE_SYS_TYPES_H
-#include <sys/types.h>
-#endif
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
 #endif
@@ -1457,7 +1457,8 @@ xfmedia_xine_trick_mode(XfmediaXine * xf
     g_return_val_if_fail(XFMEDIA_IS_XINE(xfx), 0);
     g_return_val_if_fail(xfx->priv->stream != NULL, 0);
 
-    return xine_trick_mode(xfx->priv->stream, mode, value);
+    //return xine_trick_mode(xfx->priv->stream, mode, value);
+    return 0;
 }
 
 gboolean
