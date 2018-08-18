--- sandbox/linux/services/libc_interceptor.cc.orig	2018-07-19 22:19:52.264027000 +0200
+++ sandbox/linux/services/libc_interceptor.cc	2018-07-19 22:20:31.348730000 +0200
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
@@ -94,7 +96,7 @@
   } else {
     base::AutoLock lock(g_timezones_lock.Get());
     auto ret_pair = g_timezones.Get().insert(timezone);
-    output->tm_zone = ret_pair.first->c_str();
+    output->tm_zone = (char *)ret_pair.first->c_str();
   }
 
   return true;
