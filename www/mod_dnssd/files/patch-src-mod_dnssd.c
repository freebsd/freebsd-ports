--- src/mod_dnssd.c.orig
+++ src/mod_dnssd.c
@@ -27,6 +27,11 @@
 #include <apr_signal.h>
 #include <mpm_common.h>
+#include <mod_unixd.h>
 
+#if MODULE_MAGIC_NUMBER_MAJOR >= 20090130
+#define unixd_setup_child ap_unixd_setup_child
+#endif
+
 #include <unistd.h>
 
 #include <avahi-common/simple-watch.h>
