--- config.mk.orig	2010-05-30 16:05:25.000000000 -0400
+++ config.mk	2010-07-12 20:08:08.000000000 -0400
@@ -4,25 +4,26 @@
 # Customize below to fit your system
 
 # paths
-PREFIX = /usr/local
-MANPREFIX = ${PREFIX}/share/man
+PREFIX?= /usr/local
+MANPREFIX = ${PREFIX}/man
 
-GTKINC=$(shell pkg-config --cflags gtk+-2.0 webkit-1.0)
-GTKLIB=$(shell pkg-config --libs gtk+-2.0 webkit-1.0)
+GTKINC!= pkg-config --cflags gtk+-2.0 webkit-1.0
+GTKLIB!= pkg-config --libs gtk+-2.0 webkit-1.0
 
 
 # includes and libs
-INCS = -I. -I/usr/include ${GTKINC}
-LIBS = -L/usr/lib -lc ${GTKLIB} -lgthread-2.0
+INCS = ${GTKINC}
+LIBS = ${PTHREAD_LIBS} ${GTKLIB}
 
 # flags
-CPPFLAGS = -DVERSION=\"${VERSION}\"
-CFLAGS = -std=c99 -pedantic -Wall -Os ${INCS} ${CPPFLAGS}
-LDFLAGS = -g ${LIBS}
+CPPFLAGS+= -DVERSION=\"${VERSION}\"
+CFLAGS+= -std=c99 ${INCS} ${CPPFLAGS}
+LDFLAGS+= ${LIBS}
+
 
 # Solaris
 #CFLAGS = -fast ${INCS} -DVERSION=\"${VERSION}\"
 #LDFLAGS = ${LIBS}
 
 # compiler and linker
-CC = cc
+CC?= cc
