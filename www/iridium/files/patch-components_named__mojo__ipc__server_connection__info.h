--- components/named_mojo_ipc_server/connection_info.h.orig	2026-02-16 10:45:29 UTC
+++ components/named_mojo_ipc_server/connection_info.h
@@ -12,7 +12,8 @@
 #include "base/win/scoped_handle.h"
 #elif BUILDFLAG(IS_MAC)
 #include <bsm/libbsm.h>
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
+#include <sys/ucred.h>
 #include <sys/socket.h>
 #endif
 
@@ -29,8 +30,10 @@ struct ConnectionInfo {
   base::ProcessId pid{};
 #if BUILDFLAG(IS_MAC)
   audit_token_t audit_token{};
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_OPENBSD)
   ucred credentials{};
+#elif BUILDFLAG(IS_FREEBSD)
+  xucred credentials{};
 #endif
 };
 
