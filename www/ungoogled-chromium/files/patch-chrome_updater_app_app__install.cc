--- chrome/updater/app/app_install.cc.orig	2023-01-13 08:56:02 UTC
+++ chrome/updater/app/app_install.cc
@@ -214,7 +214,7 @@ void AppInstall::WakeCandidate() {
       update_service_internal, base::WrapRefCounted(this)));
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // TODO(crbug.com/1276114) - implement.
 void AppInstall::WakeCandidateDone() {
   NOTIMPLEMENTED();
