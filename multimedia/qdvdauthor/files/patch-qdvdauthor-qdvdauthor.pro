--- qdvdauthor/qdvdauthor.pro.orig	Mon Feb 14 20:40:21 2005
+++ qdvdauthor/qdvdauthor.pro	Mon Feb 14 20:40:39 2005
@@ -29,19 +29,6 @@
 isEmpty(WHICH_PREFIX)	{
 	WHICH_PREFIX = /usr
 }
-# Here we create CONFIG.h according to the set-up ...
-system (echo -e '\x23ifndef CONFIG_H' > CONFIG.h )
-system (echo -e '\x23define CONFIG_H' >> CONFIG.h )
-system (echo -e '\x23define PREFIX_DIRECTORY "$$WHICH_PREFIX"' >> CONFIG.h )
-system (echo -e '\x23endif // CONFIG_H' >> CONFIG.h )
-
-# Next we create the MEDIA_CONFIG.h - file
-system (echo -e '\x23ifndef MEDIA_CONFIG_H' > qplayer/MEDIA_CONFIG.h )
-system (echo -e '\x23define MEDIA_CONFIG_H' >> qplayer/MEDIA_CONFIG.h )
-contains ( HAS_MPLAYER_SUPPORT, 1 ) { system (echo -e '\x23define MPLAYER_SUPPORT $$(WITH_MPLAYER_SUPPORT)' >> qplayer/MEDIA_CONFIG.h ) }
-contains ( HAS_XINE_SUPPORT, 1 )    { system (echo -e '\x23define XINE_SUPPORT  $$(WITH_XINE_SUPPORT)' >> qplayer/MEDIA_CONFIG.h ) }
-contains ( HAS_VLC_SUPPORT, 1 )     { system (echo -e '\x23define VLC_SUPPORT  $$(WITH_VLC_SUPPORT)' >> qplayer/MEDIA_CONFIG.h ) }
-system (echo -e '\x23endif // MEDIA_CONFIG_H' >> qplayer/MEDIA_CONFIG.h )
 
 SOURCES	+= main.cpp\
 	utils.cpp \
