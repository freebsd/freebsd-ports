--- spunk/make/freebsd-x.mak.orig	Sun Nov 24 22:33:26 1996
+++ spunk/make/freebsd-x.mak	Tue Sep  6 09:54:21 2005
@@ -27,10 +27,10 @@
 AR = ar
 LD = ld
 ZIP = zip
-CC = g++
+CC = $(CXX)
 
 # Flags for the gnu compiler
-CFLAGS	= -DFREEBSD -DUSE_OLD_TTY -g -Wall -x c++ -I /usr/X11R6/include -fno-implicit-templates -DEXPLICIT_TEMPLATES
+CFLAGS	+= -DFREEBSD -g -Wall -x c++ -I $(X11BASE)/include -fno-implicit-templates -DEXPLICIT_TEMPLATES
 
 LIB	= spunk.a
 ZIPFILE = spunk.zip
@@ -135,8 +135,8 @@
 # ------------------------------------------------------------------------------
 # Dummy targets
 
-xresed:		$(LIB) $(RESEDITOBJS)
-	$(CC) -g -o xresed $(RESEDITOBJS) $(LIB) -lg++ -L/usr/X11R6/lib -lX11
+resed:	$(LIB) $(RESEDITOBJS)
+	$(CC) -g -o xresed $(RESEDITOBJS) $(LIB) -L$(X11BASE)/lib -lX11
 
 lib:	$(LIB)
 
@@ -192,10 +192,12 @@
 
 clean:
 	-rm -f *~ linuxsrc/*~ bsdsrc/*~ unixsrc/*~
+	-rm -f *.o
+	-rm -f xresed $(LIB) $(ZIPFILE)
 
 zap:	clean
-	-rm -f *.o
 	-rm -f .depend
+
 
 
 
