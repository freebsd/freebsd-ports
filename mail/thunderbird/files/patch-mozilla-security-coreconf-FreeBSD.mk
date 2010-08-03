--- mozilla/security/coreconf/FreeBSD.mk.orig	2010-04-30 19:44:32.000000000 +0000
+++ mozilla/security/coreconf/FreeBSD.mk	2010-05-10 13:04:45.000000000 +0000
@@ -52,6 +52,15 @@
 ifeq ($(CPU_ARCH),amd64)
 CPU_ARCH		= x86_64
 endif
+ifeq ($(OS_TEST),amd64)
+CPU_ARCH		= amd64
+endif
+ifeq ($(OS_TEST),powerpc)
+CPU_ARCH		= powerpc
+endif
+ifeq ($(OS_TEST),sparc64)
+CPU_ARCH		= sparc64
+endif
 
 OS_CFLAGS		= $(DSO_CFLAGS) -ansi -Wall -Wno-switch -DFREEBSD -DHAVE_STRERROR -DHAVE_BSD_FLOCK
 
@@ -78,7 +87,7 @@
 DLL_SUFFIX		= so.1.0
 endif
 
-MKSHLIB			= $(CC) $(DSO_LDOPTS)
+MKSHLIB			= $(CC) -Wl,-Bsymbolic -lc $(DSO_LDOPTS) -o $@
 ifdef MAPFILE
 	MKSHLIB += -Wl,--version-script,$(MAPFILE)
 endif
@@ -87,4 +96,4 @@
 
 G++INCLUDES		= -I/usr/include/g++
 
-INCLUDES		+= -I/usr/X11R6/include
+#INCLUDES		+= -I/usr/local/include
