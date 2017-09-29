--- makefile_include.mk.orig	2017-08-29 20:27:36 UTC
+++ makefile_include.mk
@@ -17,16 +17,16 @@ ifndef CROSS_COMPILE
   CROSS_COMPILE=
 endif
 
-ifeq ($(CC),cc)
-  CC = $(CROSS_COMPILE)gcc
-endif
+#ifeq ($(CC),cc)
+#  CC = $(CROSS_COMPILE)gcc
+#endif
 LD=$(CROSS_COMPILE)ld
 AR=$(CROSS_COMPILE)ar
 RANLIB=$(CROSS_COMPILE)ranlib
 
-ifndef MAKE
-   MAKE=make
-endif
+#ifndef MAKE
+#   MAKE=make
+#endif
 
 CFLAGS += -I./ -Wall -Wsign-compare -Wextra -Wshadow
 
@@ -65,7 +65,7 @@ CFLAGS += -Wno-nullability-completeness
 endif
 
 # adjust coverage set
-ifneq ($(filter $(shell arch), i386 i686 x86_64 amd64 ia64),)
+ifneq ($(filter $(shell /sbin/sysctl -b hw.machine_arch), i386 i686 x86_64 amd64 ia64),)
    COVERAGE = test_standalone timing
    COVERAGE_APP = ./test && ./ltmtest
 else
