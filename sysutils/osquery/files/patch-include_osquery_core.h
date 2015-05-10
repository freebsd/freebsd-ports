--- include/osquery/core.h.orig	2015-05-05 00:16:41 UTC
+++ include/osquery/core.h
@@ -30,7 +30,11 @@
 // clang-format on
 
 #ifndef __constructor__
-#define __constructor__ __attribute__((constructor))
+#define __registry_constructor__ __attribute__((constructor(101)))
+#define __plugin_constructor__ __attribute__((constructor(102)))
+#else
+#define __registry_constructor__ __attribute__((__constructor__(101)))
+#define __plugin_constructor__ __attribute__((__constructor__(102)))
 #endif
 
 /// A configuration error is catastrophic and should exit the watcher.
