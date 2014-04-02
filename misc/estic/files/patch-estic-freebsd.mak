--- estic/make/freebsd.mak.orig	1997-01-31 03:57:24.000000000 +0100
+++ estic/make/freebsd.mak	2014-03-28 17:03:18.000000000 +0100
@@ -27,11 +27,11 @@
 AR = ar
 LD = ld
 ZIP = zip
-CC = g++
+CC?= g++
 
 LIB	= ../spunk/spunk.a
 INCDIR	= ../spunk
-CFLAGS	= -DFREEBSD -g -Wall -I$(INCDIR) -x c++ -fno-implicit-templates -DEXPLICIT_TEMPLATES
+CFLAGS	+= -DFREEBSD -g -Wall -I$(INCDIR) -x c++ -fno-implicit-templates -DEXPLICIT_TEMPLATES
 
 
 # ------------------------------------------------------------------------------
@@ -70,10 +70,10 @@
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
@@ -81,14 +81,14 @@
 all:	estic
 
 estic:	$(LIB) $(OBJS)
-	$(CC) -o estic $(OBJS) $(LIB) -ltermcap -lg++
+	$(CC) -o estic $(OBJS) $(LIB) -ltermcap
 
 # ------------------------------------------------------------------------------
 # Create a dependency file
 
 depend dep:
 	@echo "Creating dependency information"
-	$(CC) -I$(INCDIR) -DFREEBSD -MM *.cc > .depend
+	$(CC) $(CFLAGS) -MM *.cc > .depend
 
 # ------------------------------------------------------------------------------
 # Create a ZIP file
@@ -112,9 +112,10 @@
 
 clean:
 	-rm -f *.bak *~
+	-rm -f *.o
+	-rm -f estic
 
 zap:	clean
-	-rm -f *.o
 	-rm -f .depend
 
 
