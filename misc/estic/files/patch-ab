--- estic/make/freebsd.mak.orig	Sat Sep 14 15:40:16 1996
+++ estic/make/freebsd.mak	Fri Mar  9 23:10:46 2001
@@ -27,7 +27,8 @@
 AR = ar
 LD = ld
 ZIP = zip
-CC = g++
+CXX ?= g++
+CC = ${CXX}
 
 LIB	= ../spunk/spunk.a
 INCDIR	= ../spunk
@@ -35,7 +36,8 @@
 # Both configurations of CFLAGS will probably work since FreeBSD has a
 # smart linker...
 #CFLAGS = -DFREEBSD -DUSE_OLD_TTY -g -Wall -I$(INCDIR) -x c++
-CFLAGS	= -DFREEBSD -DUSE_OLD_TTY -g -Wall -I$(INCDIR) -x c++ -fno-implicit-templates -DEXPLICIT_TEMPLATES
+#CFLAGS	= -DFREEBSD -DUSE_OLD_TTY -g -Wall -I$(INCDIR) -x c++ -fno-implicit-templates -DEXPLICIT_TEMPLATES
+CFLAGS	+= -DFREEBSD -g -Wall -I$(INCDIR) -x c++ -fno-implicit-templates -DEXPLICIT_TEMPLATES
 
 
 # ------------------------------------------------------------------------------
