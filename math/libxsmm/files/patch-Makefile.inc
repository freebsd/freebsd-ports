--- Makefile.inc.orig	2018-03-15 13:08:45 UTC
+++ Makefile.inc
@@ -53,9 +53,9 @@ MAKE ?= make
 ENV ?= env
 
 ifneq (Darwin,$(UNAME))
-  ifneq (,$(strip $(CP)))
-    CP += -u
-  endif
+  #ifneq (,$(strip $(CP)))
+  #  CP += -u
+  #endif
   DLIBEXT ?= so
   SLIBEXT ?= a
 else
@@ -164,8 +164,8 @@ TBB_OLDRTL ?= 0
 ifneq (Darwin,$(UNAME))
   XGROUP_BEGIN = -Wl,--start-group
   XGROUP_END = -Wl,--end-group
-  XLIB_BEGIN = -Wl,--as-needed
-  XLIB_END = -Wl,--no-as-needed
+  #XLIB_BEGIN = -Wl,--as-needed
+  #XLIB_END = -Wl,--no-as-needed
   XRPATH = -Wl,--rpath=$(NULL)
 else
   XRPATH = -Xlinker -rpath -Xlinker $(NULL)
