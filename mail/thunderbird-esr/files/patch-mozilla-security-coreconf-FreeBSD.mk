--- mozilla/security/coreconf/FreeBSD.mk.orig	2010-02-28 23:30:04.000000000 +0000
+++ mozilla/security/coreconf/FreeBSD.mk	2010-03-03 02:05:22.000000000 +0000
@@ -49,8 +49,24 @@
 ifeq ($(CPU_ARCH),pc98)
 CPU_ARCH		= x86
 endif
-ifeq ($(CPU_ARCH),amd64)
-CPU_ARCH		= x86_64
+ifeq ($(OS_TEST),alpha)
+CPU_ARCH		= alpha
+endif
+ifeq ($(OS_TEST),x86_64)
+CPU_ARCH		= x86_64
+endif
+ifeq ($(OS_TEST),ia64) 
+CPU_ARCH		= ia64
+endif
+ifeq ($(OS_TEST),powerpc64)
+CPU_ARCH		= powerpc
+USE_64			= 1
+endif
+ifeq ($(OS_TEST),powerpc)
+CPU_ARCH		= powerpc
+endif
+ifeq ($(OS_TEST),sparc64)
+CPU_ARCH		= sparc64
 endif
 
 OS_CFLAGS		= $(DSO_CFLAGS) -ansi -Wall -Wno-switch -DFREEBSD -DHAVE_STRERROR -DHAVE_BSD_FLOCK
@@ -78,7 +90,7 @@
 DLL_SUFFIX		= so.1.0
 endif
 
-MKSHLIB			= $(CC) $(DSO_LDOPTS)
+MKSHLIB			= $(CC) -Wl,-Bsymbolic -lc $(DSO_LDOPTS) -o $@
 ifdef MAPFILE
 	MKSHLIB += -Wl,--version-script,$(MAPFILE)
 endif
@@ -87,4 +99,6 @@
 
 G++INCLUDES		= -I/usr/include/g++
 
-INCLUDES		+= -I/usr/X11R6/include
+USE_SYSTEM_ZLIB		= 1
+ZLIB_LIBS		= -lz
+INCLUDES		+= -I$(LOCALBASE)/include
