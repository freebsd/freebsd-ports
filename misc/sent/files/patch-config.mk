--- config.mk.orig	2018-02-01 17:23:54 UTC
+++ config.mk
@@ -16,8 +16,8 @@ LIBS = -L/usr/lib -lc -lm -L${X11LIB} -lXft -lfontconf
 # OpenBSD (uncomment)
 #INCS = -I. -I${X11INC} -I${X11INC}/freetype2
 # FreeBSD (uncomment)
-#INCS = -I. -I/usr/local/include -I/usr/local/include/freetype2 -I${X11INC}
-#LIBS = -L/usr/local/lib -lc -lm -L${X11LIB} -lXft -lfontconfig -lX11
+INCS = -I. -I/usr/local/include -I/usr/local/include/freetype2 -I${X11INC}
+LIBS = -L/usr/local/lib -lc -lm -L${X11LIB} -lXft -lfontconfig -lX11
 
 # flags
 CPPFLAGS = -DVERSION=\"${VERSION}\" -D_XOPEN_SOURCE=600
