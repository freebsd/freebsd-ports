
$FreeBSD$

--- ../coreconf/rules.mk.orig	Thu Jun 21 03:56:29 2001
+++ ../coreconf/rules.mk	Wed Dec 19 10:28:51 2001
@@ -106,6 +106,7 @@
 endif
 ifdef SHARED_LIBRARY
 	$(INSTALL) -m 775 $(SHARED_LIBRARY) $(SOURCE_LIB_DIR)
+	ln -sf $(notdir $(SHARED_LIBRARY)) $(SOURCE_LIB_DIR)/$(notdir $(SHARED_LIBRARY:.so.1=.so))
 ifeq ($(OS_ARCH),OpenVMS)
 	$(INSTALL) -m 775 $(SHARED_LIBRARY:$(DLL_SUFFIX)=vms) $(SOURCE_LIB_DIR)
 endif
