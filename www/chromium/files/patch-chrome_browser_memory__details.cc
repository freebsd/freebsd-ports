--- chrome/browser/memory_details.cc.orig	2021-12-31 00:57:23 UTC
+++ chrome/browser/memory_details.cc
@@ -37,7 +37,7 @@
 #include "services/resource_coordinator/public/cpp/memory_instrumentation/memory_instrumentation.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if defined(OS_POSIX) && !defined(OS_MAC) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MAC) && !defined(OS_ANDROID) && !defined(OS_BSD)
 #include "content/public/browser/zygote_host/zygote_host_linux.h"
 #endif
 
@@ -325,7 +325,7 @@ void MemoryDetails::CollectChildInfoOnUIThread() {
           std::ref(process)));
     }
 
-#if defined(OS_POSIX) && !defined(OS_MAC) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MAC) && !defined(OS_ANDROID) && !defined(OS_BSD)
     if (content::ZygoteHost::GetInstance()->IsZygotePid(process.pid)) {
       process.process_type = content::PROCESS_TYPE_ZYGOTE;
     }
