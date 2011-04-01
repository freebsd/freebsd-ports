--- chrome/common/multi_process_lock.h.orig	2011-03-20 22:02:04.375736719 +0200
+++ chrome/common/multi_process_lock.h	2011-03-20 22:02:04.485737571 +0200
@@ -18,7 +18,7 @@
   // The length of a multi-process lock name is limited on Linux, so
   // it is limited it on all platforms for consistency. This length does
   // not include a terminator.
-  static const size_t MULTI_PROCESS_LOCK_NAME_MAX_LEN = 106;
+  static const size_t MULTI_PROCESS_LOCK_NAME_MAX_LEN = 102;
 
   // Factory method for creating a multi-process lock.
   // |name| is the name of the lock. The name has special meaning on Windows
