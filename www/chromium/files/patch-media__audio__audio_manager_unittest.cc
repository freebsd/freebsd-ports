--- media/audio/audio_manager_unittest.cc.orig	2013-11-08 07:41:29.000000000 +0100
+++ media/audio/audio_manager_unittest.cc	2013-11-15 15:40:31.000000000 +0100
@@ -9,9 +9,9 @@
 #include "media/audio/audio_manager_base.h"
 #include "testing/gtest/include/gtest/gtest.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "media/audio/linux/audio_manager_linux.h"
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_FREEBSD)
 
 #if defined(OS_WIN)
 #include "base/win/scoped_com_initializer.h"
