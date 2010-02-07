--- security/coreconf/FreeBSD.mk.orig	2009-11-09 01:34:19.000000000 +0100
+++ security/coreconf/FreeBSD.mk	2009-11-11 18:15:55.000000000 +0100
@@ -45,8 +45,24 @@
 ifeq ($(OS_TEST),alpha)
 CPU_ARCH		= alpha
 else
+ifeq ($(OS_TEST),amd64)
+CPU_ARCH		= amd64
+else 
+ifeq ($(OS_TEST),ia64) 
+CPU_ARCH		= ia64
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
+endif
 
 OS_CFLAGS		= $(DSO_CFLAGS) -ansi -Wall -Wno-switch -DFREEBSD -DHAVE_STRERROR -DHAVE_BSD_FLOCK
 
@@ -73,7 +89,7 @@
 DLL_SUFFIX		= so.1.0
 endif
 
-MKSHLIB			= $(CC) $(DSO_LDOPTS)
+MKSHLIB			= $(CC) -Wl,-Bsymbolic -lc $(DSO_LDOPTS) -o $@
 ifdef MAPFILE
 	MKSHLIB += -Wl,--version-script,$(MAPFILE)
 endif
@@ -82,4 +98,4 @@
 
 G++INCLUDES		= -I/usr/include/g++
 
-INCLUDES		+= -I/usr/X11R6/include
+#INCLUDES		+= -I/usr/local/include
