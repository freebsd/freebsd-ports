--- bridge/bridge.mk.orig	2012-03-13 06:23:10.000000000 +0100
+++ bridge/bridge.mk	2012-03-14 12:28:03.000000000 +0100
@@ -47,8 +47,10 @@
 APP_LIBXUL_DIRS += $(DEPTH)$(SUBDIR)/db/mork
 #endif
 
+ifdef disabled
 APP_LIBXUL_DIRS += \
   $(DEPTH)$(SUBDIR)/mailnews \
   $(NULL)
+endif
