--- security/coreconf/FreeBSD.mk.orig	Tue Sep 19 05:53:08 2000
+++ security/coreconf/FreeBSD.mk	Thu Feb 14 14:19:02 2002
@@ -35,27 +35,27 @@
 
 include $(CORE_DEPTH)/coreconf/UNIX.mk
 
-DEFAULT_COMPILER	= gcc
-CC			= gcc
-CCC			= g++
+CCC			= ${CXX}
 RANLIB			= ranlib
 
 ifeq ($(OS_TEST),alpha)
 CPU_ARCH		= alpha
 else
-OS_REL_CFLAGS		= -Di386
 CPU_ARCH		= x86
 endif
 
-OS_CFLAGS		= $(DSO_CFLAGS) $(OS_REL_CFLAGS) -ansi -Wall -pipe $(THREAD_FLAG) -DFREEBSD -DHAVE_STRERROR -DHAVE_BSD_FLOCK
+OS_CFLAGS		= $(DSO_CFLAGS) $(OS_REL_CFLAGS) -ansi -Wall -DFREEBSD -DHAVE_STRERROR -DHAVE_BSD_FLOCK
+
+DSO_CFLAGS		= -fPIC
+DSO_LDOPTS		= -shared -Wl,-soname -Wl,$(notdir $@)
 
 #
 # The default implementation strategy for FreeBSD is pthreads.
 #
 ifndef CLASSIC_NSPR
 USE_PTHREADS		= 1
-DEFINES			+= -D_THREAD_SAFE
-THREAD_FLAG		= -pthread
+DEFINES			+= -D_THREAD_SAFE -D_REENTRANT
+DSO_LDOPTS	+= -pthread
 endif
 
 ARCH			= freebsd
@@ -68,11 +68,7 @@
 DLL_SUFFIX		= so.1.0
 endif
 
-DSO_CFLAGS		= -fPIC
-DSO_LDOPTS		= -Bshareable
-DSO_LDFLAGS		=
-
-MKSHLIB			= $(LD) $(DSO_LDOPTS)
+MKSHLIB			= $(CC) $(DSO_LDOPTS) -o $@
 
 G++INCLUDES		= -I/usr/include/g++
 
