--- common.mak.orig	2014-04-08 18:24:04.000000000 +0200
+++ common.mak	2014-04-08 18:24:45.000000000 +0200
@@ -28,8 +28,8 @@
 DEP_LIBS := $(foreach lib,$(FFLIBS),$(call PATH_LIBNAME,$(lib)))
 
 SRC_DIR    := $(SRC_PATH)/lib$(NAME)
-ALLHEADERS := $(subst $(SRC_DIR)/,$(SUBDIR),$(wildcard $(SRC_DIR)/*.h $(SRC_DIR)/$(ARCH)/*.h))
-SKIPHEADERS += $(ARCH_HEADERS:%=$(ARCH)/%) $(SKIPHEADERS-)
+ALLHEADERS := $(subst $(SRC_DIR)/,$(SUBDIR),$(wildcard $(SRC_DIR)/*.h $(SRC_DIR)/$(LIBAV_ARCH)/*.h))
+SKIPHEADERS += $(ARCH_HEADERS:%=$(LIBAV_ARCH)/%) $(SKIPHEADERS-)
 SKIPHEADERS := $(SKIPHEADERS:%=$(SUBDIR)%)
 HOBJS        = $(filter-out $(SKIPHEADERS:.h=.h.o),$(ALLHEADERS:.h=.h.o))
 checkheaders: $(HOBJS)
