--- src/3rdparty/chromium/base/posix/file_descriptor_shuffle.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/base/posix/file_descriptor_shuffle.h
@@ -26,6 +26,8 @@
 #include "base/base_export.h"
 #include "base/compiler_specific.h"
 
+#undef close
+
 namespace base {
 
 // A Delegate which performs the actions required to perform an injective
