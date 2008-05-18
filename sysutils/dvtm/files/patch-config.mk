--- config.mk.orig	2008-05-18 12:01:46.000000000 +0200
+++ config.mk	2008-05-18 12:05:01.000000000 +0200
@@ -3,14 +3,14 @@
 
 # Customize below to fit your system
 
-PREFIX = /usr/local
-MANPREFIX = ${PREFIX}/share/man
+PREFIX ?= /usr/local
+MANPREFIX = ${PREFIX}/man
 
 INCS = -I. -I/usr/include -I/usr/local/include 
 LIBS = -lc -lutil -lncurses
 LIBS_UTF8 = -lc -lutil -lncursesw
 
-CFLAGS += -std=c99 -Os ${INCS} -DVERSION=\"${VERSION}\" -DNDEBUG
+CFLAGS += -std=c99 ${INCS} -DVERSION=\"${VERSION}\" -DNDEBUG
 LDFLAGS += -L/usr/lib -L/usr/local/lib ${LIBS}
 
 # Mouse handling
@@ -18,4 +18,4 @@
 
 DEBUG_CFLAGS = ${CFLAGS} -UNDEBUG -O0 -g -ggdb -Wall
 
-CC = cc
+CC ?= cc
