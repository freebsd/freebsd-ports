--- src/kino_common.cc.orig	Wed Mar  7 10:23:12 2007
+++ src/kino_common.cc	Sat Mar 17 21:17:18 2007
@@ -35,6 +35,8 @@
 #ifndef _GNU_SOURCE
 #define _GNU_SOURCE
 #endif
+#include <libgen.h>
+#include <signal.h>
 #include <string.h>
 #include <stdarg.h>
 #include <time.h>
@@ -1527,7 +1529,8 @@
 	Frame *frame = GetFramePool()->GetFrame();
 	if ( frame != NULL )
 	{
-		unsigned char pixels[ FRAME_MAX_WIDTH * FRAME_MAX_HEIGHT * 4 ];
+		unsigned char *pixels;
+		pixels = (unsigned char *)malloc(FRAME_MAX_WIDTH * FRAME_MAX_HEIGHT * 4);
 		GError *gerror = NULL;
 		this->getPlayList()->GetFrame( this->g_currentFrame, *frame );
 
@@ -1562,6 +1565,7 @@
 			g_error_free( gerror );
 		}
 		g_object_unref( im );
+		free(pixels);
 		GetFramePool()->DoneWithFrame( frame );
 	}
 }
