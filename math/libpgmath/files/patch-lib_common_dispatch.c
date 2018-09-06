--- lib/common/dispatch.c.orig	2018-09-04 21:58:51 UTC
+++ lib/common/dispatch.c
@@ -62,11 +62,7 @@
 #include <time.h>
 #include <unistd.h>
 #include <inttypes.h>
-#ifdef TARGET_LINUX_X8664
-#include <malloc.h>
-#else
 #include <sched.h>
-#endif
 #include "mth_tbldefs.h"
 #if defined(TARGET_LINUX_X8664) || defined(TARGET_OSX_X8664)
 #include "cpuid8664.h"
