--- build/arch.mk.orig	2015-08-09 21:14:55 UTC
+++ build/arch.mk
@@ -1,7 +1,7 @@
 ifneq ($(filter %86 x86_64, $(ARCH)),)
 include $(SRC_PATH)build/x86-common.mk
 endif
-ifneq ($(filter-out arm64, $(filter arm%, $(ARCH))),)
+ifneq ($(filter-out armv6 arm64, $(filter arm%, $(ARCH))),)
 ifeq ($(USE_ASM), Yes)
 ASM_ARCH = arm
 ASMFLAGS += -I$(SRC_PATH)codec/common/arm/
