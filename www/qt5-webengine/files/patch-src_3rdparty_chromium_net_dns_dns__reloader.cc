Include all headers required by res_init(3) and friends.

Note that as of base r289315 (present in FreeBSD 11+), the libc resolver
already reloads /etc/resolv.conf when it is changed, so we should also consider
whether to just disable this functionality in Chromium altogether.
--- src/3rdparty/chromium/net/dns/dns_reloader.cc.orig	2016-11-07 14:46:18 UTC
+++ src/3rdparty/chromium/net/dns/dns_reloader.cc
@@ -7,6 +7,9 @@
 #if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_OPENBSD) && \
     !defined(OS_ANDROID)
 
+#include <sys/types.h>
+#include <netinet/in.h>
+#include <arpa/nameser.h>
 #include <resolv.h>
 
 #include "base/lazy_instance.h"
