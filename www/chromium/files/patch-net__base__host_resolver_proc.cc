--- net/base/host_resolver_proc.cc.orig	2011-03-15 05:50:10.000000000 +0200
+++ net/base/host_resolver_proc.cc	2011-03-15 05:50:34.000000000 +0200
@@ -6,15 +6,15 @@
 
 #include "build/build_config.h"
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
-#include <resolv.h>
-#endif
-
 #include "base/logging.h"
 #include "net/base/address_list.h"
 #include "net/base/dns_reload_timer.h"
 #include "net/base/net_errors.h"
 #include "net/base/sys_addrinfo.h"
+#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#include <netdb.h> /* EAI_NODATA */
+#include <resolv.h>
+#endif
 
 namespace net {
 
@@ -248,7 +248,11 @@
 #if defined(OS_WIN)
     if (err != WSAHOST_NOT_FOUND && err != WSANO_DATA)
       return ERR_NAME_RESOLUTION_FAILED;
-#elif defined(OS_POSIX)
+#elif defined(OS_FREEBSD)
+	// EAI_NODATA is obsolete [RFC 3493].
+	if (err != EAI_NONAME)
+      return ERR_NAME_RESOLUTION_FAILED;
+#elif defined(OS_POSIX)
     if (err != EAI_NONAME && err != EAI_NODATA)
       return ERR_NAME_RESOLUTION_FAILED;
 #endif
