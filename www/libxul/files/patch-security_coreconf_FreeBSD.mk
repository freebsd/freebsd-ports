--- security/coreconf/FreeBSD.mk.orig	2010-06-26 07:29:06.000000000 +0200
+++ security/coreconf/FreeBSD.mk	2010-07-18 13:25:06.000000000 +0200
@@ -49,9 +49,6 @@
 ifeq ($(CPU_ARCH),pc98)
 CPU_ARCH		= x86
 endif
-ifeq ($(CPU_ARCH),amd64)
-CPU_ARCH		= x86_64
-endif
 
 OS_CFLAGS		= $(DSO_CFLAGS) -ansi -Wall -Wno-switch -DFREEBSD -DHAVE_STRERROR -DHAVE_BSD_FLOCK
 
@@ -87,4 +84,4 @@
 
 G++INCLUDES		= -I/usr/include/g++
 
-INCLUDES		+= -I/usr/X11R6/include
+#INCLUDES		+= -I/usr/X11R6/include
