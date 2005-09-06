--- estic/make/freebsd.mak.orig	Fri Jan 31 03:57:24 1997
+++ estic/make/freebsd.mak	Tue Sep  6 09:54:21 2005
@@ -27,11 +27,12 @@
 AR = ar
 LD = ld
 ZIP = zip
-CC = g++
+CXX ?= g++
+CC = ${CXX}
 
 LIB	= ../spunk/spunk.a
 INCDIR	= ../spunk
-CFLAGS	= -DFREEBSD -g -Wall -I$(INCDIR) -x c++ -fno-implicit-templates -DEXPLICIT_TEMPLATES
+CFLAGS	+= -DFREEBSD -g -Wall -I$(INCDIR) -x c++ -fno-implicit-templates -DEXPLICIT_TEMPLATES
 
 
 # ------------------------------------------------------------------------------
@@ -70,10 +71,10 @@
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
@@ -81,7 +82,7 @@
 all:	estic
 
 estic:	$(LIB) $(OBJS)
-	$(CC) -o estic $(OBJS) $(LIB) -ltermcap -lg++
+	$(CC) -o estic $(OBJS) $(LIB) -ltermcap
 
 # ------------------------------------------------------------------------------
 # Create a dependency file
@@ -112,9 +113,10 @@
 
 clean:
 	-rm -f *.bak *~
+	-rm -f *.o
+	-rm -f estic
 
 zap:	clean
-	-rm -f *.o
 	-rm -f .depend
 
 
