--- ../coreconf/FreeBSD.mk.orig	Wed Mar 26 20:17:25 2003
+++ ../coreconf/FreeBSD.mk	Sat Apr 17 21:25:24 2004
@@ -35,9 +35,9 @@
 
 include $(CORE_DEPTH)/coreconf/UNIX.mk
 
-DEFAULT_COMPILER	= gcc
-CC			= gcc
-CCC			= g++
+DEFAULT_COMPILER	= $(CC)
+CC			?= gcc
+CCC			= $(CXX)
 RANLIB			= ranlib
 
 ifeq ($(OS_TEST),alpha)
@@ -47,6 +47,8 @@
 endif
 
 OS_CFLAGS		= $(DSO_CFLAGS) -ansi -Wall -DFREEBSD -DHAVE_STRERROR -DHAVE_BSD_FLOCK
+OS_LIBS			= $(BSD_LDOPTS)
+OPTIMIZER		=
 
 DSO_CFLAGS		= -fPIC
 DSO_LDOPTS		= -shared -Wl,-soname -Wl,$(notdir $@)
@@ -58,7 +60,7 @@
 USE_PTHREADS		= 1
 DEFINES			+= -D_THREAD_SAFE -D_REENTRANT
 OS_LIBS			+= -pthread
-DSO_LDOPTS		+= -pthread
+DSO_LDOPTS		+= $(BSD_LDOPTS)
 endif
 
 ARCH			= freebsd
@@ -66,12 +68,16 @@
 MOZ_OBJFORMAT		:= $(shell test -x /usr/bin/objformat && /usr/bin/objformat || echo aout)
 
 ifeq ($(MOZ_OBJFORMAT),elf)
-DLL_SUFFIX		= so
+DLL_SUFFIX		= so.1
 else
 DLL_SUFFIX		= so.1.0
 endif
 
-MKSHLIB			= $(CC) $(DSO_LDOPTS)
+ifneq (,$(filter alpha ia64,$(OS_TEST)))
+MKSHLIB			= $(CC) -Wl,-Bsymbolic -lc $(DSO_LDOPTS)
+else
+MKSHLIB			= $(CC) -Wl,-Bsymbolic $(DSO_LDOPTS)
+endif
 ifdef MAPFILE
 # Add LD options to restrict exported symbols to those in the map file
 endif
