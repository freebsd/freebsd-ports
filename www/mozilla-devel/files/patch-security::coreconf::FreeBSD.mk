
$FreeBSD$

--- security/coreconf/FreeBSD.mk.orig	Sat Mar  9 00:17:36 2002
+++ security/coreconf/FreeBSD.mk	Tue Mar 12 17:19:15 2002
@@ -35,9 +35,7 @@
 
 include $(CORE_DEPTH)/coreconf/UNIX.mk
 
-DEFAULT_COMPILER	= gcc
-CC			= gcc
-CCC			= g++
+CCC			= ${CXX}
 RANLIB			= ranlib
 
 ifeq ($(OS_TEST),alpha)
@@ -70,7 +68,7 @@
 DLL_SUFFIX		= so.1.0
 endif
 
-MKSHLIB			= $(CC) $(DSO_LDOPTS)
+MKSHLIB			= $(CC) $(DSO_LDOPTS) -o $@
 ifdef MAPFILE
 # Add LD options to restrict exported symbols to those in the map file
 endif
