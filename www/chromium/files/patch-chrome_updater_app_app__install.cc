--- chrome/updater/app/app_install.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/updater/app/app_install.cc
@@ -155,7 +155,7 @@ void AppInstall::WakeCandidate() {
       update_service_internal, base::WrapRefCounted(this)));
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // TODO(crbug.com/1276114) - implement.
 void AppInstall::WakeCandidateDone() {
   NOTIMPLEMENTED();
