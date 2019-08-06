--- /dev/null	2019-07-08 14:38:21.999045000 +0100
+++ tensorflow/lite/experimental/micro/tools/make/targets/freebsd_makefile.inc	2019-07-08 14:37:33.196932000 +0100
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
