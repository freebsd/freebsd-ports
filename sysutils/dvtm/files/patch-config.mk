--- config.mk.orig	2014-11-15 15:01:02.000000000 +0100
+++ config.mk	2015-01-08 12:08:14.000000000 +0100
@@ -4,7 +4,7 @@
 # Customize below to fit your system
 
 PREFIX ?= /usr/local
-MANPREFIX = ${PREFIX}/share/man
+MANPREFIX = ${PREFIX}/man
 # specify your systems terminfo directory
 # leave empty to install into your home folder
 TERMINFO := ${DESTDIR}${PREFIX}/share/terminfo
@@ -21,10 +21,10 @@
 # Cygwin
 #INCS = -I/usr/include/ncurses
 
-CFLAGS += -std=c99 -Os ${INCS} -DVERSION=\"${VERSION}\" -DNDEBUG -D_POSIX_C_SOURCE=200809L -D_XOPEN_SOURCE=700
+CFLAGS += -std=c99 ${INCS} -DVERSION=\"${VERSION}\" -DNDEBUG -D_POSIX_C_SOURCE=200809L -D_XOPEN_SOURCE=700 -D__BSD_VISIBLE
 LDFLAGS += ${LIBS}
 
 DEBUG_CFLAGS = ${CFLAGS} -UNDEBUG -O0 -g -ggdb -Wall -Wextra -Wno-unused-parameter
 
-CC = cc
+CC ?= cc
 STRIP = strip
