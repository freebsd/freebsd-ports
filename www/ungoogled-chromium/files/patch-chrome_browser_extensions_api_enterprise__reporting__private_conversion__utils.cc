--- chrome/browser/extensions/api/enterprise_reporting_private/conversion_utils.cc.orig	2022-10-01 07:40:07 UTC
+++ chrome/browser/extensions/api/enterprise_reporting_private/conversion_utils.cc
@@ -6,7 +6,7 @@
 
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 #include <memory>
 #include <utility>
