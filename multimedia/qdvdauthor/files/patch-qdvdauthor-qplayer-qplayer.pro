--- qdvdauthor/qplayer/qplayer.pro.orig	Mon Feb 14 20:41:59 2005
+++ qdvdauthor/qplayer/qplayer.pro	Mon Feb 14 20:42:05 2005
@@ -25,16 +25,6 @@
 	CREATE_MEDIA_CONFIG = 1
 }
 
-# So the question is if we should create the MEDIA_CONFIG.h - file ?
-contains (CREATE_MEDIA_CONFIG, 1)	{
-system (echo -e '\x23ifndef MEDIA_CONFIG_H' > MEDIA_CONFIG.h )
-system (echo -e '\x23define MEDIA_CONFIG_H' >> MEDIA_CONFIG.h )
-contains ( HAS_MPLAYER_SUPPORT, 1 ) { system (echo -e '\x23define MPLAYER_SUPPORT $$(WITH_MPLAYER_SUPPORT)' >> MEDIA_CONFIG.h ) }
-contains ( HAS_XINE_SUPPORT, 1 )    { system (echo -e '\x23define XINE_SUPPORT  $$(WITH_XINE_SUPPORT)' >> MEDIA_CONFIG.h ) }
-contains ( HAS_VLC_SUPPORT, 1 )     { system (echo -e '\x23define VLC_SUPPORT  $$(WITH_VLC_SUPPORT)' >> MEDIA_CONFIG.h ) }
-system (echo -e '\x23endif // MEDIA_CONFIG_H' >> MEDIA_CONFIG.h )
-}
-
 DISTFILES	= README
 
 SOURCES	+=	qplayer.cpp   \
