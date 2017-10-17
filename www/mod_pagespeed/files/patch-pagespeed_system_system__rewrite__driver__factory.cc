--- pagespeed/system/system_rewrite_driver_factory.cc.orig	2017-09-14 17:19:19 UTC
+++ pagespeed/system/system_rewrite_driver_factory.cc
@@ -16,7 +16,9 @@
 
 #include "pagespeed/system/system_rewrite_driver_factory.h"
 
+#if !defined(OS_BSD)
 #include <sys/prctl.h>
+#endif
 #include <algorithm>  // for min
 #include <cstdio>
 #include <cstdlib>
@@ -255,9 +257,11 @@ void SystemRewriteDriverFactory::NamePro
   // Set the process status.  This is what /proc/PID/status shows and what
   // "ps -a" gives you.  With PR_SET_NAME there's a max of 16 characters, so
   // abbreviate pagespeed as ps to be terse.
+#if !defined(OS_BSD)
   char name_for_prctl[16];
   snprintf(name_for_prctl, sizeof(name_for_prctl), "ps-%s", name);
   prctl(PR_SET_NAME, name_for_prctl);
+#endif
 
   // It's also possible to change argv[0], but this is a pain so currently we
   // only do this in nginx where they've written ngx_setproctitle to make it
