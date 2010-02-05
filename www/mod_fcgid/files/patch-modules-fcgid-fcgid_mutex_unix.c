Index: modules/fcgid/fcgid_mutex_unix.c
===================================================================
--- modules/fcgid/fcgid_mutex_unix.c    (revision 904780)
+++ modules/fcgid/fcgid_mutex_unix.c    (working copy)
@@ -56,6 +56,10 @@

 #include "ap_mpm.h"

+#if MODULE_MAGIC_NUMBER_MAJOR < 20051115
+#define AP_NEED_SET_MUTEX_PERMS 1
+#endif
+
 #if AP_NEED_SET_MUTEX_PERMS
 #include "unixd.h"
 #endif


