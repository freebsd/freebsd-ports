--- security/coreconf/FreeBSD.mk.orig	Wed Mar 26 20:17:25 2003
+++ security/coreconf/FreeBSD.mk	Thu Jul  8 12:56:24 2004
@@ -35,16 +35,18 @@
 
 include $(CORE_DEPTH)/coreconf/UNIX.mk
 
-DEFAULT_COMPILER	= gcc
-CC			= gcc
-CCC			= g++
+CCC			= ${CXX}
 RANLIB			= ranlib
 
 ifeq ($(OS_TEST),alpha)
 CPU_ARCH		= alpha
 else
+ifeq ($(OS_TEST),amd64)
+CPU_ARCH		= amd64
+else
 CPU_ARCH		= x86
 endif
+endif
 
 OS_CFLAGS		= $(DSO_CFLAGS) -ansi -Wall -DFREEBSD -DHAVE_STRERROR -DHAVE_BSD_FLOCK
 
@@ -71,7 +73,11 @@
 DLL_SUFFIX		= so.1.0
 endif
 
-MKSHLIB			= $(CC) $(DSO_LDOPTS)
+ifneq (,$(filter alpha ia64,$(OS_TEST)))
+MKSHLIB			= $(CC) -Wl,-Bsymbolic -lc $(DSO_LDOPTS) -o $@
+else
+MKSHLIB			= $(CC) -Wl,-Bsymbolic $(DSO_LDOPTS) -o $@
+endif
 ifdef MAPFILE
 # Add LD options to restrict exported symbols to those in the map file
 endif
