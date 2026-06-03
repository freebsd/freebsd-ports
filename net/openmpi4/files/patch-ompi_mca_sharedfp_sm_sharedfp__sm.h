--- ompi/mca/sharedfp/sm/sharedfp_sm.h.orig	2025-02-04 17:12:40 UTC
+++ ompi/mca/sharedfp/sm/sharedfp_sm.h
@@ -29,6 +29,7 @@
 #include "ompi/mca/sharedfp/sharedfp.h"
 #include "ompi/mca/common/ompio/common_ompio.h"
 #include <semaphore.h>
+#include <sys/stat.h>
 
 BEGIN_C_DECLS
 
