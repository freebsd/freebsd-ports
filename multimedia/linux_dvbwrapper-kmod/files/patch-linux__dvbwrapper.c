--- linux_dvbwrapper.c.orig	2017-02-01 19:40:17 UTC
+++ linux_dvbwrapper.c
@@ -38,10 +38,7 @@ __FBSDID("$FreeBSD$");
 #include <sys/sysproto.h>
 #include <sys/mman.h>
 #include <sys/resourcevar.h>
-
-#if __FreeBSD_version > 900040
-#include <sys/capability.h>
-#endif
+#include <sys/capsicum.h>
 
 #include <vm/vm.h>
 #include <vm/pmap.h>
