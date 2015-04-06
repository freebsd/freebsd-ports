--- config/StdGNU.mk.orig	2013-04-23 18:42:55.000000000 +0200
+++ config/StdGNU.mk	2015-01-30 09:12:53.000000000 +0100
@@ -1,10 +1,10 @@
 AS         = $(CROSS_COMPILE)as
 LD         = $(CROSS_COMPILE)ld
 ifeq ($(clang),y)
-CC         = $(CROSS_COMPILE)clang
+CC         ?= $(CROSS_COMPILE)clang
 LD_LTO     = $(CROSS_COMPILE)llvm-ld
 else
-CC         = $(CROSS_COMPILE)gcc
+CC         ?= $(CROSS_COMPILE)gcc
 LD_LTO     = $(CROSS_COMPILE)ld
 endif
 CPP        = $(CC) -E
