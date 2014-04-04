--- estic/make/freebsd-x.mak.orig	1997-01-31 03:57:24.000000000 +0100
+++ estic/make/freebsd-x.mak	2014-03-28 17:00:36.000000000 +0100
@@ -27,12 +27,12 @@
 AR = ar
 LD = ld
 ZIP = zip
-CC = g++
+CC?= g++
 
 LIB	= ../spunk/spunk.a
 INCDIR	= ../spunk
 
-CFLAGS	= -DFREEBSD -g -Wall -I$(INCDIR) -x c++ -L /usr/X11R6/lib -fno-implicit-templates -DEXPLICIT_TEMPLATES
+CFLAGS	+= -DFREEBSD -g -Wall -I$(INCDIR) -x c++ -L $(LOCALBASE)/lib -fno-implicit-templates -DEXPLICIT_TEMPLATES
 
 
 # ------------------------------------------------------------------------------
@@ -71,10 +71,10 @@
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
@@ -82,7 +82,7 @@
 all:	xestic
 
 xestic: $(LIB) $(OBJS)
-	$(CC) -o xestic $(OBJS) $(LIB) -ltermcap -lg++ -lX11
+	$(CC) -L $(LOCALBASE)/lib -o xestic $(OBJS) $(LIB) -ltermcap -lX11
 
 
 # ------------------------------------------------------------------------------
@@ -90,7 +90,7 @@
 
 depend dep:
 	@echo "Creating dependency information"
-	$(CC) -I$(INCDIR) -DFREEBSD -MM *.cc > .depend
+	$(CC) $(CFLAGS) -MM *.cc > .depend
 
 # ------------------------------------------------------------------------------
 # Create a ZIP file
@@ -114,9 +114,10 @@
 
 clean:
 	-rm -f *.bak *~
+	-rm -f *.o
+	-rm -f xestic
 
 zap:	clean
-	-rm -f *.o
 	-rm -f .depend
 
 
