--- Config.mk.orig	2013-10-30 14:55:12.664590030 -0500
+++ Config.mk	2013-10-30 14:55:29.462580127 -0500
@@ -13,9 +13,8 @@
 SHELL     ?= /bin/sh
 
 # Tools to run on system hosting the build
-HOSTCC      = gcc
-HOSTCFLAGS  = -Wall -Werror -Wstrict-prototypes -O2 -fomit-frame-pointer
-HOSTCFLAGS += -fno-strict-aliasing
+HOSTCC      = ${CC}
+HOSTCFLAGS  = ${CFLAGS}
 
 DISTDIR     ?= $(XEN_ROOT)/dist
 DESTDIR     ?= /
