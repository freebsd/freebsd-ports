--- vendor/core_unix/linux_ext/src/linux_ext_stubs.c.orig	2026-10-09 07:50:35 UTC
+++ vendor/core_unix/linux_ext/src/linux_ext_stubs.c
@@ -635,10 +635,22 @@ CAMLprim value core_linux_epoll_offsetof_readyflags(va
   return Val_int( offsetof(struct epoll_event, events));
 }
 
+#endif /* JSC_LINUX_EXT */
+
+/* timerfd(2) also exists on FreeBSD >= 14, independently of the other
+   Linux-only extensions, so these bindings live outside JSC_LINUX_EXT. */
 #ifdef JSC_TIMERFD
 
 /** timerfd bindings **/
 
+#include <errno.h>
+#include <stdint.h>
+#include <unistd.h>
+#include <time.h>
+
+#include "ocaml_utils.h"
+#include "unix_utils.h"
+
 #include <sys/timerfd.h>
 
 /* These values are from timerfd.h. They are not defined in Linux
@@ -721,6 +733,8 @@ CAMLprim value core_linux_timerfd_gettime(value v_fd)
 }
 
 #endif /* JSC_TIMERFD */
+
+#ifdef JSC_LINUX_EXT
 
 #ifdef JSC_EVENTFD
 
