--- config.mk.orig	2015-11-19 18:37:08 UTC
+++ config.mk
@@ -7,12 +7,12 @@ VERSION = 0.2
 PREFIX = /usr/local
 MANPREFIX = ${PREFIX}/share/man
 
-X11INC = /usr/X11R6/include
-X11LIB = /usr/X11R6/lib
+X11INC = /usr/local/X11R6/include
+X11LIB = /usr/local/X11R6/lib
 
 # includes and libs
-INCS = -I. -I/usr/include -I/usr/include/freetype2 -I${X11INC}
-LIBS = -L/usr/lib -lc -lm -L${X11LIB} -lXft -lfontconfig -lX11 -lpng
+INCS = -I. -I/usr/local/include -I/usr/local/include/freetype2 -I${X11INC}
+LIBS = -L/usr/local/lib -lc -lm -L${X11LIB} -lXft -lfontconfig -lX11 -lpng
 
 # flags
 CPPFLAGS = -DVERSION=\"${VERSION}\" -D_XOPEN_SOURCE=600
