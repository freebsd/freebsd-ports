--- config.mk.orig	2012-11-28 01:28:06 UTC
+++ config.mk
@@ -90,7 +90,7 @@ HOSTCC		 = $(call os_x_before, 10, 5, "c
 HOSTCFLAGS	+= $(call os_x_before, 10, 4, "-traditional-cpp")
 HOSTLDFLAGS	+= $(call os_x_before, 10, 5, "-multiply_defined suppress")
 else
-HOSTCC		= gcc
+HOSTCC		?= gcc
 endif
 
 ifeq ($(HOSTOS),cygwin)
