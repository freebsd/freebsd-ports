--- security/coreconf/FreeBSD.mk.orig	Wed Mar 26 20:17:25 2003
+++ security/coreconf/FreeBSD.mk	Sun Nov 21 22:59:49 2004
@@ -43,8 +43,12 @@
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
 
@@ -71,7 +75,11 @@
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
