--- ../../security/coreconf/FreeBSD.mk.orig	2009-08-22 07:33:09.000000000 +0200
+++ ../../security/coreconf/FreeBSD.mk	2010-03-28 23:01:33.000000000 +0200
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
@@ -50,7 +50,26 @@
 CPU_ARCH		= x86
 endif
 ifeq ($(CPU_ARCH),amd64)
-CPU_ARCH		= x86_64
+CPU_ARCH		= amd64
+USE_64			= 1
+endif
+ifeq ($(OS_TEST),alpha)
+CPU_ARCH		= alpha
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
+USE_64			= 1
+endif
+ifeq ($(OS_TEST),ia64)
+CPU_ARCH		= ia64
+USE_64			= 1
 endif
 
 OS_CFLAGS		= $(DSO_CFLAGS) -ansi -Wall -Wno-switch -DFREEBSD -DHAVE_STRERROR -DHAVE_BSD_FLOCK
@@ -65,20 +80,18 @@
 USE_PTHREADS		= 1
 DEFINES			+= -D_THREAD_SAFE -D_REENTRANT
 OS_LIBS			+= -pthread
-DSO_LDOPTS		+= -pthread
+DSO_LDOPTS		+= $(BSD_LDOPTS)
 endif
 
 ARCH			= freebsd
 
-MOZ_OBJFORMAT		:= $(shell test -x /usr/bin/objformat && /usr/bin/objformat || echo elf)
+DLL_SUFFIX		= so.1
 
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
