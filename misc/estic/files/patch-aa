--- estic/make/freebsd-x.mak.orig	Sat Sep 14 15:40:16 1996
+++ estic/make/freebsd-x.mak	Fri Mar  9 23:10:30 2001
@@ -27,7 +27,8 @@
 AR = ar
 LD = ld
 ZIP = zip
-CC = g++
+CXX ?= g++
+CC = ${CXX}
 
 LIB	= ../spunk/spunk.a
 INCDIR	= ../spunk
@@ -35,7 +36,7 @@
 # Both configurations of CFLAGS will probably work since FreeBSD has a
 # smart linker...
 #CFLAGS = -DFREEBSD -DUSE_OLD_TTY -g -Wall -I$(INCDIR) -x c++ -L /usr/X11R6/lib
-CFLAGS	= -DFREEBSD -DUSE_OLD_TTY -g -Wall -I$(INCDIR) -x c++ -L /usr/X11R6/lib -fno-implicit-templates -DEXPLICIT_TEMPLATES
+CFLAGS	+= -DFREEBSD -g -Wall -I$(INCDIR) -x c++ -L $(X11BASE)/lib -fno-implicit-templates -DEXPLICIT_TEMPLATES
 
 
 # ------------------------------------------------------------------------------
@@ -79,7 +80,7 @@
 all:	xestic
 
 xestic: $(LIB) $(OBJS)
-	$(CC) -o xestic $(OBJS) $(LIB) -ltermcap -lg++ -lX11
+	$(CC) -L /usr/X11R6/lib -o xestic $(OBJS) $(LIB) -ltermcap -lX11
 
 
 # ------------------------------------------------------------------------------
