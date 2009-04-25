--- security/coreconf/FreeBSD.mk.orig	2008-07-06 00:10:00.000000000 -0500
+++ security/coreconf/FreeBSD.mk	2008-07-06 00:12:34.000000000 -0500
@@ -45,8 +45,12 @@
 ifeq ($(OS_TEST),alpha)
 CPU_ARCH		= alpha
 else
+ifeq ($(OS_TEST),amd64)
+CPU_ARCH		= amd64
+else
 CPU_ARCH		= x86
 endif
+endif
 
 OS_CFLAGS		= $(DSO_CFLAGS) -ansi -Wall -Wno-switch -DFREEBSD -DHAVE_STRERROR -DHAVE_BSD_FLOCK
 
@@ -73,7 +77,7 @@
 DLL_SUFFIX		= so.1.0
 endif
 
-MKSHLIB			= $(CC) $(DSO_LDOPTS)
+MKSHLIB			= $(CC) -Wl,-Bsymbolic -lc $(DSO_LDOPTS) -o $@
 ifdef MAPFILE
 	MKSHLIB += -Wl,--version-script,$(MAPFILE)
 endif
@@ -82,4 +86,4 @@
 
 G++INCLUDES		= -I/usr/include/g++
 
-INCLUDES		+= -I/usr/X11R6/include
+#INCLUDES		+= -I/usr/X11R6/include
