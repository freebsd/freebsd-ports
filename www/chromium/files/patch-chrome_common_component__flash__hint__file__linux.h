--- chrome/common/component_flash_hint_file_linux.h.orig	2016-03-25 13:04:46 UTC
+++ chrome/common/component_flash_hint_file_linux.h
@@ -7,9 +7,9 @@
 
 #include "build/build_config.h"
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_FREEBSD)
 #error "This file only applies to the Linux component update of Flash."
-#endif  // !defined(OS_LINUX)
+#endif  // !defined(OS_LINUX) && !defined(OS_FREEBSD)
 
 #include <string>
 
