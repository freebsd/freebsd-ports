
$FreeBSD$

--- ../coreconf/command.mk	2002/08/08 17:20:41	1.1
+++ ../coreconf/command.mk	2002/08/08 17:20:54
@@ -42,7 +42,7 @@
 LINK_DLL      = $(LINK) $(OS_DLLFLAGS) $(DLLFLAGS)
 LINK_EXE      = $(LINK) $(OS_LFLAGS) $(LFLAGS)
 NFSPWD        = $(NSINSTALL_DIR)/nfspwd
-CFLAGS        = $(OPTIMIZER) $(OS_CFLAGS) $(XP_DEFINE) $(DEFINES) $(INCLUDES) \
+CFLAGS        += $(OPTIMIZER) $(OS_CFLAGS) $(XP_DEFINE) $(DEFINES) $(INCLUDES) \
 		$(XCFLAGS)
 RANLIB        = echo
 TAR           = /bin/tar
