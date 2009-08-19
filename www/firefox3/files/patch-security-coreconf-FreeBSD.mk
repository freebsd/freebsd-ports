--- security/coreconf/FreeBSD.mk.orig	2009-07-30 17:30:28.000000000 +0200
+++ security/coreconf/FreeBSD.mk	2009-08-17 22:29:03.510890513 +0200
@@ -45,8 +45,20 @@
 ifeq ($(OS_TEST),alpha)
 CPU_ARCH		= alpha
 else
+ifeq ($(OS_TEST),amd64)
+CPU_ARCH		= amd64
+else
+ifeq ($(OS_TEST),powerpc)
+CPU_ARCH		= powerpc
+else
+ifeq ($(OS_TEST),sparc64)
+CPU_ARCH		= sparc64
+else
 CPU_ARCH		= x86
 endif
+endif
+endif
+endif
 
 OS_CFLAGS		= $(DSO_CFLAGS) -ansi -Wall -Wno-switch -DFREEBSD -DHAVE_STRERROR -DHAVE_BSD_FLOCK
 
@@ -73,7 +85,7 @@
 DLL_SUFFIX		= so.1.0
 endif
 
-MKSHLIB			= $(CC) $(DSO_LDOPTS)
+MKSHLIB			= $(CC) -Wl,-Bsymbolic -lc $(DSO_LDOPTS) -o $@
 ifdef MAPFILE
 	MKSHLIB += -Wl,--version-script,$(MAPFILE)
 endif
@@ -82,4 +94,4 @@
 
 G++INCLUDES		= -I/usr/include/g++
 
-INCLUDES		+= -I/usr/X11R6/include
+#INCLUDES		+= -I/usr/X11R6/include
