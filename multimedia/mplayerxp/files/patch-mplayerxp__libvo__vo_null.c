--- mplayerxp/libvo/vo_null.c.orig	Thu Jan 19 17:17:41 2006
+++ mplayerxp/libvo/vo_null.c	Sun Oct  1 22:39:27 2006
@@ -35,7 +35,9 @@
 #include "video_out_internal.h"
 #include "dri_vo.h"
 #include "vo_msg.h"
+#if 0
 #include <vidix/vidixlib.h>
+#endif
 
 LIBVO_EXTERN(null)
 
