--- src/kino_common.cc.orig	Fri Dec 15 09:49:52 2006
+++ src/kino_common.cc	Mon Dec 25 23:46:08 2006
@@ -34,6 +34,7 @@
 #ifndef _GNU_SOURCE
 #define _GNU_SOURCE
 #endif
+#include <libgen.h>
 #include <string.h>
 #include <stdarg.h>
 #include <time.h>
@@ -1486,7 +1487,8 @@
 	Frame *frame = GetFramePool()->GetFrame();
 	if ( frame != NULL )
 	{
-		unsigned char pixels[ FRAME_MAX_WIDTH * FRAME_MAX_HEIGHT * 4 ];
+		unsigned char *pixels;
+		pixels = (unsigned char *)malloc(FRAME_MAX_WIDTH * FRAME_MAX_HEIGHT * 4);
 		GError *gerror = NULL;
 		this->getPlayList()->GetFrame( this->g_currentFrame, *frame );
 
@@ -1521,6 +1523,7 @@
 			g_error_free( gerror );
 		}
 		g_object_unref( im );
+		free(pixels);
 		GetFramePool()->DoneWithFrame( frame );
 	}
 }
