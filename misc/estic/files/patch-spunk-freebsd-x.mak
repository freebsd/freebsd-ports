--- spunk/make/freebsd-x.mak.orig	1996-11-24 21:33:26 UTC
+++ spunk/make/freebsd-x.mak
@@ -27,10 +27,10 @@ AS = gas
 AR = ar
 LD = ld
 ZIP = zip
-CC = g++
+CC?= g++
 
 # Flags for the gnu compiler
-CFLAGS	= -DFREEBSD -DUSE_OLD_TTY -g -Wall -x c++ -I /usr/X11R6/include -fno-implicit-templates -DEXPLICIT_TEMPLATES
+CFLAGS	+= -DFREEBSD -g -Wall -x c++ -I $(LOCALBASE)/include -fno-implicit-templates -DEXPLICIT_TEMPLATES
 
 LIB	= spunk.a
 ZIPFILE = spunk.zip
@@ -135,8 +135,8 @@ RESEDITOBJS	=	resed.o		\
 # ------------------------------------------------------------------------------
 # Dummy targets
 
-xresed:		$(LIB) $(RESEDITOBJS)
-	$(CC) -g -o xresed $(RESEDITOBJS) $(LIB) -lg++ -L/usr/X11R6/lib -lX11
+resed:	$(LIB) $(RESEDITOBJS)
+	$(CC) -g -o xresed $(RESEDITOBJS) $(LIB) -L$(LOCALBASE)/lib -lX11
 
 lib:	$(LIB)
 
@@ -149,7 +149,7 @@ $(LIB):		$(OBJS)
 
 depend dep:
 	@echo "Creating dependency information"
-	$(CC) -DFREEBSD -MM *.cc > .depend
+	$(CC) $(CFLAGS) -MM *.cc > .depend
 
 # ------------------------------------------------------------------------------
 # Target specific files
@@ -192,9 +192,10 @@ zip:
 
 clean:
 	-rm -f *~ linuxsrc/*~ bsdsrc/*~ unixsrc/*~
+	-rm -f *.o
+	-rm -f xresed $(LIB) $(ZIPFILE)
 
 zap:	clean
-	-rm -f *.o
 	-rm -f .depend
 
 
