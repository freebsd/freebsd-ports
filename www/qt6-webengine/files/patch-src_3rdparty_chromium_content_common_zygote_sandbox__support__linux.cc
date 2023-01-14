--- src/3rdparty/chromium/content/common/zygote/sandbox_support_linux.cc.orig	2022-11-20 10:46:46 UTC
+++ src/3rdparty/chromium/content/common/zygote/sandbox_support_linux.cc
@@ -8,7 +8,11 @@
 #include "base/posix/global_descriptors.h"
 #include "base/posix/unix_domain_socket.h"
 #include "content/public/common/content_descriptors.h"
+#if defined(OS_BSD)
+#include "sandbox/policy/openbsd/sandbox_openbsd.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 
 namespace content {
 
