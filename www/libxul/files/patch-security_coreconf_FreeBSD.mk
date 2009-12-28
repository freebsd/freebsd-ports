--- security/coreconf/FreeBSD.mk.orig	2009-11-22 11:51:31.000000000 -0800
+++ security/coreconf/FreeBSD.mk	2009-11-22 11:51:44.000000000 -0800
@@ -37,16 +37,32 @@
 
 include $(CORE_DEPTH)/coreconf/UNIX.mk
 
-DEFAULT_COMPILER	= gcc
-CC			= gcc
-CCC			= g++
+CCC			= ${CXX}
 RANLIB			= ranlib
 
 ifeq ($(OS_TEST),alpha)
 CPU_ARCH		= alpha
 else
+ifeq ($(OS_TEST),powerpc)
+CPU_ARCH		= powerpc
+else
+ifeq ($(OS_TEST),sparc64)
+CPU_ARCH		= sparc64
+USE_64			= 1
+else
+ifeq ($(OS_TEST),ia64)
+CPU_ARCH		= ia64
+USE_64			= 1
+else
+ifeq ($(OS_TEST),amd64)
+CPU_ARCH		= amd64
+else
 CPU_ARCH		= x86
 endif
+endif
+endif
+endif
+endif
 
 OS_CFLAGS		= $(DSO_CFLAGS) -ansi -Wall -DFREEBSD -DHAVE_STRERROR -DHAVE_BSD_FLOCK
 
@@ -73,7 +89,11 @@
 DLL_SUFFIX		= so.1.0
 endif
 
-MKSHLIB			= $(CC) $(DSO_LDOPTS)
+ifneq (,$(filter alpha ia64,$(OS_TEST)))
+MKSHLIB			= $(CC) -Wl,-Bsymbolic -lc $(DSO_LDOPTS) -o $@
+else
+MKSHLIB			= $(CC) -Wl,-Bsymbolic $(DSO_LDOPTS) -o $@
+endif
 ifdef MAPFILE
 	MKSHLIB += -Wl,--version-script,$(MAPFILE)
 endif
@@ -81,5 +101,3 @@
         sed -e 's,;+,,' -e 's; DATA ;;' -e 's,;;,,' -e 's,;.*,;,' > $@
 
 G++INCLUDES		= -I/usr/include/g++
-
-INCLUDES		+= -I/usr/X11R6/include
