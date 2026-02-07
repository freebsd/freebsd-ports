--- src/3rdparty/chromium/components/named_mojo_ipc_server/connection_info.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/components/named_mojo_ipc_server/connection_info.h
@@ -12,7 +12,7 @@
 #include "base/win/scoped_handle.h"
 #elif BUILDFLAG(IS_MAC)
 #include <bsm/libbsm.h>
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <sys/socket.h>
 #endif
 
@@ -29,7 +29,7 @@ struct ConnectionInfo {
   base::ProcessId pid{};
 #if BUILDFLAG(IS_MAC)
   audit_token_t audit_token{};
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ucred credentials{};
 #endif
 };
