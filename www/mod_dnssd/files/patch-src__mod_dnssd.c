--- src/mod_dnssd.c.orig	2009-01-28 02:24:00 UTC
+++ src/mod_dnssd.c
@@ -24,9 +24,16 @@
 #include <ap_config.h>
 #include <apr_strings.h>
 #include <unixd.h>
+#if MODULE_MAGIC_COOKIE >= 0x41503234UL /* "AP24" */
+#include <mod_unixd.h>
+#endif
 #include <apr_signal.h>
 #include <mpm_common.h>
 
+#if MODULE_MAGIC_NUMBER_MAJOR >= 20090130
+#define unixd_setup_child ap_unixd_setup_child
+#endif
+
 #include <unistd.h>
 
 #include <avahi-common/simple-watch.h>
