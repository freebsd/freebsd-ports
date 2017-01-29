--- spunk/make/freebsd.mak.orig	1996-11-24 21:33:26 UTC
+++ spunk/make/freebsd.mak
@@ -27,10 +27,10 @@ AS = gas
 AR = ar
 LD = ld
 ZIP = zip
-CC = g++
+CC?= g++
 
 # Flags for the gnu compiler
-CFLAGS	= -DFREEBSD -DUSE_OLD_TTY -g -Wall -x c++ -fno-implicit-templates -DEXPLICIT_TEMPLATES
+CFLAGS	+= -DFREEBSD -g -Wall -x c++ -fno-implicit-templates -DEXPLICIT_TEMPLATES
 
 LIB	= spunk.a
 ZIPFILE = spunk.zip
@@ -137,7 +137,7 @@ RESEDITOBJS	=	resed.o		\
 # Dummy targets
 
 resed:	$(LIB) $(RESEDITOBJS)
-	$(CC) -g -o resed $(RESEDITOBJS) $(LIB) -ltermcap -lg++
+	$(CC) -g -o resed $(RESEDITOBJS) $(LIB) -ltermcap
 
 lib:	$(LIB)
 
@@ -150,7 +150,7 @@ $(LIB):		$(OBJS)
 
 depend dep:
 	@echo "Creating dependency information"
-	$(CC) -DFREEBSD -MM *.cc > .depend
+	$(CC) ${CFLAGS} -MM *.cc > .depend
 
 # ------------------------------------------------------------------------------
 # Target specific files
@@ -196,9 +196,10 @@ zip:
 
 clean:
 	-rm -f *~ linuxsrc/*~ bsdsrc/*~ unixsrc/*~
+	-rm -f *.o
+	-rm -f resed $(LIB) $(ZIPFILE)
 
 zap:	clean
-	-rm -f *.o
 	-rm -f .depend
 
 
