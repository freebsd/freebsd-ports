--- chrome/browser/extensions/api/enterprise_reporting_private/conversion_utils.cc.orig	2022-08-31 12:19:35 UTC
+++ chrome/browser/extensions/api/enterprise_reporting_private/conversion_utils.cc
@@ -4,7 +4,7 @@
 
 #include "chrome/browser/extensions/api/enterprise_reporting_private/conversion_utils.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 #include <memory>
 #include <utility>
