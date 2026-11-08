diff --git coreconf/FreeBSD.mk coreconf/FreeBSD.mk
index fcbf23f6a..280d3a140 100644
--- coreconf/FreeBSD.mk
+++ coreconf/FreeBSD.mk
@@ -5,9 +5,9 @@
 
 include $(CORE_DEPTH)/coreconf/UNIX.mk
 
-DEFAULT_COMPILER	= gcc
-CC			= gcc
-CCC			= g++
+DEFAULT_COMPILER	= $(CC)
+CC			?= gcc
+CCC			= $(CXX)
 RANLIB			= ranlib
 
 CPU_ARCH		= $(OS_TEST)
@@ -20,6 +20,16 @@ endif
 ifeq ($(CPU_ARCH),amd64)
 CPU_ARCH		= x86_64
 endif
+ifneq (,$(filter arm%, $(CPU_ARCH)))
+CPU_ARCH		= arm
+endif
+ifneq (,$(filter powerpc%, $(CPU_ARCH)))
+CPU_ARCH		= ppc
+endif
+
+ifneq (,$(findstring 64,$(OS_TEST)))
+USE_64		= 1
+endif
 
 OS_CFLAGS		= $(DSO_CFLAGS) -Wall -Wno-switch -DFREEBSD -DHAVE_STRERROR -DHAVE_BSD_FLOCK
 
@@ -46,7 +56,7 @@ else
 DLL_SUFFIX		= so.1.0
 endif
 
-MKSHLIB			= $(CC) $(DSO_LDOPTS)
+MKSHLIB			= $(CC) -Wl,-Bsymbolic $(DSO_LDOPTS)
 ifdef MAPFILE
 	MKSHLIB += -Wl,--version-script,$(MAPFILE)
 endif
@@ -55,4 +65,5 @@ PROCESS_MAP_FILE = grep -v ';-' $< | \
 
 G++INCLUDES		= -I/usr/include/g++
 
-INCLUDES		+= -I/usr/X11R6/include
+USE_SYSTEM_ZLIB		= 1
+ZLIB_LIBS		= -lz
