--- base/third_party/libevent/event-config.h.orig	2022-03-28 18:11:04 UTC
+++ base/third_party/libevent/event-config.h
@@ -13,6 +13,8 @@
 #include "base/third_party/libevent/linux/event-config.h"
 #elif defined(__FreeBSD__)
 #include "base/third_party/libevent/freebsd/event-config.h"
+#elif defined(__OpenBSD__)
+#include "base/third_party/libevent/openbsd/event-config.h"
 #elif defined(__sun)
 #include "base/third_party/libevent/solaris/event-config.h"
 #elif defined(_AIX)
