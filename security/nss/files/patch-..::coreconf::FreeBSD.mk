
$FreeBSD$

--- ../coreconf/FreeBSD.mk.orig	Fri Mar  1 18:08:12 2002
+++ ../coreconf/FreeBSD.mk	Thu Aug  8 20:16:30 2002
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
@@ -57,7 +59,7 @@
 ifndef CLASSIC_NSPR
 USE_PTHREADS		= 1
 DEFINES			+= -D_THREAD_SAFE -D_REENTRANT
-DSO_LDOPTS		+= -pthread
+DSO_LDOPTS		+= $(BSD_LDOPTS)
 endif
 
 ARCH			= freebsd
@@ -65,7 +67,7 @@
 MOZ_OBJFORMAT		:= $(shell test -x /usr/bin/objformat && /usr/bin/objformat || echo aout)
 
 ifeq ($(MOZ_OBJFORMAT),elf)
-DLL_SUFFIX		= so
+DLL_SUFFIX		= so.1
 else
 DLL_SUFFIX		= so.1.0
 endif
