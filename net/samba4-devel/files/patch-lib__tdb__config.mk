--- ./lib/tdb/config.mk.orig	2009-06-19 04:36:48.000000000 +0000
+++ ./lib/tdb/config.mk	2009-07-12 02:39:36.000000000 +0000
@@ -14,44 +14,44 @@
 
 ################################################
 # Start BINARY tdbtool
-[BINARY::tdbtool]
+[BINARY::tdbtool4]
 INSTALLDIR = BINDIR
 PRIVATE_DEPENDENCIES = \
 		LIBTDB
 # End BINARY tdbtool
 ################################################
 
-tdbtool_OBJ_FILES = $(tdbsrcdir)/tools/tdbtool.o
+tdbtool4_OBJ_FILES = $(tdbsrcdir)/tools/tdbtool.o
 
 ################################################
 # Start BINARY tdbtorture
-[BINARY::tdbtorture]
+[BINARY::tdbtorture4]
 INSTALLDIR = BINDIR
 PRIVATE_DEPENDENCIES = \
 		LIBTDB
 # End BINARY tdbtorture
 ################################################
 
-tdbtorture_OBJ_FILES = $(tdbsrcdir)/tools/tdbtorture.o
+tdbtorture4_OBJ_FILES = $(tdbsrcdir)/tools/tdbtorture.o
 
 ################################################
 # Start BINARY tdbdump
-[BINARY::tdbdump]
+[BINARY::tdbdump4]
 INSTALLDIR = BINDIR
 PRIVATE_DEPENDENCIES = \
 		LIBTDB
 # End BINARY tdbdump
 ################################################
 
-tdbdump_OBJ_FILES = $(tdbsrcdir)/tools/tdbdump.o
+tdbdump4_OBJ_FILES = $(tdbsrcdir)/tools/tdbdump.o
 
 ################################################
 # Start BINARY tdbbackup
-[BINARY::tdbbackup]
+[BINARY::tdbbackup4]
 INSTALLDIR = BINDIR
 PRIVATE_DEPENDENCIES = \
 		LIBTDB
 # End BINARY tdbbackup
 ################################################
 
-tdbbackup_OBJ_FILES = $(tdbsrcdir)/tools/tdbbackup.o
+tdbbackup4_OBJ_FILES = $(tdbsrcdir)/tools/tdbbackup.o
