--- /dev/null	2019-07-08 14:12:50.536743000 +0100
+++ tensorflow/lite/tools/make/targets/freebsd_makefile.inc	2019-07-08 14:11:35.495868000 +0100
@@ -0,0 +1,16 @@
+# Settings for FreeBSD.
+ifeq ($(TARGET), freebsd)
+  CXXFLAGS += \
+    -fPIC \
+    -DGEMMLOWP_ALLOW_SLOW_SCALAR_FALLBACK \
+    -pthread
+  CFLAGS += \
+    -fPIC \  
+    -DGEMMLOWP_ALLOW_SLOW_SCALAR_FALLBACK \
+    -pthread
+  # TODO(petewarden): In the future we may want to add architecture-specific
+  # flags like -msse4.2 
+        LIBS += -lexecinfo
+endif
+
+
