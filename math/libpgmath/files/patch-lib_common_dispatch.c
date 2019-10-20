--- lib/common/dispatch.c.orig	2019-10-20 14:21:37 UTC
+++ lib/common/dispatch.c
@@ -95,11 +95,7 @@
 
 #endif      // #ifndef _WIN64
 
-#if defined(TARGET_LINUX_X8664) || defined(TARGET_LINUX_POWER) || defined(TARGET_WIN_X8664)
-#include <malloc.h>
-#else
 #include <sched.h>
-#endif
 
 
 #include "mth_tbldefs.h"
