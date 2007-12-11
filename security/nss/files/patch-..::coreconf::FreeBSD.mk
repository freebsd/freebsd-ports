--- ../coreconf/FreeBSD.mk.orig	2007-10-31 14:02:28.000000000 -0500
+++ ../coreconf/FreeBSD.mk	2007-10-31 14:05:56.000000000 -0500
@@ -37,9 +37,9 @@
 
 include $(CORE_DEPTH)/coreconf/UNIX.mk
 
-DEFAULT_COMPILER	= gcc
-CC			= gcc
-CCC			= g++
+DEFAULT_COMPILER	= $(CC)
+CC			?= gcc
+CCC			= $(CXX)
 RANLIB			= ranlib
 
 ifeq ($(OS_TEST),alpha)
@@ -49,8 +49,14 @@
 endif
 
 OS_CFLAGS		= $(DSO_CFLAGS) -ansi -Wall -DFREEBSD -DHAVE_STRERROR -DHAVE_BSD_FLOCK
+OS_LIBS			= $(BSD_LDOPTS)
+OPTIMIZER		=
 
+ifeq ($(OS_TEST),sparc64)
 DSO_CFLAGS		= -fPIC
+else
+DSO_CFLAGS		= -fpic
+endif
 DSO_LDOPTS		= -shared -Wl,-soname -Wl,$(notdir $@)
 
 #
@@ -60,20 +66,19 @@
 USE_PTHREADS		= 1
 DEFINES			+= -D_THREAD_SAFE -D_REENTRANT
 OS_LIBS			+= -pthread
-DSO_LDOPTS		+= -pthread
+DSO_LDOPTS		+= $(BSD_LDOPTS)
 endif
 
 ARCH			= freebsd
 
-MOZ_OBJFORMAT		:= $(shell test -x /usr/bin/objformat && /usr/bin/objformat || echo aout)
+DLL_SUFFIX		= so.1
 
-ifeq ($(MOZ_OBJFORMAT),elf)
-DLL_SUFFIX		= so
+ifneq (,$(filter alpha ia64,$(OS_TEST)))
+MKSHLIB			= $(CC) -Wl,-Bsymbolic -lc $(DSO_LDOPTS)
 else
-DLL_SUFFIX		= so.1.0
+MKSHLIB			= $(CC) -Wl,-Bsymbolic $(DSO_LDOPTS)
 endif
 
-MKSHLIB			= $(CC) $(DSO_LDOPTS)
 ifdef MAPFILE
 	MKSHLIB += -Wl,--version-script,$(MAPFILE)
 endif
@@ -82,4 +87,5 @@
 
 G++INCLUDES		= -I/usr/include/g++
 
-INCLUDES		+= -I/usr/X11R6/include
+USE_SYSTEM_ZLIB		= 1
+ZLIB_LIBS		= -lz
