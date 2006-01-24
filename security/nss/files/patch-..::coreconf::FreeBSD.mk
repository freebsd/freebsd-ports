--- ../coreconf/FreeBSD.mk	Fri Sep 16 13:09:23 2005
+++ ../coreconf/FreeBSD.mk	Wed Jan 18 18:30:48 2006
@@ -38,7 +38,7 @@
 include $(CORE_DEPTH)/coreconf/UNIX.mk
 
-DEFAULT_COMPILER	= gcc
-CC			= gcc
-CCC			= g++
+DEFAULT_COMPILER	= $(CC)
+CC			?= gcc
+CCC			= $(CXX)
 RANLIB			= ranlib
 
@@ -50,6 +50,12 @@
 
 OS_CFLAGS		= $(DSO_CFLAGS) -ansi -Wall -DFREEBSD -DHAVE_STRERROR -DHAVE_BSD_FLOCK
+OS_LIBS			= $(BSD_LDOPTS)
+OPTIMIZER		=
 
+ifeq ($(OS_TEST),sparc64)
 DSO_CFLAGS		= -fPIC
+else
+DSO_CFLAGS		= -fpic
+endif
 DSO_LDOPTS		= -shared -Wl,-soname -Wl,$(notdir $@)
 
@@ -61,5 +67,5 @@
 DEFINES			+= -D_THREAD_SAFE -D_REENTRANT
 OS_LIBS			+= -pthread
-DSO_LDOPTS		+= -pthread
+DSO_LDOPTS		+= $(BSD_LDOPTS)
 endif
 
@@ -69,10 +75,14 @@
 
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
@@ -84,2 +94,4 @@
 
 INCLUDES		+= -I/usr/X11R6/include
+USE_SYSTEM_ZLIB		= 1
+ZLIB_LIBS		= -lz
