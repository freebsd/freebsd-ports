--- src/kino_common.cc.orig	Tue Apr  6 15:28:50 2004
+++ src/kino_common.cc	Tue Apr 13 18:48:18 2004
@@ -1080,7 +1080,8 @@
 	Frame *frame = GetFramePool()->GetFrame();
 	if ( frame != NULL )
 	{
-		unsigned char pixels[ FRAME_MAX_WIDTH * FRAME_MAX_HEIGHT * 4 ];
+		unsigned char *pixels;
+		pixels = (unsigned char *)malloc(FRAME_MAX_WIDTH * FRAME_MAX_HEIGHT * 4);
 		GError *gerror = NULL;
 		this->getPlayList()->GetFrame( this->g_currentFrame, *frame );
 
@@ -1115,6 +1116,7 @@
 			g_error_free( gerror );
 		}
 		g_object_unref( im );
+		free(pixels);
 		GetFramePool()->DoneWithFrame( frame );
 	}
 }
