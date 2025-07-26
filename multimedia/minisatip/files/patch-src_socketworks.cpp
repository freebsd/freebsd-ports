--- src/socketworks.cpp.orig	2025-07-19 19:28:14 UTC
+++ src/socketworks.cpp
@@ -34,7 +34,9 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sys/ioctl.h>
+#if !defined(__FreeBSD__)
 #include <sys/prctl.h>
+#endif
 #include <sys/socket.h>
 #include <sys/time.h>
 #include <sys/types.h>
@@ -714,7 +716,9 @@ void *select_and_execute(void *arg) {
            sizeof(thread_info[thread_index].thread_name));
     if (arg) {
         safe_strncpy(thread_info[thread_index].thread_name, (char *)arg);
+#ifdef PR_SET_NAME
         prctl(PR_SET_NAME, thread_info[thread_index].thread_name, 0, 0, 0);
+#endif
     } else
         strcpy(thread_info[thread_index].thread_name, "main");
 
