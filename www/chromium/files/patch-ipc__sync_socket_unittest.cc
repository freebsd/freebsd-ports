--- ipc/sync_socket_unittest.cc.orig	2011-01-06 10:01:35.000000000 +0100
+++ ipc/sync_socket_unittest.cc	2011-01-09 19:49:43.000000000 +0100
@@ -20,9 +20,9 @@
 #include "testing/gtest/include/gtest/gtest.h"
 #include "testing/multiprocess_func_list.h"
 
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_POSIX)
 #include "base/file_descriptor_posix.h"
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX)
+#endif  // defined(OS_POSIX)
 
 enum IPCMessageIds {
   UNUSED_IPC_TYPE,
