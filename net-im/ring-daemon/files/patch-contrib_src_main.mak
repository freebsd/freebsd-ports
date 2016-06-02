--- contrib/src/main.mak.orig	2016-05-10 20:45:50 UTC
+++ contrib/src/main.mak
@@ -78,10 +78,10 @@ endif
 #
 ifndef HAVE_CROSS_COMPILE
 ifneq ($(findstring $(origin CC),undefined default),)
-CC := gcc
+CC := cc
 endif
 ifneq ($(findstring $(origin CXX),undefined default),)
-CXX := g++
+CXX := c++
 endif
 ifneq ($(findstring $(origin LD),undefined default),)
 LD := ld
@@ -97,10 +97,10 @@ STRIP := strip
 endif
 else
 ifneq ($(findstring $(origin CC),undefined default),)
-CC := $(CROSS_COMPILE)gcc
+CC := $(CROSS_COMPILE)cc
 endif
 ifneq ($(findstring $(origin CXX),undefined default),)
-CXX := $(CROSS_COMPILE)g++
+CXX := $(CROSS_COMPILE)c++
 endif
 ifneq ($(findstring $(origin LD),undefined default),)
 LD := $(CROSS_COMPILE)ld
@@ -117,8 +117,8 @@ endif
 endif
 
 ifdef HAVE_ANDROID
-CC :=  $(CROSS_COMPILE)gcc --sysroot=$(ANDROID_NDK)/platforms/$(ANDROID_API)/arch-$(PLATFORM_SHORT_ARCH)
-CXX := $(CROSS_COMPILE)g++ --sysroot=$(ANDROID_NDK)/platforms/$(ANDROID_API)/arch-$(PLATFORM_SHORT_ARCH)
+CC :=  $(CROSS_COMPILE)cc --sysroot=$(ANDROID_NDK)/platforms/$(ANDROID_API)/arch-$(PLATFORM_SHORT_ARCH)
+CXX := $(CROSS_COMPILE)c++ --sysroot=$(ANDROID_NDK)/platforms/$(ANDROID_API)/arch-$(PLATFORM_SHORT_ARCH)
 endif
 
 ifdef HAVE_MACOSX
@@ -256,15 +256,15 @@ else
 ZCAT ?= $(error Gunzip client (zcat) not found!)
 endif
 
-ifeq ($(shell sha512sum --version >/dev/null 2>&1 || echo FAIL),)
-SHA512SUM = sha512sum --check
-else ifeq ($(shell shasum --version >/dev/null 2>&1 || echo FAIL),)
-SHA512SUM = shasum -a 512 --check
-else ifeq ($(shell openssl version >/dev/null 2>&1 || echo FAIL),)
-SHA512SUM = openssl dgst -sha512
-else
-SHA512SUM = $(error SHA-512 checksumming not found!)
-endif
+#ifeq ($(shell sha512sum --version >/dev/null 2>&1 || echo FAIL),)
+#SHA512SUM = sha512sum --check
+#else ifeq ($(shell shasum --version >/dev/null 2>&1 || echo FAIL),)
+#SHA512SUM = shasum -a 512 --check
+#else ifeq ($(shell openssl version >/dev/null 2>&1 || echo FAIL),)
+#SHA512SUM = openssl dgst -sha512
+#else
+#SHA512SUM = $(error SHA-512 checksumming not found!)
+#endif
 
 #
 # Common helpers
@@ -320,7 +320,7 @@ checksum = \
 			"$(SRC)/$(patsubst .sum-%,%,$@)/$(2)SUMS" &&) \
 	(cd $(TARBALLS) && $(1) /dev/stdin) < \
 		"$(SRC)/$(patsubst .sum-%,%,$@)/$(2)SUMS"
-CHECK_SHA512 = $(call checksum,$(SHA512SUM),SHA512)
+#CHECK_SHA512 = $(call checksum,$(SHA512SUM),SHA512)
 UNPACK = $(RM) -R $@ \
 	$(foreach f,$(filter %.tar.gz %.tgz,$^), && tar xvzf $(f)) \
 	$(foreach f,$(filter %.tar.bz2,$^), && tar xvjf $(f)) \
@@ -459,12 +459,12 @@ endif
 	echo "set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)" >> $@
 
 # Default pattern rules
-.sum-%: $(SRC)/%/SHA512SUMS
-	$(CHECK_SHA512)
-	touch $@
+#.sum-%: $(SRC)/%/SHA512SUMS
+#	$(CHECK_SHA512)
+#	touch $@
 
-.sum-%:
-	$(error Download and check target not defined for $*)
+#.sum-%:
+#	$(error Download and check target not defined for $*)
 
 # Dummy dependency on found packages
 $(patsubst %,.dep-%,$(PKGS_FOUND)): .dep-%:
