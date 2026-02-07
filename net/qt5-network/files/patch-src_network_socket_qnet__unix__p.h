Some extra includes for us.

--- src/network/socket/qnet_unix_p.h.orig	2018-12-03 11:15:26 UTC
+++ src/network/socket/qnet_unix_p.h
@@ -71,6 +71,12 @@
 #  include <resolv.h>
 #endif
 
+#if defined(Q_OS_FREEBSD)
+#  include <net/if.h>
+#  include <net/if_types.h>
+#  include <net/if_var.h>
+#endif 
+
 QT_BEGIN_NAMESPACE
 
 // Almost always the same. If not, specify in qplatformdefs.h.
