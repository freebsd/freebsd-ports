--- config.mk.orig	2012-08-01 13:28:25.000000000 +0200
+++ config.mk	2012-11-10 15:50:08.000000000 +0100
@@ -3,8 +3,8 @@
 
 # Customize below to fit your system
 
-PREFIX = /usr/local
-MANPREFIX = ${PREFIX}/share/man
+PREFIX ?= /usr/local
+MANPREFIX = ${PREFIX}/man
 
 INCS = -I. -I/usr/include -I/usr/local/include
 LIBS = -lc -lutil -lncursesw
@@ -15,9 +15,9 @@
 # Cygwin
 #INCS += -I/usr/include/ncurses
 
-CFLAGS += -std=c99 -Os ${INCS} -DVERSION=\"${VERSION}\" -DNDEBUG
+CFLAGS += -std=c99 ${INCS} -DVERSION=\"${VERSION}\" -DNDEBUG
 LDFLAGS += -L/usr/lib -L/usr/local/lib ${LIBS}
 
 DEBUG_CFLAGS = ${CFLAGS} -UNDEBUG -O0 -g -ggdb -Wall
 
-CC = cc
+CC ?= cc
