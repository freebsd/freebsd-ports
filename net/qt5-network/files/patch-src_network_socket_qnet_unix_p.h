--- src/network/socket/qnet_unix_p.h.orig	2018-08-27 06:31:41.917561000 +0200
+++ src/network/socket/qnet_unix_p.h	2018-08-27 06:33:20.404588000 +0200
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
