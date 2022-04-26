--- ompi/mca/sharedfp/sm/sharedfp_sm.h.orig	2022-04-01 19:57:04.609982000 +0200
+++ ompi/mca/sharedfp/sm/sharedfp_sm.h	2022-04-01 19:57:19.417411000 +0200
@@ -29,6 +29,7 @@
 #include "ompi/mca/sharedfp/sharedfp.h"
 #include "ompi/mca/common/ompio/common_ompio.h"
 #include <semaphore.h>
+#include <sys/stat.h>
 
 BEGIN_C_DECLS
 
