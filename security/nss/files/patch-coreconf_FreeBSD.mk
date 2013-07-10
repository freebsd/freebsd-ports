--- coreconf/FreeBSD.mk.orig	2009-08-22 07:33:09.000000000 +0200
+++ coreconf/FreeBSD.mk	2010-03-28 23:01:33.000000000 +0200
@@ -37,9 +37,9 @@
 
 include $(CORE_DEPTH)/coreconf/UNIX.mk
 
-DEFAULT_COMPILER	= gcc
-CC			= gcc
-CCC			= g++
+DEFAULT_COMPILER	= $(CC)
+CC			?= gcc
+CCC			= $(CXX)
 RANLIB			= ranlib
 
 CPU_ARCH		= $(OS_TEST)
@@ -52,6 +52,13 @@ endif
 ifeq ($(CPU_ARCH),amd64)
 CPU_ARCH		= x86_64
 endif
+ifneq (,$(filter powerpc%, $(CPU_ARCH)))
+CPU_ARCH		= ppc
+endif
+
+ifneq (,$(filter %64, $(OS_TEST)))
+USE_64			= 1
+endif
 
 OS_CFLAGS		= $(DSO_CFLAGS) -ansi -Wall -Wno-switch -DFREEBSD -DHAVE_STRERROR -DHAVE_BSD_FLOCK
 
@@ -70,15 +85,15 @@
 
 ARCH			= freebsd
 
-MOZ_OBJFORMAT		:= $(shell test -x /usr/bin/objformat && /usr/bin/objformat || echo elf)
+ifndef MOZILLA_CLIENT
+DLL_SUFFIX		= so.1
+endif
 
-ifeq ($(MOZ_OBJFORMAT),elf)
-DLL_SUFFIX		= so
+ifneq (,$(filter alpha ia64,$(OS_TEST)))
+MKSHLIB			= $(CC) -Wl,-Bsymbolic -lc $(DSO_LDOPTS)
 else
-DLL_SUFFIX		= so.1.0
+MKSHLIB			= $(CC) -Wl,-Bsymbolic $(DSO_LDOPTS)
 endif
-
-MKSHLIB			= $(CC) $(DSO_LDOPTS)
 ifdef MAPFILE
 	MKSHLIB += -Wl,--version-script,$(MAPFILE)
 endif
@@ -87,4 +100,5 @@
 
 G++INCLUDES		= -I/usr/include/g++
 
-INCLUDES		+= -I/usr/X11R6/include
+USE_SYSTEM_ZLIB		= 1
+ZLIB_LIBS		= -lz
