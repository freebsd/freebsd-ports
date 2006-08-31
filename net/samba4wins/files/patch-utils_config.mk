--- utils/config.mk.orig	Mon Jul  3 09:48:15 2006
+++ utils/config.mk	Mon Aug 28 02:13:42 2006
@@ -77,7 +77,7 @@
 
 #################################
 # Start BINARY nmblookup
-[BINARY::nmblookup]
+[BINARY::nmblookup4]
 INSTALLDIR = BINDIR
 OBJ_FILES = \
 		nmblookup.o
@@ -92,7 +92,7 @@
 
 #################################
 # Start BINARY testparm
-[BINARY::testparm]
+[BINARY::testparm4]
 INSTALLDIR = BINDIR
 OBJ_FILES = \
 		testparm.o
