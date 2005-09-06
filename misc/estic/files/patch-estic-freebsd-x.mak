--- estic/make/freebsd-x.mak.orig	Fri Jan 31 03:57:24 1997
+++ estic/make/freebsd-x.mak	Tue Sep  6 09:54:21 2005
@@ -27,12 +27,13 @@
 AR = ar
 LD = ld
 ZIP = zip
-CC = g++
+CXX ?= g++
+CC = ${CXX}
 
 LIB	= ../spunk/spunk.a
 INCDIR	= ../spunk
 
-CFLAGS	= -DFREEBSD -g -Wall -I$(INCDIR) -x c++ -L /usr/X11R6/lib -fno-implicit-templates -DEXPLICIT_TEMPLATES
+CFLAGS	+= -DFREEBSD -g -Wall -I$(INCDIR) -x c++ -L $(X11BASE)/lib -fno-implicit-templates -DEXPLICIT_TEMPLATES
 
 
 # ------------------------------------------------------------------------------
@@ -71,10 +72,10 @@
 		icintcon.o	\
 		iclog.o		\
 		icmsgwin.o	\
-		icprefix.o	\
 		icshort.o	\
 		icver.o		\
-		istecmsg.o
+		istecmsg.o	\
+		../areacode/areacode.o
 
 # ------------------------------------------------------------------------------
 #
@@ -82,7 +83,7 @@
 all:	xestic
 
 xestic: $(LIB) $(OBJS)
-	$(CC) -o xestic $(OBJS) $(LIB) -ltermcap -lg++ -lX11
+	$(CC) -L $(X11BASE)/lib -o xestic $(OBJS) $(LIB) -ltermcap -lX11
 
 
 # ------------------------------------------------------------------------------
@@ -114,10 +115,10 @@
 
 clean:
 	-rm -f *.bak *~
+	-rm -f *.o
+	-rm -f xestic
 
 zap:	clean
-	-rm -f *.o
 	-rm -f .depend
-
 
 
