--- spunk/make/freebsd.mak.orig	Sun Nov 24 22:33:26 1996
+++ spunk/make/freebsd.mak	Tue Sep  6 09:54:21 2005
@@ -27,10 +27,10 @@
 AR = ar
 LD = ld
 ZIP = zip
-CC = g++
+CC = $(CXX)
 
 # Flags for the gnu compiler
-CFLAGS	= -DFREEBSD -DUSE_OLD_TTY -g -Wall -x c++ -fno-implicit-templates -DEXPLICIT_TEMPLATES
+CFLAGS	+= -DFREEBSD -g -Wall -x c++ -fno-implicit-templates -DEXPLICIT_TEMPLATES
 
 LIB	= spunk.a
 ZIPFILE = spunk.zip
@@ -137,7 +137,7 @@
 # Dummy targets
 
 resed:	$(LIB) $(RESEDITOBJS)
-	$(CC) -g -o resed $(RESEDITOBJS) $(LIB) -ltermcap -lg++
+	$(CC) -g -o resed $(RESEDITOBJS) $(LIB) -ltermcap
 
 lib:	$(LIB)
 
@@ -196,9 +196,10 @@
 
 clean:
 	-rm -f *~ linuxsrc/*~ bsdsrc/*~ unixsrc/*~
+	-rm -f *.o
+	-rm -f resed $(LIB) $(ZIPFILE)
 
 zap:	clean
-	-rm -f *.o
 	-rm -f .depend
 
 
