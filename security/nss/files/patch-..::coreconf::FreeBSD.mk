--- ../../security/coreconf/FreeBSD.mk.orig	2008-07-12 10:28:59.000000000 -0400
+++ ../../security/coreconf/FreeBSD.mk	2009-09-16 22:57:28.000000000 -0400
@@ -37,16 +37,28 @@
 
 include $(CORE_DEPTH)/coreconf/UNIX.mk
 
-DEFAULT_COMPILER	= gcc
-CC			= gcc
-CCC			= g++
+DEFAULT_COMPILER	= $(CC)
+CC			?= gcc
+CCC			= $(CXX)
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
+ifeq ($(OS_TEST),amd64)
+USE_64			= 1
+endif
 CPU_ARCH		= x86
 endif
+endif
+endif
 
 OS_CFLAGS		= $(DSO_CFLAGS) -ansi -Wall -Wno-switch -DFREEBSD -DHAVE_STRERROR -DHAVE_BSD_FLOCK
 
@@ -60,20 +72,18 @@ ifndef CLASSIC_NSPR
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
@@ -82,4 +92,5 @@ PROCESS_MAP_FILE = grep -v ';-' $< | \
 
 G++INCLUDES		= -I/usr/include/g++
 
-INCLUDES		+= -I/usr/X11R6/include
+USE_SYSTEM_ZLIB		= 1
+ZLIB_LIBS		= -lz
