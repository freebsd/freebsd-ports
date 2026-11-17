--- src/remoting/host/setup/me2me_native_messaging_host.cc.orig	2026-10-18 18:43:23 UTC
+++ src/remoting/host/setup/me2me_native_messaging_host.cc
@@ -331,7 +331,7 @@ void Me2MeNativeMessagingHost::ProcessSt
                                                   base::DictValue response) {
   DCHECK(task_runner()->BelongsToCurrentThread());
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // See: b/215406223, crbug.com/514525547
   // TODO: yuweih - consider re-enabling starting host via native messaging once
   // the GDM-managed host becomes the default.
