--- chrome/common/component_flash_hint_file_linux.h.orig	2015-10-15 10:25:32.927627000 +0200
+++ chrome/common/component_flash_hint_file_linux.h	2015-10-15 10:25:53.911624000 +0200
@@ -7,9 +7,9 @@
 
 #include "build/build_config.h"
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_FREEBSD)
 #error "This file only applies to the Linux component update of Flash."
-#endif  // !defined(OS_LINUX)
+#endif  // !defined(OS_LINUX) && !defined(OS_FREEBSD)
 
 #include <string>
 
