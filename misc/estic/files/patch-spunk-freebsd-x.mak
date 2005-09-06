--- spunk/make/freebsd-x.mak.orig	Fri Jun 21 12:57:24 1996
+++ spunk/make/freebsd-x.mak	Fri Mar  9 23:13:10 2001
@@ -27,11 +27,12 @@
 AR = ar
 LD = ld
 ZIP = zip
-CC = g++
+CXX ?= g++
+CC = ${CXX}
 
 # Flags for the gnu compiler (use the second one for gcc >= 2.6.0)
 #CFLAGS = -DFREEBSD -g -Wall -x c++ -I /usr/X11/include
-CFLAGS	= -DFREEBSD -g -Wall -x c++ -I /usr/X11/include -fno-implicit-templates -DEXPLICIT_TEMPLATES
+CFLAGS	+= -DFREEBSD -g -Wall -x c++ -I ${X11BASE}/include -fno-implicit-templates -DEXPLICIT_TEMPLATES
 
 LIB	= spunk.a
 ZIPFILE = spunk.zip
@@ -206,7 +207,7 @@
 # Dummy targets
 
 xresed:		$(LIB) $(RESEDITOBJS) $(HDRS)
-	$(CC) -g -o xresed $(RESEDITOBJS) $(LIB) -lg++ -L/usr/X11R6/lib -lX11
+	$(CC) -g -o xresed $(RESEDITOBJS) $(LIB) -L/usr/X11R6/lib -lX11
 
 lib:	$(LIB)
 
