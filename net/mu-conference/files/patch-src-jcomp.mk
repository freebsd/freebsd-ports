--- src/jcomp.mk.orig	Sun Oct 26 15:35:19 2003
+++ src/jcomp.mk	Mon Feb  9 16:03:18 2004
@@ -25,7 +25,7 @@
 #CFLAGS:=$(CFLAGS) -pipe -Os -I../../jabberd -I../include 
 #LIBS:=$(LIBS) /usr/local/lib/ccmalloc-gcc.o -lccmalloc 
 #LIBS:=$(LIBS) -lmemusage
-LIBS:=$(LIBS) -ljcomp -lm `pkg-config --libs glib-2.0` `pkg-config --libs gthread-2.0`
+LIBS:=-ljcomp -lm `pkg-config --libs glib-2.0` `pkg-config --libs gthread-2.0`
 LDFLAGS:=-L../../lib 
 
 conference_OBJECTS=conference.o conference_room.o conference_user.o utils.o xdata.o admin.o roles.o xdb.o hash.o main.o
