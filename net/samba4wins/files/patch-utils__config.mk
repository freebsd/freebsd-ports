--- ./utils/config.mk.orig	2009-01-14 08:31:07.000000000 +0000
+++ ./utils/config.mk	2009-01-19 02:13:34.000000000 +0000
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
