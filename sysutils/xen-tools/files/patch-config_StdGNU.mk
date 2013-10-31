--- config/StdGNU.mk.orig	2013-10-30 14:56:35.070570838 -0500
+++ config/StdGNU.mk	2013-10-30 14:56:42.021581306 -0500
@@ -1,6 +1,6 @@
 AS         = $(CROSS_COMPILE)as
 LD         = $(CROSS_COMPILE)ld
-CC         = $(CROSS_COMPILE)gcc
+CC         ?= $(CROSS_COMPILE)gcc
 CPP        = $(CC) -E
 AR         = $(CROSS_COMPILE)ar
 RANLIB     = $(CROSS_COMPILE)ranlib
