--- qdvdauthor/qplayer/qplayer.pro.orig	Fri Dec 23 13:07:06 2005
+++ qdvdauthor/qplayer/qplayer.pro	Fri Dec 30 05:59:49 2005
@@ -102,7 +102,7 @@
 		LIB_EXTRA += &&
 	}
 	LIB_EXTRA += vlc-config --cxxflags --libs
-	LIBS +=-L/usr/local/lib/vlc -lvlc -ldl -lavcodec -lavformat -lvlc -lmemcpymmx -li420_rgb_mmx -li422_yuy2_mmx -li420_ymga_mmx -li420_yuy2_mmx -lmemcpymmxext -lmemcpy3dn -lffmpeg -lstream_out_switcher -lpthread -lxvideo -lX11 -lXaw -lXv -lXinerama
+	LIBS +=-L/usr/X11R6/lib/vlc -lvlc -lavcodec -lavformat -lvlc -lmemcpymmx -li420_rgb_mmx -li422_yuy2_mmx -li420_ymga_mmx -li420_yuy2_mmx -lmemcpymmxext -lmemcpy3dn -lffmpeg -lstream_out_switcher -lpthread -lxvideo -lX11 -lXaw -lXv -lXinerama
 	SOURCES	+=	engines/vlcinfo.cpp \
 			engines/vlcwidget.cpp \
 			engines/qvlcwidget.cpp
