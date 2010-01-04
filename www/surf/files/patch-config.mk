--- config.mk	2009-10-30 13:41:02.000000000 +0100
+++ config.mk	2009-12-21 19:25:11.000000000 +0100
@@ -4,25 +4,25 @@ VERSION = 0.3
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
-LDFLAGS = -s ${LIBS}
+CPPFLAGS+= -DVERSION=\"${VERSION}\"
+CFLAGS+= -std=c99 ${INCS} ${CPPFLAGS}
+LDFLAGS+= ${LIBS}
 
 # Solaris
 #CFLAGS = -fast ${INCS} -DVERSION=\"${VERSION}\"
 #LDFLAGS = ${LIBS}
 
 # compiler and linker
-CC = cc
+CC?= cc
