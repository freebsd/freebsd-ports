
$FreeBSD$

--- ../coreconf/FreeBSD.mk.orig	Tue Sep 19 06:53:08 2000
+++ ../coreconf/FreeBSD.mk	Wed Dec 19 10:05:26 2001
@@ -35,19 +35,19 @@
 
 include $(CORE_DEPTH)/coreconf/UNIX.mk
 
-DEFAULT_COMPILER	= gcc
-CC			= gcc
-CCC			= g++
+DEFAULT_COMPILER	= $(CC)
+CCC			= $(CXX)
 RANLIB			= ranlib
 
 ifeq ($(OS_TEST),alpha)
 CPU_ARCH		= alpha
 else
-OS_REL_CFLAGS		= -Di386
 CPU_ARCH		= x86
 endif
 
-OS_CFLAGS		= $(DSO_CFLAGS) $(OS_REL_CFLAGS) -ansi -Wall -pipe $(THREAD_FLAG) -DFREEBSD -DHAVE_STRERROR -DHAVE_BSD_FLOCK
+OS_CFLAGS		= $(DSO_CFLAGS) $(OS_REL_CFLAGS) -ansi -Wall -pipe -DFREEBSD -DHAVE_STRERROR -DHAVE_BSD_FLOCK
+OS_LIBS			= $(BSD_LDOPTS)
+OPTIMIZER		=
 
 #
 # The default implementation strategy for FreeBSD is pthreads.
@@ -55,7 +55,7 @@
 ifndef CLASSIC_NSPR
 USE_PTHREADS		= 1
 DEFINES			+= -D_THREAD_SAFE
-THREAD_FLAG		= -pthread
+DSO_LDFLAGS		= -pthread
 endif
 
 ARCH			= freebsd
@@ -63,16 +63,15 @@
 MOZ_OBJFORMAT		:= $(shell test -x /usr/bin/objformat && /usr/bin/objformat || echo aout)
 
 ifeq ($(MOZ_OBJFORMAT),elf)
-DLL_SUFFIX		= so
+DLL_SUFFIX		= so.1
 else
 DLL_SUFFIX		= so.1.0
 endif
 
 DSO_CFLAGS		= -fPIC
-DSO_LDOPTS		= -Bshareable
-DSO_LDFLAGS		=
+DSO_LDOPTS		= -shared
 
-MKSHLIB			= $(LD) $(DSO_LDOPTS)
+MKSHLIB			= $(CC) $(DSO_LDOPTS) $(BSD_LDOPTS)
 
 G++INCLUDES		= -I/usr/include/g++
 
