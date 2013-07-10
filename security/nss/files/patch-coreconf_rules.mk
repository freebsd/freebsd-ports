--- coreconf/rules.mk.orig	Sat Jan  6 00:48:54 2007
+++ coreconf/rules.mk	Fri Mar 23 10:15:46 2007
@@ -114,6 +114,9 @@
 endif
 ifdef SHARED_LIBRARY
 	$(INSTALL) -m 775 $(SHARED_LIBRARY) $(SOURCE_LIB_DIR)
+ifndef MOZILLA_CLIENT
+	ln -sf $(notdir $(SHARED_LIBRARY)) $(SOURCE_LIB_DIR)/$(notdir $(SHARED_LIBRARY:.so.1=.so))
+endif
 ifdef MOZ_DEBUG_SYMBOLS
 ifeq (,$(filter-out _WIN%,$(NS_USE_GCC)_$(OS_TARGET)))
 	$(INSTALL) -m 644 $(SHARED_LIBRARY:$(DLL_SUFFIX)=pdb) $(SOURCE_LIB_DIR)
