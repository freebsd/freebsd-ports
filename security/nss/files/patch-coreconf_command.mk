--- coreconf/command.mk	Mon Oct 10 19:46:12 2005
+++ coreconf/command.mk	Wed Jan 18 17:23:28 2006
@@ -46,5 +46,5 @@
 LINK_DLL      = $(LINK) $(OS_DLLFLAGS) $(DLLFLAGS)
 LINK_EXE      = $(LINK) $(OS_LFLAGS) $(LFLAGS)
-CFLAGS        = $(OPTIMIZER) $(OS_CFLAGS) $(XP_DEFINE) $(DEFINES) $(INCLUDES) \
+CFLAGS        += $(OPTIMIZER) $(OS_CFLAGS) $(XP_DEFINE) $(DEFINES) $(INCLUDES) \
 		$(XCFLAGS)
 RANLIB        = echo
