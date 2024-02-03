--- chrome/updater/util/posix_util.cc.orig	2024-02-03 15:42:55 UTC
+++ chrome/updater/util/posix_util.cc
@@ -18,7 +18,7 @@
 #include "chrome/updater/updater_branding.h"
 #include "chrome/updater/util/util.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/updater/util/linux_util.h"
 #endif
 
