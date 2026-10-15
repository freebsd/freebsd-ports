--- remoting/host/setup/me2me_native_messaging_host.cc.orig	2026-07-01 06:24:19 UTC
+++ remoting/host/setup/me2me_native_messaging_host.cc
@@ -331,7 +331,7 @@ void Me2MeNativeMessagingHost::ProcessStartDaemon(base
                                                   base::DictValue response) {
   DCHECK(task_runner()->BelongsToCurrentThread());
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // See: b/215406223, crbug.com/514525547
   // TODO: yuweih - consider re-enabling starting host via native messaging once
   // the GDM-managed host becomes the default.
