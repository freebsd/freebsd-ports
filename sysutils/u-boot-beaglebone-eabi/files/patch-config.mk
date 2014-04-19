--- config.mk.orig	2014-04-18 16:19:53.610552978 -0400
+++ config.mk	2014-04-18 16:22:38.796542173 -0400
@@ -95,7 +95,7 @@
 HOSTCFLAGS	+= $(call os_x_before, 10, 4, "-traditional-cpp")
 HOSTLDFLAGS	+= $(call os_x_before, 10, 5, "-multiply_defined suppress")
 else
-HOSTCC		= gcc
+HOSTCC		= cc
 endif
 
 ifeq ($(HOSTOS),cygwin)
