--- tensorflow/lite/experimental/micro/tools/make/targets/freebsd_makefile.inc.orig	2021-07-05 16:52:18 UTC
+++ tensorflow/lite/experimental/micro/tools/make/targets/freebsd_makefile.inc
@@ -0,0 +1,10 @@
+# Settings for x86 on FreeBSD
+ifeq ($(TARGET), freebsd)
+  ifeq ($(TARGET_ARCH), x86_64)
+    PLATFORM_FLAGS = \
+      -DTF_LITE_DISABLE_X86_NEON
+    CXXFLAGS += $(PLATFORM_FLAGS)
+    CCFLAGS += $(PLATFORM_FLAGS)
+  endif
+endif
+
