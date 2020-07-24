--- sandbox/linux/services/libc_interceptor.cc.orig	2020-03-16 18:39:54 UTC
+++ sandbox/linux/services/libc_interceptor.cc
@@ -11,7 +11,9 @@
 #include <stddef.h>
 #include <stdint.h>
 #include <string.h>
+#if !defined(OS_BSD)
 #include <sys/prctl.h>
+#endif
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <time.h>
@@ -92,7 +94,7 @@ bool ReadTimeStruct(base::PickleIterator* iter,
   } else {
     base::AutoLock lock(g_timezones_lock.Get());
     auto ret_pair = g_timezones.Get().insert(timezone);
-    output->tm_zone = ret_pair.first->c_str();
+    output->tm_zone = (char *)ret_pair.first->c_str();
   }
 
   return true;
