
$FreeBSD$

--- ../coreconf/rules.mk.orig	Thu Feb 21 23:23:13 2002
+++ ../coreconf/rules.mk	Thu Aug  8 20:02:24 2002
@@ -106,6 +106,7 @@
 endif
 ifdef SHARED_LIBRARY
 	$(INSTALL) -m 775 $(SHARED_LIBRARY) $(SOURCE_LIB_DIR)
+	ln -sf $(notdir $(SHARED_LIBRARY)) $(SOURCE_LIB_DIR)/$(notdir $(SHARED_LIBRARY:.so.1=.so))
 ifeq ($(OS_TARGET),OpenVMS)
 	$(INSTALL) -m 775 $(SHARED_LIBRARY:$(DLL_SUFFIX)=vms) $(SOURCE_LIB_DIR)
 endif
