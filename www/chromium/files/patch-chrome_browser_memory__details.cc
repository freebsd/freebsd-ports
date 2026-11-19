--- chrome/browser/memory_details.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/memory_details.cc
@@ -341,7 +341,7 @@ void MemoryDetails::CollectChildInfoOnUIThread() {
           });
     }
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_BSD)
     if (content::ZygoteHost::GetInstance()->IsZygotePid(process.pid)) {
       process.process_type = content::PROCESS_TYPE_ZYGOTE;
     }
