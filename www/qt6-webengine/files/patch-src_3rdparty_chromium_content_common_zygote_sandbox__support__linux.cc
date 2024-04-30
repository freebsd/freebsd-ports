--- src/3rdparty/chromium/content/common/zygote/sandbox_support_linux.cc.orig	2023-12-12 22:08:45 UTC
+++ src/3rdparty/chromium/content/common/zygote/sandbox_support_linux.cc
@@ -8,7 +8,11 @@
 #include "base/posix/global_descriptors.h"
 #include "base/posix/unix_domain_socket.h"
 #include "content/public/common/content_descriptors.h"
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 
 namespace content {
 
