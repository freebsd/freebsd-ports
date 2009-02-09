--- config.mk.orig	2009-02-08 23:35:47.000000000 +0100
+++ config.mk	2009-02-08 23:37:06.000000000 +0100
@@ -3,14 +3,14 @@
 
 # Customize below to fit your system
 
-PREFIX = /usr/local
-MANPREFIX = ${PREFIX}/share/man
+PREFIX ?= /usr/local
+MANPREFIX = ${PREFIX}/man
 
 INCS = -I. -I/usr/include -I/usr/local/include 
 LIBS = -lc -lutil -lncursesw
 #LIBS = -lc -lutil -lncurses
 
-CFLAGS += -std=c99 -Os ${INCS} -DVERSION=\"${VERSION}\" -DNDEBUG
+CFLAGS += -std=c99 ${INCS} -DVERSION=\"${VERSION}\" -DNDEBUG
 LDFLAGS += -L/usr/lib -L/usr/local/lib ${LIBS}
 
 # Mouse handling
@@ -20,4 +20,4 @@
 
 DEBUG_CFLAGS = ${CFLAGS} -UNDEBUG -O0 -g -ggdb -Wall
 
-CC = cc
+CC ?= cc
