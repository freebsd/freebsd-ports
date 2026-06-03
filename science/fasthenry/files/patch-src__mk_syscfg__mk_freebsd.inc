--- src/mk_syscfg/mk_freebsd.inc.orig	2026-04-06 08:54:12 UTC
+++ src/mk_syscfg/mk_freebsd.inc
@@ -0,0 +1,34 @@
+# These CFLAGS should be fine for anything that is reasonably recent
+# except for MinGW.
+
+# Check AVX (parallel math support), for x86_64 only.  We're going to
+# assume the compiler is gcc compatible, you'll need to comment this
+# if a non-compatible compiler is used.  Allow AVX if the gcc version
+# is 4.8 or later.  This should also work for macOS clang on Intel
+# Macs.
+
+ARCH := $(shell uname -m)
+
+ifeq ($(ARCH),amd64)
+    HAVX = 1
+endif
+
+# If you build with AVX enabled, and run on a system that does not
+# have AVX, the program will crash.  If is not likely that you would
+# want to run fasthenry on such a machine as it is probably slow, but
+# to force build without AVX comment the next three lines below. 
+# There seems to be no way to accommodate the presence/absence of AVX
+# at run-time nicely.
+
+ifeq "$(HAVX)" "1"
+    MAVX = -mavx -DWITH_AVX
+endif
+
+CFLAGS += -O3 -DFOUR $(MAVX) 
+
+# For debugging.
+#CFLAGS = -O -g -DFOUR $(MAVX)
+
+# For profiling.
+#CFLAGS = -pg -g  -DFOUR $(MAVX)
+
